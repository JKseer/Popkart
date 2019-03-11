#pragma once
#include <cv.h>

class CAward
{
public:
	//ͼƬ(����)
	static IplImage * m_AwardImage[];
	//���ųߴ�
	CvSize m_CurrSize;
	//����(��ͨ/����/����)
	int m_ID;
	//���������Ե�ʱ��С���ӷ֣�
	int m_HP;
	//�Ƿ�ʰȡ(����ͼƬ��ʧ)
	bool m_Die;
	//��ʰȡ���
	int m_Width;
	//�ƶ��켣�˵�
	int m_RoadID;//�켣���
	CvPoint m_Start;//Զ��
	CvPoint m_End;//����
	//��ǰλ�ã�ֱ���޷��������仯��
	CvPoint m_Current;
	//���Ա�ʰȡλ��
	CvPoint m_Get;
	//�ٶ�
	int m_SpeedY;
	int m_SpeedX;
public:
	CAward();
	CAward(int BKWidth, int BKHeight, int Speed);
	~CAward();
	//�ƶ�
	void Move();
	//�ߴ�仯
	void Scale();
	//��ʰȡ��ʧ
	void Catch(CvPoint carPoint, int carWidth);
	//����
	void Draw2BK(IplImage * bkimg);
};

