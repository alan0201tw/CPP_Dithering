#pragma once

#include <vector>

#include <opencv2/opencv.hpp>

namespace dithering
{
	class DitheringWeight
	{
	private:
		struct WeightEntry
		{
			int width_offset;
			int height_offset;
			int weight;
		};

		std::vector<WeightEntry> weightEntries;
		int divisor;

		// this will update weightEntries and divisor.
		void LoadWeightEntriesFile(const std::string& filename);

	public:
		explicit DitheringWeight();
		explicit DitheringWeight(const std::string& filename);

		~DitheringWeight();

		cv::Mat dither(cv::Mat inputImage);
	};
}