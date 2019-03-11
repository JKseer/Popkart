#pragma once
#include "cv.h"

class CTools
{
public:
	CTools();
	~CTools();
	static void Draw2BK(IplImage * pbkImg,
		IplImage * pimg,
		int row, int col,
		uchar keyb, uchar keyg, uchar keyr);
	static void TransDraw2BK(IplImage * pbkImg,
		IplImage * lastImg, const char * winName);
};

