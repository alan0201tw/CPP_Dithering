#pragma once

#include <opencv2/opencv.hpp>

namespace dithering
{
	/**
	 *  Deprecated : using file assignmented weights instead.
	 *	Might be continue developed after the file input feature is done.
	 *
	 *	A base class for varies different dithering algorithms.
	 */
	class DitheringBase
	{
	public:
		DitheringBase() {};
		~DitheringBase() {};

		virtual cv::Mat dither(cv::Mat inputImage) = 0;
	};
}