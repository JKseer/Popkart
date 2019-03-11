#include "stdafx.h"
#include "Award.h"

#include <highgui.h>
#include "Tools.h"
#include "time.h"

IplImage * CAward::m_AwardImage[5]{
	cvLoadImage("img/awards/1.bmp", 1),
	cvLoadImage("img/awards/2.bmp", 1),
	cvLoadImage("img/awards/3.bmp", 1),
	cvLoadImage("img/awards/4.bmp", 1),
	cvLoadImage("img/awards/5.bmp", 1) };

CAward::CAward()
{
}

CAward::CAward(int BKWidth, int BKHeight, int SpeedY)
{
	//srand((unsigned)time(NULL));

	m_ID = rand() % 5;

	m_HP = m_ID * 50;

	m_CurrSize = cvSize(15, 15);

	m_Die = 0;

	int count = 5;//¹ìµÀÊý
	m_Width = (BKWidth * 0.8) / count;

	m_RoadID = rand() % count;
	m_Start.x = BKWidth * (0.44 + 0.06 / count * (m_RoadID * 2 +1));
	m_Start.y = BKHeight * 0.28;
	m_End.x = BKWidth * (0.5 / count * (m_RoadID * 2 + 1));
	m_End.y = BKHeight;

	m_Current = m_Start;

	m_Get.x = m_Width * (m_RoadID + 0.5) - m_CurrSize.width * 0.5;
	m_Get.y = BKHeight * 0.7 - m_CurrSize.height * 0.5;

	m_SpeedY = SpeedY;
	m_SpeedX = m_SpeedY * (m_End.x - m_Start.x) / (m_End.y - m_Start.y);
}

CAward::~CAward()
{
}

void CAward::Move()
{
	this->m_Current.x += m_SpeedX;
	this->m_Current.y += m_SpeedY;

	if (this->m_Current.y - this->m_CurrSize.height > this->m_End.y)
		this->m_Die = 1;
}

void CAward::Scale()
{
	this->m_CurrSize.width += 1;
	this->m_CurrSize.height += 1;
}

void CAward::Catch(CvPoint carPoint, int carWidth)
{
	if (abs(carPoint.y - this->m_Get.y) < 50) {
		if (carPoint.x - this->m_Get.x < carWidth / 2) {
			this->m_Die = 1;
		}
	}
}

void CAward::Draw2BK(IplImage * bkimg)
{
	Scale();
	if (!this->m_Die) {
		IplImage * img = cvCreateImage(this->m_CurrSize,
			m_AwardImage[this->m_ID]->depth,
			m_AwardImage[this->m_ID]->nChannels);
		cvResize(this->m_AwardImage[this->m_ID], img, CV_INTER_LINEAR);

		CTools::Draw2BK(bkimg, img,
			this->m_Current.x - this->m_CurrSize.width / 2,
			this->m_Current.y - this->m_CurrSize.height / 2,
			255, 255, 255);

		cvReleaseImage(&img);
	}
}
