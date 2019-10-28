#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include<stdio.h>
using namespace cv;
using namespace std;


const int alpha_slider_max = 100;
int contrastCurseur;
double alpha;
double beta;


Mat src1;
Mat src2;
Mat dst;

int iValueForContrast = 50;
int iValueForLuminosity = 50;

void on_trackbar( int  , void *)
{
 src1.convertTo( src2,-1, iValueForContrast,iValueForLuminosity);

 imshow( "ma fenetre", src2 );
}

int main(){


	 src1=imread("src/test.jpg",1);

	  if( !src1.data )
	    { return -1; }

	  imshow("image initiale", src1 );

	   namedWindow("ma fenetre", 1);
	   createTrackbar("Contrast","ma fenetre",&iValueForContrast,100, on_trackbar,&iValueForLuminosity);
	   createTrackbar("brightness","ma fenetre",&iValueForLuminosity,100,on_trackbar,&iValueForContrast);

	  waitKey(0);




	  return 0;
	}