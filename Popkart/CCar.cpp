#include "stdafx.h"
#include "Car.h"

#include <highgui.h>
#include "Tools.h"
#include "Award.h"

CCar::CCar()
{
	m_Image = cvLoadImage("../img/car/uupoop11.png", 1);
	m_LeftImage = cvLoadImage("../img/car/uupoop10.png", 1); 
	m_RightImage = cvLoadImage("../img/car/uupoop12.png", 1);
	m_LLeftImage = cvLoadImage("../img/car/uupoop9.png", 1);
	m_RRightImage = cvLoadImage("../img/car/uupoop13.png", 1);

	m_SpeedX = 100;
	m_SpeedY = 3;

	m_Position.x = 15;
	m_Position.y = 3;
	m_OriginPosition = m_Position;

	m_HP = 100;

	m_Toward = 0;
}

CCar::CCar(int BKWidth, int BKHeight)
{
	m_Image = cvLoadImage("img/car/uupoop11.png", 1); ;
	m_LeftImage = cvLoadImage("img/car/uupoop10.png", 1);
	m_RightImage = cvLoadImage("img/car/uupoop12.png", 1);
	m_LLeftImage = cvLoadImage("img/car/uupoop9.png", 1);
	m_RRightImage = cvLoadImage("img/car/uupoop13.png", 1);

	m_SpeedX = 15;
	m_SpeedY = 3;

	m_Position.x = BKWidth / 2;
	m_Position.y = BKHeight * 5 / 6;

	m_OriginPosition = m_Position;

	m_HP = 10000;

	m_BorderX = BKWidth;
	m_BorderY = BKHeight;

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
	int ImgLeft = this->m_Position.x - this->m_Image->width / 2;
	int ImgRight = this->m_Position.x + this->m_Image->width / 2;
	int BorderLeft = (int)(this->m_BorderX * 0.1);
	int BorderRight = this->m_BorderX - BorderLeft;
	if (ImgLeft > BorderLeft && ImgRight < BorderRight) {
		if (((key == 'a') || (key == 'A')) 
			&& (ImgLeft - this->m_SpeedX > BorderLeft)) {
			this->m_Position.x -= this->m_SpeedX;
			this->m_Toward --;
		}
		else if (((key == 'd') || (key == 'D'))
			&& (ImgRight + this->m_SpeedX < BorderRight)) {
			this->m_Position.x += this->m_SpeedX;
			this->m_Toward ++;
		}
		else if ((key == 'r') || (key == 'R')) {
			this->m_Position.x = this->m_OriginPosition.x;
			this->m_Toward = 0;
		}
	}
	Shake();
}

void CCar::Shake()
{
	int shake = rand() % 3;//Ëæ»ú¶¶¶¯Á¿
	if (this->m_OriginPosition.y < this->m_Position.y) {
		this->m_Position.y = this->m_OriginPosition.y - shake;
	}
	else {
		this->m_Position.y = this->m_OriginPosition.y + shake;
	}
}

void CCar::Catch(bool flag)
{
	this->m_HP += flag * 1000;
}

void CCar::Draw2BK(IplImage * pbkImg)
{
	this->m_HP --;

	IplImage * img;
	if (m_Toward > 4) {
		if (m_Toward < 12) {
			img = m_RightImage;
		}
		else {
			img = m_RRightImage;
		}
	}
	else if (m_Toward < -4) {
		if (m_Toward > -12) {
			img = m_LeftImage;
		}
		else {
			img = m_LLeftImage;
		}
	}
	else {
		img = m_Image;
	}

	CTools::Draw2BK(pbkImg , img,
		this->m_Position.x - this->m_Image->width / 2, 
		this->m_Position.y - this->m_Image->height, 
		0, 255, 0);

	//cvReleaseImage(&img);
}
