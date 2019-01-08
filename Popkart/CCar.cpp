#include "stdafx.h"
#include "Car.h"

#include <highgui.h>
#include "Tools.h"

CCar::CCar()
{
	m_Image = cvLoadImage("../img/car/uupoop11.png", 1);
	m_LeftImage = cvLoadImage("../img/car/uupoop10.png", 1); 
	m_RightImage = cvLoadImage("../img/car/uupoop12.png", 1);
	m_LLeftImage = cvLoadImage("../img/car/uupoop9.png", 1);
	m_RRightImage = cvLoadImage("../img/car/uupoop13.png", 1);

	m_SpeedX = 3;
	m_SpeedY = 3;

	m_Position.x = 100;
	m_Position.y = 100;
	m_OriginPosition = m_Position;

	m_HP = 100;

	m_Toward = 0;
}

CCar::CCar(int BKWidth, int BKHeight)
{
	m_Image = cvLoadImage("../img/car/uupoop11.png", 1); ;
	m_LeftImage = cvLoadImage("../img/car/uupoop10.png", 1);
	m_RightImage = cvLoadImage("../img/car/uupoop12.png", 1);
	m_LLeftImage = cvLoadImage("../img/car/uupoop9.png", 1);
	m_RRightImage = cvLoadImage("../img/car/uupoop13.png", 1);

	m_SpeedX = 3;
	m_SpeedY = 3;

	m_Position.x = BKHeight - this->m_Image->height * 3 / 2;
	m_Position.y = BKWidth / 2 - this->m_Image->width / 2;

	m_OriginPosition = m_Position;

	m_HP = 100;

	m_BorderX = BKHeight;
	m_BorderY = BKWidth;

	m_Toward = 0;
	//m_Shine = 0;
}


CCar::~CCar()
{
	cvReleaseImage(&m_Image);
	cvReleaseImage(&m_LeftImage);
	cvReleaseImage(&m_RightImage);
	cvReleaseImage(&m_LLeftImage);
	cvReleaseImage(&m_RRightImage);
}

void CCar::Move(char key)
{
	int ImgLeft = this->m_Position.y;
	int ImgRight = this->m_Position.y + this->m_Image->width;
	int BorderLeft = (int)(this->m_BorderY * 0.1);
	int BorderRight = this->m_BorderY - BorderLeft;
	if (ImgLeft > BorderLeft && ImgRight < BorderRight) {
		if (((key == 'a') || (key == 'A')) 
			&& (ImgLeft != BorderLeft + 1)) {
			this->m_Position.y -= this->m_SpeedY;
			this->m_Toward--;
		}
		else if (((key == 'd') || (key == 'D'))
			&& (ImgRight != BorderRight - 1)) {
			this->m_Position.y += this->m_SpeedY;
			this->m_Toward++;
		}
		else if ((key == 'r') || (key == 'R')) {
			this->m_Position.y = this->m_OriginPosition.y;
			this->m_Toward = 0;
		}
	}
}

void CCar::Shake()
{
	int shake = rand() % 3;//Ëæ»ú¶¶¶¯Á¿
	if (this->m_OriginPosition.x < this->m_Position.x) {
		this->m_Position.x = this->m_OriginPosition.x - shake;
	}
	else {
		this->m_Position.x = this->m_OriginPosition.x + shake;
	}
}

void CCar::Draw2BK(IplImage * pbkImg)
{
	IplImage * img;
	if (m_Toward > 20) {
		if (m_Toward < 60) {
			img = m_RightImage;
		}
		else {
			img = m_RRightImage;
		}
	}
	else if (m_Toward < -20) {
		if (m_Toward > -60) {
			img = m_LeftImage;
		}
		else {
			img = m_LLeftImage;
		}
	}
	else {
		img = m_Image;
	}
	Shake();
	CTools::Draw2BK(pbkImg ,
		img , this->m_Position.x,
		this->m_Position.y, 0, 255, 0);
}
