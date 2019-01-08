#pragma once
#include "Car.h"
#include "Track.h"

class CGame
{
public:
	//背景图片（1张 / 多张）
	IplImage * m_pBKImg;
	IplImage * m_openImg;
	IplImage * m_showImg;
	int m_Width;
	int m_Height;
	//小车
	CCar * m_Car;
	//赛道
	CTrack * m_Track;
	//道具
public:
	CGame();
	~CGame();
	//控制运动（按键或鼠标信息）
	void Move(char key);
	//吃道具
	//音效 （参数确定bgm）
	//绘制 （单帧）
	void Draw();
	//运行（调用运行所有方法）
	void Run();

};

