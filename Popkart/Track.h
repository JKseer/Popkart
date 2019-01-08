#pragma once
#include <cv.h>

class CTrack
{
public:
	//����������ʵ�ߣ�����
	CvPoint m_TrackStartL, m_TrackStartR;//Զ��
	CvPoint m_TrackEndL, m_TrackEndR;//����
	//������ɫ
	CvScalar m_TrackColor;
	//������
	int m_TrackWidth;
	//�����������ߣ����ߣ�����
	CvPoint m_LineStartL, m_LineStartC, m_LineStartR;//Զ��
	CvPoint m_LineEndL, m_LineEndC, m_LineEndR;//Զ��
	//��������ɫ
	CvScalar m_LineColor;
	//�������߿�
	int m_LineWidth;
	//ÿ������xy������
	int m_LineY;
	int m_LineX;
	//������������
	int m_LineRun;
public:
	CTrack();
	CTrack(int BKWidth, int BKHeight);
	~CTrack();
	//�ƶ�
	void Move(char key);
	//����
	void Draw2BK(IplImage * pbkImg);
};

