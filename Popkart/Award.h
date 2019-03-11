#pragma once
#include <cv.h>

class CAward
{
public:
	//图片(多张)
	static IplImage * m_AwardImage[];
	//缩放尺寸
	CvSize m_CurrSize;
	//种类(普通/加速/陷阱)
	int m_ID;
	//能量（被吃掉时给小车加分）
	int m_HP;
	//是否被拾取(控制图片消失)
	bool m_Die;
	//可拾取宽度
	int m_Width;
	//移动轨迹端点
	int m_RoadID;//轨迹编号
	CvPoint m_Start;//远端
	CvPoint m_End;//近端
	//当前位置（直接无法给出，变化）
	CvPoint m_Current;
	//可以被拾取位置
	CvPoint m_Get;
	//速度
	int m_SpeedY;
	int m_SpeedX;
public:
	CAward();
	CAward(int BKWidth, int BKHeight, int Speed);
	~CAward();
	//移动
	void Move();
	//尺寸变化
	void Scale();
	//被拾取消失
	void Catch(CvPoint carPoint, int carWidth);
	//绘制
	void Draw2BK(IplImage * bkimg);
};

