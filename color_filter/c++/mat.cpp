#include <iostream>
#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <typeinfo>

using namespace std;
using namespace cv;

void help()
{
	cout << "The purpose of this program is to detect a specific color withing an image. To detect the color Red type either 'red' or 'Red'. To detect the color black typoe either 'black' or 'Black'."<< endl;
	cout << "This fxn takes 2 argument. That being an image and then the color to be filtered out." << endl;
	cout << "First use 'cmake .', then 'make', then call the fxn using the format below" << endl;
	cout << "To call this fxn use the format: " << endl;
	cout << "./mat image_name.png color" << endl << endl << endl;
}

int main(int argc, char** argv)
{
	help(); //will display instructions for the user on this fxn
	
	Mat original_img;  //original image inputted by user
	Mat new_img;  //will hold image of just color detected
	//Reading the image (load the games image)
	original_img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
	
	//Define Boundries for the color that we want to isolate.

	if (argv[2] == NULL) //if user does not enter a second arguement
	{
		new_img = original_img;
	}
	else if (string(argv[2]) == "black" || string(argv[2]) == "Black")
	{
		inRange(original_img, Scalar(0,0,0), Scalar(20,20,20), new_img);
	}
	else if (string(argv[2]) == "red" || string(argv[2]) == "Red")
	{
		inRange(original_img, Scalar(0,0,100), Scalar(65, 65, 255), new_img);
	}
	else //if user inputs something other than red or black
	{
		new_img = original_img;
	}
	
	//Window for the original image
	namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
	imshow("Original Image", original_img);

	//Window for the image with only the detected color
	namedWindow("Color Detection", CV_WINDOW_AUTOSIZE);
	imshow("Color Detection", new_img);


	waitKey(0);
	return 0;
}
