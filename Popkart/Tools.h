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
};

