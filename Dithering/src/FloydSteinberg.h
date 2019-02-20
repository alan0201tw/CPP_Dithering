#pragma once

#include "DitheringBase.h"
#include "util.h"

namespace dithering
{
	class FloydSteinberg : public DitheringBase
	{
	public:
		FloydSteinberg() {};
		~FloydSteinberg() {};

		virtual cv::Mat dither(cv::Mat inputImage) override
		{
			cv::Mat outputImage = inputImage.clone();

			const int width = outputImage.cols;
			const int height = outputImage.rows;

			//std::cout << "width = " << width << ", height = " << height << std::endl;
			// when using Point as position
			// top left corner is Point(0, 0)
			// top right corner is Point(width-1, 0)

			for (int i = 0; i < height; i++) // 375
			{
				for (int j = 0; j < width; j++) // 600
				{
					// uint8_t ranges from 0 to 255
					uint8_t oldpixel = outputImage.at<uint8_t>(i, j);
					uint8_t newpixel = (oldpixel > 127 ? 255 : 0);
					//std::cout << "oldpixel = " << (int)oldpixel << ", newpixel = " << (int)newpixel << std::endl;
					outputImage.at<uint8_t>(i, j) = newpixel;
					int8_t quant_error = oldpixel - newpixel;

					if (j + 1 < width && j > 0 && i + 1 < height)
					{
						outputImage.at<uint8_t>(i, j + 1) = saturated_add(outputImage.at<uint8_t>(i, j + 1), quant_error * 7 / 16);
						outputImage.at<uint8_t>(i + 1, j + 1) = saturated_add(outputImage.at<uint8_t>(i + 1, j + 1), quant_error * 3 / 16);
						outputImage.at<uint8_t>(i + 1, j) = saturated_add(outputImage.at<uint8_t>(i + 1, j), quant_error * 5 / 16);
						outputImage.at<uint8_t>(i + 1, j - 1) = saturated_add(outputImage.at<uint8_t>(i + 1, j - 1), quant_error * 1 / 16);
					}
				}
			}

			return outputImage;
		}
	};
}