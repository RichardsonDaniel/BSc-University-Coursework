#pragma once
#include "glaux.h"
#include <cstdio>
#pragma comment(lib,"glaux.lib")

struct whd_bitmap
{
	int width;
	int height;
	GLubyte* data;
	
	// default constructor
	whd_bitmap()
	{
		data=NULL;
		width=0;
		height=0;
	}
	
	// destructor
	~whd_bitmap()
	{
		delete[] data;
	}
	
	// load picture and set key color alpha value to 0
	void load(const wchar_t* image,const GLubyte& r,const GLubyte& g,const GLubyte& b)
	{
		AUX_RGBImageRec *bitmap_RGB = auxDIBImageLoad(image);
		GLubyte *bitmap_RGBA = NULL;

		if (bitmap_RGB!=NULL)
		{
			int imageSize_RGB=bitmap_RGB->sizeX*bitmap_RGB->sizeY*3;
			int imageSize_RGBA=bitmap_RGB->sizeX*bitmap_RGB->sizeY*4;

			bitmap_RGBA=new GLubyte[imageSize_RGBA];

			int i,j;

			for(i=0,j=0;i<imageSize_RGB;i+=3,j+=4)
			{
				if ((bitmap_RGB->data[i]==r) // if pixel color equals to color key
					&&(bitmap_RGB->data[i+1]==g)
					&&(bitmap_RGB->data[i+2]==b))
				{
					bitmap_RGBA[j+3]=0;
				}
				else
				{
					bitmap_RGBA[j+3]=255;
				}
				bitmap_RGBA[j]=bitmap_RGB->data[i];
				bitmap_RGBA[j+1]=bitmap_RGB->data[i+1];
				bitmap_RGBA[j+2]=bitmap_RGB->data[i+2];
			}
		}
		data=bitmap_RGBA;
		width=bitmap_RGB->sizeX;
		height=bitmap_RGB->sizeY;
		if (data==0)
		{
			printf("%s %s \n","Cannot open ",image);
			system("pause");
			exit(1);
		}
		delete[] bitmap_RGB;
	}
	
	// simple just load the picture
	void load(const wchar_t* image)
	{
		AUX_RGBImageRec* bitmap_RGB=auxDIBImageLoad(image);
		GLubyte *bitmap_RGBA = NULL;

		if (bitmap_RGB!=NULL)
		{
			int imageSize_RGB=bitmap_RGB->sizeX*bitmap_RGB->sizeY*3;
			int imageSize_RGBA=bitmap_RGB->sizeX*bitmap_RGB->sizeY*4;

			bitmap_RGBA=new GLubyte[imageSize_RGBA];

			int i,j;

			for(i=0,j=0;i<imageSize_RGB;i+=3,j+=4)
			{
				bitmap_RGBA[j]=bitmap_RGB->data[i];
				bitmap_RGBA[j+1]=bitmap_RGB->data[i+1];
				bitmap_RGBA[j+2]=bitmap_RGB->data[i+2];
				bitmap_RGBA[j+3]=255;
			}
		}
		data=bitmap_RGBA;
		width=bitmap_RGB->sizeX;
		height=bitmap_RGB->sizeY;
		if (data==0)
		{
			printf("%s %s \n","Cannot open ",image);
			system("pause");
			exit(1);
		}
		delete[] bitmap_RGB;
	}
};
