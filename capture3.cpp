#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

// See www.asciitable.com
#define ESCAPE_KEY (27)
#define SYSTEM_ERROR (-1)
int main()
{
   VideoCapture cam0(0);
   namedWindow("video_display");
   	char winInput;	
   if (!cam0.isOpened())
   {
       exit(SYSTEM_ERROR);
   }

 
 cam0.set(CAP_PROP_FRAME_WIDTH, 640);
 cam0.set(CAP_PROP_FRAME_HEIGHT, 480);
while (1)
      {
        Mat frame;
	Mat frame_gray;
      	Mat frame_canny; 
	cam0.read(frame);

    	// Copy edges to the images that will display the results in BGR
    	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	medianBlur(frame_gray, frame_gray, 5);    	
	vector<Vec3f> circles;
    	HoughCircles(frame_gray, circles, HOUGH_GRADIENT, 1,
                 frame_gray.rows/16,  // change this value to detect circles with different distances to each other
                 100, 30, 1, 30 // change the last two parameters
            // (min_radius & max_radius) to detect larger circles
    	);
	for( size_t i = 0; i < circles.size(); i++ )
    	{
        	Vec3i c = circles[i];
        	Point center = Point(c[0], c[1]);
        	// circle center
        	circle( frame, center, 1, Scalar(0,100,100), 3, LINE_AA);
        	// circle outline
        	int radius = c[2];
        	circle( frame, center, radius, Scalar(255,0,255), 3, LINE_AA);
    	}
	imshow("detected circles", frame);
    	// Wait and Exit
	if ((winInput = waitKey(10)) == ESCAPE_KEY)
        {
         break;
        }
	
}
};
