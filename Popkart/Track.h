#pragma once
#include <cv.h>

class CTrack
{
public:
	//左右赛道（实线）坐标
	CvPoint m_TrackStartL, m_TrackStartR;//远端
	CvPoint m_TrackEndL, m_TrackEndR;//近端
	//赛道颜色
	CvScalar m_TrackColor;
	//赛道宽
	int m_TrackWidth;
	//左中右赛道线（虚线）坐标
	CvPoint m_LineStartL, m_LineStartC, m_LineStartR;//远端
	CvPoint m_LineEndL, m_LineEndC, m_LineEndR;//远端
	//赛道线颜色
	CvScalar m_LineColor;
	//赛道线线宽
	int m_LineWidth;
	//每段虚线xy方向跨度
	int m_SpeedY;
	int m_SpeedX;
	//控制赛道滚动
	int m_LineRun;
public:
	CTrack();
	CTrack(int BKWidth, int BKHeight);
	~CTrack();
	//移动
	void Move();
	//绘制
	void Draw2BK(IplImage * pbkImg);
};

