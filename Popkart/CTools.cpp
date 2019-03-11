#include "stdafx.h"
#include "Tools.h"

#include <highgui.h>

CTools::CTools()
{
}


CTools::~CTools()
{
}

void CTools::Draw2BK(IplImage * pbkImg, IplImage * pimg, int col, int row, uchar keyb, uchar keyg, uchar keyr)
{
	for (int i = 0; i < pimg->height; i++) {//行
		for (int j = 0; j < pimg->width; j++) { //列
			uchar b = CV_IMAGE_ELEM(pimg, uchar, i, j * 3);
			uchar g = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
			uchar r = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);
			if ((b == keyb) && (r == keyr) && (g == keyg))
				continue;

			if (row + i < pbkImg->height && row + i > 0 
				&& col + j < pbkImg->width && col + j > 0) {
				CV_IMAGE_ELEM(pbkImg, uchar, i + row, (j + col) * 3) = b;
				CV_IMAGE_ELEM(pbkImg, uchar, i + row, (j + col) * 3 + 1) = g;
				CV_IMAGE_ELEM(pbkImg, uchar, i + row, (j + col) * 3 + 2) = r;
			}
		}
	}
}

void CTools::TransDraw2BK(IplImage * pbkImg, IplImage * lastImg, const char * winName)
{
	IplImage * nextImg = NULL;
	cvCopy(pbkImg, nextImg);
	for (int i = 0; i < nextImg->height; i++) {//行
		for (int j = 0; j < nextImg->width; j++) { //列
			uchar b1 = CV_IMAGE_ELEM(lastImg, uchar, i, j * 3) / 16;
			uchar g1 = CV_IMAGE_ELEM(lastImg, uchar, i, j * 3 + 1) / 16;
			uchar r1 = CV_IMAGE_ELEM(lastImg, uchar, i, j * 3 + 2) / 16;

			uchar b2 = CV_IMAGE_ELEM(nextImg, uchar, i, j * 3) / 16.0;
			uchar g2 = CV_IMAGE_ELEM(nextImg, uchar, i, j * 3 + 1) / 16.0;
			uchar r2 = CV_IMAGE_ELEM(nextImg, uchar, i, j * 3 + 2) / 16.0;

			for (int k = 0; k < 16; k++){
				CV_IMAGE_ELEM(nextImg, uchar, i, j * 3) = b1 * (16 - k) + b2 * k;
				CV_IMAGE_ELEM(nextImg, uchar, i, j * 3 + 1) = g1 * (16 -k)+ g2 * k;
				CV_IMAGE_ELEM(nextImg, uchar, i, j * 3 + 2) = r1 * (16 -k)+ r2 * k;
				cvShowImage(winName, nextImg);
			}
			cvShowImage(winName, pbkImg);
		}
	}

	cvReleaseImage(&nextImg);
}
