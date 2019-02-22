#include "DitheringWeight.h"

#include <fstream>

#include <opencv2/opencv.hpp>

#include "util.h"

namespace dithering
{
	DitheringWeight::DitheringWeight() {}

	DitheringWeight::DitheringWeight(const std::string& filename)
	{
		LoadWeightEntriesFile(filename);
	}

	DitheringWeight::~DitheringWeight() {}

	void DitheringWeight::LoadWeightEntriesFile(const std::string & filename)
	{
		std::ifstream inputStream(filename.c_str(), std::ios::in);
		while (!inputStream.eof())
		{
			WeightEntry entry;
			char comma;
			inputStream >> entry.width_offset >> comma >> entry.height_offset >> comma >> entry.weight;
			this->weightEntries.push_back(entry);
			divisor += entry.weight;
		}
	}

	cv::Mat DitheringWeight::dither(cv::Mat inputImage)
	{
		for (auto& entry : weightEntries)
		{
			std::cout << "width_offset = " << entry.width_offset
				<< ", height_offset = " << entry.height_offset
				<< ", weight = " << entry.weight << std::endl;
		}
		std::cout << "divisor = " << this->divisor << std::endl;

		cv::Mat outputImage = inputImage.clone();

		const int width = outputImage.cols;
		const int height = outputImage.rows;

		for (int i = 0; i < height; i++) // 375
		{
			for (int j = 0; j < width; j++) // 600
			{
				// uint8_t ranges from 0 to 255
				uint8_t oldpixel = outputImage.at<uint8_t>(i, j);
				uint8_t newpixel = (oldpixel > 127 ? 255 : 0);

				outputImage.at<uint8_t>(i, j) = newpixel;
				int8_t quant_error = oldpixel - newpixel;

				for (auto& entry : weightEntries)
				{
					int heightIndex = i + entry.height_offset;
					int widthIndex = j + entry.width_offset;
					if (heightIndex >= 0 && heightIndex < height && widthIndex >= 0 && widthIndex < width)
					{
						outputImage.at<uint8_t>(heightIndex, widthIndex) =
							saturated_add(outputImage.at<uint8_t>(heightIndex, widthIndex), quant_error * entry.weight / this->divisor);
					}
				}
			}
		}

		return outputImage;
	}
}