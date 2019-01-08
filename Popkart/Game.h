#pragma once
#include "Car.h"
#include "Track.h"

class CGame
{
public:
	//����ͼƬ��1�� / ���ţ�
	IplImage * m_pBKImg;
	IplImage * m_openImg;
	IplImage * m_showImg;
	int m_Width;
	int m_Height;
	//С��
	CCar * m_Car;
	//����
	CTrack * m_Track;
	//����
public:
	CGame();
	~CGame();
	//�����˶��������������Ϣ��
	void Move(char key);
	//�Ե���
	//��Ч ������ȷ��bgm��
	//���� ����֡��
	void Draw();
	//���У������������з�����
	void Run();

};

