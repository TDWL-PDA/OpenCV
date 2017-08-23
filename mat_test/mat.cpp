#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace cv;

int main (int argc, char** argv)
{
	Mat A, C;  //creates just the header parts
	A = imread(argv[1], CV_LOAD_IMAGE_COLOR); //allocates matrix
	Mat B(A);  //Use the copy constructor
	//The copy operators wil only copy the headers and the pointer to the large matrix, not the data itself
	C = A;  //Assignment operator
	//All the objects (A, B, C) point to the same single data matrix. THe headers are different though and modifying any one of them will affect the other ones as well.
	Mat D (A, Rect(10, 10, 870, 556));  //using a rectangle
	Mat E = A (Range::all(), Range(1, 3));  //using row and column boundries
	Mat F = A.clone();
	Mat G;
	A. copyTo(G);
	
	namedWindow("Display Window", WINDOW_AUTOSIZE);
	imshow("Display Window", D);
	waitKey(0);

	return 0;
}
