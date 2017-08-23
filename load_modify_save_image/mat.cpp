#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace cv;

int main (int argc, char** argv)
{
	String imageName = argv[1];
	Mat image;
	image = imread(imageName, CV_LOAD_IMAGE_COLOR);
	if (argc != 2 || !image.data)
	{
		std::cout << "No image data \n" << std::endl;
		return -1;
	}
	Mat gray_image;
	cvtColor(image, gray_image, CV_BGR2GRAY); //convert image from BGR to Grayscale format
	//Arguments:
			//Source image (image)
			//Destination image (grey_image) saves the converted image
			//CV_BGR2GRAY indicates the type of transformation

	imwrite("Gray_image.jpg", gray_image);  //save our new gray_image to disk (otherwise it will get lost after program ends)

	namedWindow(imageName, CV_WINDOW_AUTOSIZE);
	namedWindow("Gray image", CV_WINDOW_AUTOSIZE);

	imshow(imageName, image);
	imshow("Gray image", gray_image);

	waitKey(0);

	return 0;
}
