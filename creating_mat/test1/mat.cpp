#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src1;
	src1 = imread(argv[1], CV_LOAD_IMAGE_COLOR);
	namedWindow("Original image", CV_WINDOW_AUTOSIZE);
	imshow("Original image", src1);

	Mat gray;
	cvtColor(src1, gray, CV_BGR2GRAY);
	namedWindow("Result Window", CV_WINDOW_AUTOSIZE);
	imshow("Result Window", gray);
	
	//Use the copy constructor
	Mat src2(src1);
	namedWindow("window2", CV_WINDOW_AUTOSIZE);
	imshow("window2", src2);

	//Assignment Operator
	Mat src3;
	src3 = src2;
	namedWindow("window3", CV_WINDOW_AUTOSIZE);
	imshow("window3", src3);

	//Selecting a region of interest using a rectange
	Mat src4 (src1, Rect(50, 50, 150, 150));
	namedWindow("window4", CV_WINDOW_AUTOSIZE);
	imshow("window4", src4);
	// Another way of doing same
	Rect r(10, 10, 100, 100);
	Mat src41 = src1(r);
	namedWindow( "4.1", CV_WINDOW_AUTOSIZE ); 
	imshow( "4.1", src41 ); 
    // clone() function
    Mat src5 = src1.clone();
    namedWindow( "window5", CV_WINDOW_AUTOSIZE ); 
    imshow( "window5", src5 ); 
    // copyTo() function
    Mat src6;
    src1.copyTo(src6);
    namedWindow( "window6", CV_WINDOW_AUTOSIZE ); 
    imshow( "window6", src6 ); 

	// Using Range()
	Mat P;
	src6.rowRange(1,2).copyTo(P);
	//cout << "P = " << endl << " " << P(Range::all(),Range::all()) << endl << endl ;
    // Range::all() - “the whole sequence”
    // Range(a,b) - "[start , end]
    // Copy {row : 0 to 4} and {col : 5 to 9} to matrix Q
	Mat Q; Q = gray(Range(0,5),Range(5,10));
	cout<< Q << endl << endl;

	//make a black image from an existing image
	src1 = Scalar(0);
	namedWindow( "window7", CV_WINDOW_AUTOSIZE ); 
	imshow( "window7", src1 ); 
    // Create a header for an already existing IplImage pointer
    IplImage* img = cvLoadImage(argv[1], 1);
	Mat mtx(img); // convert IplImage* -> Mat
	namedWindow( "window8", CV_WINDOW_AUTOSIZE ); 
	imshow( "window8", mtx );
    // Mat() Constructor
    Mat M(2,2, CV_8UC3, Scalar(0,0,255));
    cout << "M = " << endl << " " << M << endl << endl;
    // Use C\C++ arrays and initialize via constructor
    // Create a matrix with more than two dimensions
    int sz[3] = {4,2,3};
    Mat L(3,sz, CV_8UC(1), Scalar::all(0));

	// Create() function
	Mat N;
	N.create(4,4, CV_8UC(2));
	cout << "N = "<< endl << " " << N << endl << endl;

	// initializer: zeros(), ones(), :eyes(). Specify size and data type to use
	Mat E = Mat::eye(4, 4, CV_64F);
	cout << "E = " << endl << " " << E << endl << endl;
    Mat O = Mat::ones(2, 2, CV_32F);
    cout << "O = " << endl << " " << O << endl << endl;

    Mat Z = Mat::zeros(3,3, CV_8UC1);
    cout << "Z = " << endl << " " << Z << endl << endl;

	// For small matrices you may use comma separated initializers:
	Mat C = (Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	cout << "C = " << endl << " " << C << endl << endl;

	Mat RowClone = C.row(1).clone();
	cout << "RowClone = " << endl << " " << RowClone << endl << endl;

	// Fill out a matrix with random values using the randu() function. 
	// You need to give the lower and upper value for the random values:
	Mat R = Mat(3, 2, CV_8UC3);
	randu(R, Scalar::all(0), Scalar::all(255));
	cout << "R = " << endl << " " << R << endl << endl; 

	// allocates a 30x40 floating-point matrix
	Mat A(30, 40, DataType<float>::type);

	Mat B = Mat_<std::complex<double> >(3, 3);
	// the statement below will print 6, 2 /*, that is depth == CV_64F, channels == 2 */
	cout << B.depth() << ", " << B.channels() << endl;
																														    
	waitKey(0);

	return 0;
}
