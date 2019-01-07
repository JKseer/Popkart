#include "stdafx.h"
#include "Tools.h"


CTools::CTools()
{
}


CTools::~CTools()
{
}

void CTools::Draw2BK(IplImage * pbkImg, IplImage * pimg, int row, int col, uchar keyb, uchar keyg, uchar keyr)
{
	for (int i = 0; i < pimg->height; i++) {//ÐÐ
		for (int j = 0; j < pimg->width; j++) { //ÁÐ
			uchar b = CV_IMAGE_ELEM(pimg, uchar, i, j * 3);
			uchar g = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
			uchar r = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);
			if ((b == keyb) && (r == keyr) && (g == keyg))
				continue;

			CV_IMAGE_ELEM(pbkImg, uchar, i + row, (j + col) * 3) = b;
			CV_IMAGE_ELEM(pbkImg, uchar, i + row, (j + col) * 3 + 1) = g;
			CV_IMAGE_ELEM(pbkImg, uchar, i + row, (j + col) * 3 + 2) = r;
		}
	}
}
