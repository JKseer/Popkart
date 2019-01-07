#pragma once
#include <cv.h>

class CCar
{
public:
	//ͼƬ��1�� / ���ţ�
	IplImage * m_Image;
	IplImage * m_LeftImage; 
	IplImage * m_RightImage;
	IplImage * m_LLeftImage;
	IplImage * m_RRightImage;
	int m_ImgIndex;
	//�ٶȣ�x,y��
	int m_SpeedX;
	int m_SpeedY;
	//λ�ã�x��y��
	CvPoint m_Position;
	CvPoint m_OriginPosition;//��¼��ʼλ������
	//����
	int m_HP;
	//�ƶ��߽�
	int m_BorderX;
	int m_BorderY;
	//�˶�״̬����ʼ������־��
	int m_Toward; //�����־,Ϊ0ֱ��,Ϊ�����ң�Ϊ������
public:
	CCar();
	CCar(int BKWidth, int BKHeight);
	~CCar();
	//�ƶ�
	void Move(char key);
	//�Ե���
	//��Ч 
	//����
	void Draw2BK(IplImage * pbkImg);
};

