#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp" 
#include "opencv2/highgui/highgui.hpp" 
#include "../include/imageoverlay.h"//확장자가 다르다는 것을 알려줘야함 매크로로 정의?를 하면됨

//namespace fs = std::filesystem;

//#include "EdgeDetection.h"
// yuv가 input인가...? 그럼 거기서 y field만 받는 방법은.....

//unsigned char inputimage[IMAGEHEIGHT * IMAGEWIDTH * CHANNEL];
unsigned char bgrimage[IMAGEHEIGHT * IMAGEWIDTH * CHANNEL];
unsigned char yuvimage[IMAGEHEIGHT * IMAGEWIDTH * CHANNEL];
unsigned char inputimage[IMAGEWIDTH * IMAGEHEIGHT * (CHANNEL)];
unsigned char outimage[IMAGEWIDTH * IMAGEHEIGHT * (CHANNEL + 1)];

//home/jisu/cstudy/imageoverlay/image/lena.bmp

int main(void) {

	int ret = 0; 
	// read bmp file in gray scale
	cv::Mat image = cv::imread("/home/jisu/cstudy/imageoverlay/image/lena.bmp");
	
	// Check if the file exists
//	if (!fs::exists("../image/lena.bmp")) 
//	{
//    	std::cerr << "Error: Image file does not exist at specified path." << std::endl;
//    	return 1;
//	}
	// Check if the image is loaded properly
    if (image.empty()) {
        std::cerr << "Error: Unable to open image file." << std::endl;
        return 1;
    }
	//unsigned char* inputimage = image.data;

	//put image.data into uchar buffer without memcpy(buffer, image.data, imagesize);
	printf("%c", image.data[0]);
	
	for (int pixel = 0; pixel < IMAGEHEIGHT * IMAGEWIDTH * CHANNEL; pixel++)
	{
		//FIXME:segmentation fault
		inputimage[pixel] = image.data[pixel];
			
	
	}
#if 0
	for (int row = 0; row < IMAGEHEIGHT; row++)
	{
		for (int col = 0; col < IMAGEWIDTH; col++)
		{
			inputimage[row * IMAGEWIDTH + col] = image.data[row * IMAGEWIDTH + col];
			//inputimage[row * IMAGEWIDTH + col] = img_data[row * IMAGEWIDTH + col];
			//printf("\t %d", inputimage);
		}
		//cout << "\n" << endl;
	}
	
#endif

	if (inputimage == NULL) return -1;

	//unsigned char* outimage = EdgeDetect(buffer);
#if 0
	//EdgeDetect(buffer, outimage);
    rgb2bgr(inputimage, bgrimage);
    rgb2yuv(inputimage, yuvimage);
	imageoverlay(bgrimage, yuvimage, outimage);

#endif

#if 0
	 
	for (int row = 0; row < IMAGEHEIGHT; row++)
	{
		for (int col = 0; col < IMAGEWIDTH; col++)
		{
			unsigned char inputimage = img_data[row * IMAGEWIDTH + col];
			//inputimage[row * IMAGEWIDTH + col] = img_data[row * IMAGEWIDTH + col];
			printf("\t %d", inputimage);
		}
		cout << "\n" << endl;
	}


	//Check the buffer
	cout << typeid(buffer).name() << "\n"; //unsigned char * __ptr64
	cout << sizeof(buffer) << "\n";   //8
	for (int row = 0; row < IMAGEHEIGHT; row++)
	{
		for (int col = 0; col < IMAGEWIDTH; col++)
		{
			
			printf("\t %c", buffer);
		}
		cout << "\n" << endl;
	}
	
	//pixel값을 unsigned char에 담아서? argument로 주기...
	int cnt = 1;
	uchar* pt = image.data;
	unsigned char imagepixel[600*754] = {0};

	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			imagepixel[width * y + x] = *pt++;

		}
	}

#endif
#if 1
    //buffer to MAT 3channel bgrimage
	cv::Mat outbuffer(IMAGEHEIGHT, IMAGEWIDTH, CV_8UC3);
	for (int pixel = 0; pixel < IMAGEHEIGHT * IMAGEWIDTH * (CHANNEL) ; pixel+=3)
	{
		
		outbuffer.data[pixel] = bgrimage[pixel];
        outbuffer.data[pixel + 1] = bgrimage[pixel + 1];
        outbuffer.data[pixel + 2] = bgrimage[pixel + 2];
 	
	}

#endif

#if 0	
    //buffer to MAT 3channel yuvimage
	cv::MatMat outbuffer(IMAGEHEIGHT, IMAGEWIDTH, CV_8UC3);
	for (int pixel = 0; pixel < IMAGEHEIGHT * IMAGEWIDTH * (CHANNEL) ; pixel+=3)
	{
		
		outbuffer.data[pixel] = yuvimage[pixel];
        outbuffer.data[pixel + 1] = yuvimage[pixel + 1];
        outbuffer.data[pixel + 2] = yuvimage[pixel + 2];
 	
	}

#endif

#if 0
//buffer to MAT 4channel image
	cv::Mat outbuffer(IMAGEHEIGHT, IMAGEWIDTH, CV_8UC4);
	for (int pixel = 0; pixel < IMAGEHEIGHT * IMAGEWIDTH * (CHANNEL + 1) ; pixel+=4)
	{
		
		outbuffer.data[pixel] = outimage[pixel];
        outbuffer.data[pixel + 1] = outimage[pixel + 1];
        outbuffer.data[pixel + 2] = outimage[pixel + 2];
        outbuffer.data[pixel + 3] = outimage[pixel + 3];
			
		
		
	}
#endif
	cv::imshow("outimage", image);
	cv::waitKey(0);


	
	return 0;

}
