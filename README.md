# Computer-vision-Opencv-Hough-circles

In the code, we first read the frame from the webcam and then applied cvtColor on it. 
The frame after applying cvtColor was given to the medianBlur method to blur the 
unnecessary objects from the image. Then we created a vector to store the frame in BGR 
format and then applied the Hough circles technique and got the circles in the image by 
iterating through the for loop in the vector of frames. By using these methods one after 
the other, we got the desired output by ‘imshow’ method.

This technique of Hough Lines Circles is used to detect the circles in the image. 
If there are no circles in the image, there will be no detection.
