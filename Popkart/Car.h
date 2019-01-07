#pragma once
#include <cv.h>

class CCar
{
public:
	//图片（1张 / 多张）
	IplImage * m_Image;
	IplImage * m_LeftImage; 
	IplImage * m_RightImage;
	IplImage * m_LLeftImage;
	IplImage * m_RRightImage;
	int m_ImgIndex;
	//速度（x,y）
	int m_SpeedX;
	int m_SpeedY;
	//位置（x，y）
	CvPoint m_Position;
	CvPoint m_OriginPosition;//记录起始位置坐标
	//能量
	int m_HP;
	//移动边界
	int m_BorderX;
	int m_BorderY;
	//运动状态（开始结束标志）
	int m_Toward; //方向标志,为0直行,为正向右，为负向左
public:
	CCar();
	CCar(int BKWidth, int BKHeight);
	~CCar();
	//移动
	void Move(char key);
	//吃道具
	//音效 
	//绘制
	void Draw2BK(IplImage * pbkImg);
};

