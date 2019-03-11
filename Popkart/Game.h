#pragma once
#include "Car.h"
#include "Track.h"
#include "Award.h"
#include "Tree.h"
#include <vector>

using namespace std;

class CGame
{
public:
	//背景图片（1张 / 多张）
	IplImage * m_pBKImg;
	IplImage * m_loadImg;
	IplImage * m_showImg;
	int m_Width;
	int m_Height;
	//小车
	CCar * m_Car;
	//赛道
	CTrack * m_Track;
	//道具
	//CAward m_Awards;//单个道具
	vector<CAward> m_Awards;
	//树
	vector<CTree> m_Trees;
	//帧率
	int m_Frame;
	//加速时钟
	int m_Clock;
	//暂停控制变量
	int m_Pause;
public:
	CGame();
	~CGame();
	//控制运动（按键或鼠标信息）
	void Move(char key);
	//音效 （参数确定bgm）
	//绘制 （单帧）
	void Draw();
	//暂停（）
	void Pause(char key);
	//产生道具
	void CreateAward();
	//吃道具
	void CatchAward();
	//道具消失
	void DeleteAward();
	//产生树
	void CreateTree();
	//树消失
	void DeleteTree();
	//运行（调用运行所有方法）
	void Run();
};

