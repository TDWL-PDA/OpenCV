#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat image;
	image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
	namedWindow(argv[1], CV_WINDOW_AUTOSIZE);
	imshow(argv[1], image);
	
	waitKey(0);
	return 0;
}
