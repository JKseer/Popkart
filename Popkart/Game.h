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
	//����ͼƬ��1�� / ���ţ�
	IplImage * m_pBKImg;
	IplImage * m_loadImg;
	IplImage * m_showImg;
	int m_Width;
	int m_Height;
	//С��
	CCar * m_Car;
	//����
	CTrack * m_Track;
	//����
	//CAward m_Awards;//��������
	vector<CAward> m_Awards;
	//��
	vector<CTree> m_Trees;
	//֡��
	int m_Frame;
	//����ʱ��
	int m_Clock;
	//��ͣ���Ʊ���
	int m_Pause;
public:
	CGame();
	~CGame();
	//�����˶��������������Ϣ��
	void Move(char key);
	//��Ч ������ȷ��bgm��
	//���� ����֡��
	void Draw();
	//��ͣ����
	void Pause(char key);
	//��������
	void CreateAward();
	//�Ե���
	void CatchAward();
	//������ʧ
	void DeleteAward();
	//������
	void CreateTree();
	//����ʧ
	void DeleteTree();
	//���У������������з�����
	void Run();
};

