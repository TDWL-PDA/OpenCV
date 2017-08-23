#include <iostream>
#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

void help()
{
	cout << "The purpose of this program is to detect a specific color withing an image."<< endl;
	cout << "This fxn takes 1 argument. That argument being an image." << endl;
	cout << "First use 'cmake .', then 'make', then call the fxn using the format below" << endl;
	cout << "To call this fxn use the format: " << endl;
	cout << "./mat image_name.png" << endl << endl << endl;
}

int main(int argc, char** argv)
{
	help(); //will display instructions for the user on this fxn
	Mat original_img;  //original image inputted by user
	Mat new_img;  //will hold image of just color detected
	//Reading the image
	original_img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
	
	//Define Boundries for the color that we want to isolate (red in this case). Boundries will be a list of tuples
	//My boundires will be a vector within a vector within a vector
//	vector<int> upper (5,4);
//	for (int i=0;i<5;i++)
//	{
//		cout <<upper[i] << "  ";
//	}
//	cout << endl;
//	vector <int> lower;
	//list<int> boundries = {
	//	
	//	};
	/*use inRange fxn to perform the actual color detection
	loop through the upper and lower boundries*/
	//return the image in binary (show only the color detected)
	
	//Window for the original image
//	namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
//	imshow("Original Image", original_img);

	//Window for the image with only the detected color
	//namedWindow("Color Detection", CV_WINDOW_AUTOSIZE);
	//imshow("Color Detection", new_img);


	waitKey(0);
	return 0;
}
