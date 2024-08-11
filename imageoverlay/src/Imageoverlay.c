#include "../include/imageoverlay.h"




void normalize(unsigned char *, float *) ;




void rgb2bgr(unsigned char* inimage, unsigned char* outimage)
{
    for(int pixel = 0; pixel < IMAGEHEIGHT * IMAGEWIDTH * CHANNEL; pixel += 3)
    {
        outimage[pixel    ] = inimage[pixel + 2];
        outimage[pixel + 1] = inimage[pixel + 1];
        outimage[pixel + 2] = inimage[pixel + 0];
        
    }


}


//outimage[pixel    ] : B, outimage[pixel + 1] : G, outimage[pixel + 2] : R로 가정하겠

void rgb2yuv(unsigned char* inimage, unsigned char* outimage)
{
    for(int pixel = 0; pixel < IMAGEHEIGHT * IMAGEWIDTH * CHANNEL; pixel += 3)
    {
        outimage[pixel    ] =  0.257 * inimage[pixel + 2] + 0.504  * inimage[pixel + 1] + 0.098 * inimage[pixel] ; //y
        outimage[pixel + 1] = -0.148 * inimage[pixel + 2] - 0.291  * inimage[pixel + 1] + 0.439 * inimage[pixel] ; //u
        outimage[pixel + 2] =  0.439 * inimage[pixel + 2] - 0.368  * inimage[pixel + 1] - 0.071 * inimage[pixel] ; //v
    }
    //printf("%c", outimage[0]);

}





void imageoverlay(unsigned char* background, unsigned char* foreground, unsigned char* outimage)
{


    unsigned char uv_field[IMAGEHEIGHT * IMAGEWIDTH];
    float alpha[IMAGEHEIGHT * IMAGEWIDTH];


    //calculate alpha
    for(int uv = 0; uv < IMAGEHEIGHT * IMAGEWIDTH * CHANNEL ; uv++)
    {
        uv_field[uv] = ((background[uv] & 0xF0) | ((background[uv] & 0xF0) << 4));
    }
    normalize(uv_field, alpha);

    
    //alpha blending
    for (int i = 0; i < IMAGEHEIGHT * IMAGEWIDTH; i++) 
    
    {
        int row = i / IMAGEWIDTH;
        int col = i % IMAGEWIDTH;
        int pixel_index = row * IMAGEWIDTH + col;
        int out_index = pixel_index * 4; // 4채널이므로 4배
        
        outimage[out_index + 0] = (unsigned char)(alpha[i] * uv_field[i] + (1.0 - alpha[i]) * background[pixel_index * 3 + 2]); // B
        outimage[out_index + 1] = (unsigned char)(alpha[i] * uv_field[i] + (1.0 - alpha[i]) * background[pixel_index * 3 + 1]); // G
        outimage[out_index + 2] = (unsigned char)(alpha[i] * uv_field[i] + (1.0 - alpha[i]) * background[pixel_index * 3 + 0]); // R
        outimage[out_index + 3] = (unsigned char)(alpha[i] * 255); // Alpha

    }


}

void normalize(unsigned char *arr, float *norm_arr) 
{

    float min = 1.0;
    float max = 0.0;
    int num = sizeof(arr) / sizeof(char);

    //find minimum
    for (int i = 1; i < num; i++) 
    {
        if ((float)arr[i] < min) {
            min = arr[i];
        }
    }
    //find maximum
     for (int i = 1; i < num; i++) 
     {
        if ((float)arr[i] > max) {
            max = arr[i];
        }
    }

    //normalize
    for (int i = 0; i < num; i++) 
    {
        norm_arr[i] = ((float)arr[i] - min) / (max - min);
    }
}