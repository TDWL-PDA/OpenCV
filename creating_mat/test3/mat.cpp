#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

void help()
{
	cout << "The purpose of this fxn is to change an image of a black square to an image of a blue square."<< endl;
	cout << "This fxn takes 1 argument. That argument being an image." << endl;
	cout << "First use 'cmake .', then 'make', then call the fxn using the format below" << endl;
	cout << "To call this fxn use the format: " << endl;
	cout << "./mat image_name.png" << endl << endl << endl;
}

int main(int argc, char** argv)
{
	help(); //will display instructions for the user on this fxn
	Mat original_img;
/*	float matrix[8][8];
	for (int i=0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			matrix[i][j] = 0;
			cout << matrix[i][j] << endl;
		}
	}*/
	//Reading the image
	original_img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
	Mat new_img;
	new_img = original_img+255; 
	//(0,0,0) is for black, (255, 0, 0) is for blue
	
	
	//Mat new_img;  //Mat image for new manipulated image
	//new_img = original_img/3;  //Actually manipulating the image
	
	//Window for the original image
	namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
	imshow("Original Image", new_img);
	//Window for the new image
	//namedWindow("New Image", CV_WINDOW_AUTOSIZE);
	//imshow("New Image", new_img);

	//This will output the color matrix of the new image
	cout << new_img <<endl;

	waitKey(0);
	return 0;
}
