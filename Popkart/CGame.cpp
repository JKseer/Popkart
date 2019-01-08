#include "stdafx.h"
#include "Game.h"

#include <highgui.h>


CGame::CGame()
{
	m_pBKImg = cvLoadImage("../img/map/map1.png");
	m_openImg = cvLoadImage("../img/map/loading.png");
	m_showImg = cvCloneImage(m_pBKImg);

	m_Width = m_pBKImg->width;
	m_Height = m_pBKImg->height;

	//游戏窗口
	cvNamedWindow("PopkartGame", 1);

	//加载部件
	m_Car = new CCar(m_Width, m_Height);
	m_Track = new CTrack(m_Width, m_Height);
}


CGame::~CGame()
{
	cvDestroyAllWindows();
	delete m_Car;
	delete m_Track;
	cvReleaseImage(&m_pBKImg);
	cvReleaseImage(&m_openImg);
	cvReleaseImage(&m_showImg);
}

void CGame::Move(char key)
{
	this->m_Track->Move(key);
	this->m_Car->Move(key);
	//道具.move
	//树木.move
}

void CGame::Draw()
{
	//重载背景
	cvCopy(this->m_pBKImg, this->m_showImg);
	//修改背景
	this->m_Track->Draw2BK(this->m_showImg);
	this->m_Car->Draw2BK(this->m_showImg);
	//刷新背景
	cvShowImage("PopkartGame", this->m_showImg);
}

void CGame::Run()
{
	cvShowImage("PopkartGame", this->m_openImg);
	cvWaitKey(3000);
	while (true)
	{
		Draw();
		char key = cvWaitKey(40);
		Move(key);
		if (key == 27 || !cvGetWindowHandle("PopkartGame"))
			break;
	}
}
