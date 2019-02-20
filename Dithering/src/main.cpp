#include <iostream>
#include <opencv2/opencv.hpp>

#include "FloydSteinberg.h"

int main()
{
	std::cout << "Hello" << std::endl;

	std::string inputImageFile = "Portal_Companion_Cube.jpg";

	// read in image as a grayscale image
	cv::Mat img = cv::imread(inputImageFile);
	if (img.data == NULL)
	{
		std::cout << "opening file failed..." << std::endl;
		return -1;
	}

	cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
	dithering::FloydSteinberg ditherer;
	img = ditherer.dither(img);

	// show the image
	cv::namedWindow("currentImg", cv::WINDOW_AUTOSIZE);
	cv::imshow("currentImg", img);

	// required for imshow
	cv::waitKey(0);
}