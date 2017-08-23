#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <vector>

using namespace std;
using namespace cv;

void help()
{
	//cout << "INSERT USER HELP HERE" << endl;
	//Goal: Input an image and then output a list of the colors that the image is comprised of.
}


int main (int argc, char** argv)
{
	if(argv[1] == NULL) //If user doesn't enter in any arguments
	{
		cout << "ERROR: Please try again with an input image" << endl;
		return 0;
	}
	Mat in_image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
	vector<string> img_colors;

//	img_colors.push_back("red");
//	cout << img_colors[0] << endl;
	waitKey(0);
	return 0;
}
