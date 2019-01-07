#include "stdafx.h"
#include "Game.h"

#include <highgui.h>


CGame::CGame()
{
	this->m_pBKImg = cvLoadImage("../img/map/map1.png");
	this->m_showImg = cvCloneImage(this->m_pBKImg);

	this->m_Width = this->m_pBKImg->width;
	this->m_Height = this->m_pBKImg->height;

	//游戏窗口
	cvNamedWindow("PopkartGame", 1);
	
	//加载部件
	this->m_Car = CCar(this->m_Width, this->m_Height);
	this->m_Track = CTrack(this->m_Width, this->m_Height);
}


CGame::~CGame()
{
	cvDestroyAllWindows();
	cvReleaseImage(&m_pBKImg);
	cvReleaseImage(&m_showImg);
}

void CGame::Move(char key)
{
	this->m_Car.Move(key);
	//道具.move
	//树木.move
}

void CGame::Draw()
{
	//重载背景
	cvCopy(this->m_pBKImg, this->m_showImg);
	//修改背景
	this->m_Car.Draw2BK(this->m_showImg);
	this->m_Track.Draw2BK(this->m_showImg);
	//刷新背景
	cvShowImage("PopkartGame", this->m_showImg);
}

void CGame::Run()
{
	while (true)
	{
		Draw();
		char key = cvWaitKey(40);
		Move(key);
		if (key == 27 || !cvGetWindowHandle("PopkartGame"))
			break;
	}
}
