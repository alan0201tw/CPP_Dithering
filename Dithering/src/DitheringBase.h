#pragma once

#include <opencv2/opencv.hpp>

namespace dithering
{
	class DitheringBase
	{
	public:
		DitheringBase() {};
		~DitheringBase() {};

		virtual cv::Mat dither(cv::Mat inputImage) = 0;
	};
}