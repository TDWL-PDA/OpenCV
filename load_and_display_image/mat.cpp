#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	String imageName("/home/patrick/Documents/christine/OpenCV_test/mat_test/pepe_le_pew.jpg");  //default
	if (argc > 1)  //If user passes an image URL this if statement will use the new image URL to display
	{
		imageName = argv[1];
	}
	
	Mat image;  //Creates the Mat object that will store the data of the loaded image
	//image = imread(imageName, IMREAD_COLOR); //Read the file
	image = imread(imageName, CV_LOAD_IMAGE_GRAYSCALE);
	//imread fxn: the first argument is the image name, and the second arguments specifies the format we want the image in
    //Second Argument can be (if not specificed defaults to CV_LOAD_IMAGE_COLOR):
			//CV_LOAD_IMAGE_UNCHAGED (<0): loads the image as is (including alpha channel if present)
			//CV_LOAD_IMAGE_GRAYSCALE (0): loads image as an intensity one (in grayscale)
			//CV_LOAD_IMAGE_COLOR (>0): loads image in the BGR format

	if (image.empty())  //Checking for valid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	cout << image << endl;
	namedWindow("Display window", WINDOW_AUTOSIZE); //Create a window for display
	//WINDOW_AUTOSIZE: only one supported without the use of Qt backend. Window will take up size of image it shows, no resize permitted.
	//WINDOW_NORMAL: on Qt can use to allow window resize. Image will resize itself according to current window size. By using | operator can also specify if you want image to keep aspect ratio (WINDOW_KEEPRATIO) or not (WINDOW_FREERATIO)
	//If second argument not specified, deafults to WINDOW_AUTOSIZE)
	imshow("Display window", image);  //Show image inside window

	waitKey(0); //wait for a keystroke in the window
	//waitKey is how long should window wait for a user input (measured in milliseconds). 0 means to wait forever.
	return 0;
}

