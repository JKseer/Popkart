#include "stdafx.h"
#include "Game.h"

#include <highgui.h>
//#include "time.h"


CGame::CGame()
{
	m_pBKImg = cvLoadImage("img/map/map1.png");
	m_loadImg = cvLoadImage("img/map/loading.png");
	m_showImg = cvCloneImage(m_pBKImg);

	m_Width = m_pBKImg->width;
	m_Height = m_pBKImg->height;

	//游戏窗口
	cvNamedWindow("PopkartGame", 1);

	//加载部件
	m_Car = new CCar(m_Width, m_Height);
	m_Track = new CTrack(m_Width, m_Height);
	//m_Awards = new CAward(m_Width, m_Height, this->m_Track->m_SpeedY);

	m_Frame = 25;

	m_Clock = 2000;

	m_Pause = 0;
}


CGame::~CGame()
{
	cvDestroyAllWindows();
	delete m_Car;
	delete m_Track;
	//delete m_Awards;
	vector<CAward>().swap(m_Awards);
	vector<CTree>().swap(m_Trees);
	cvReleaseImage(&m_pBKImg);
	cvReleaseImage(&m_loadImg);
	cvReleaseImage(&m_showImg);
}

void CGame::Move(char key)
{
	//赛道.move
	this->m_Track->Move();
	//道具.move
	vector<CAward>::iterator award;
	award = m_Awards.begin();
	while (award != m_Awards.end()) {
		award->Move();
		award++;
	}
	//树木.move
	vector<CTree>::iterator tree;
	tree = m_Trees.begin();
	while (tree != m_Trees.end()) {
		tree->Move();
		tree++;
	}
	//小车.move
	this->m_Car->Move(key);
	
}

void CGame::Draw()
{
	//重载背景
	cvCopy(this->m_pBKImg, this->m_showImg);
	//修改背景
		//赛道
	this->m_Track->Draw2BK(this->m_showImg);
		//道具
	vector<CAward>::iterator award;
	award = this->m_Awards.begin();
	while (award != m_Awards.end()) {
		award->Draw2BK(this->m_showImg);
		award++;
	}
		//树
	vector<CTree>::iterator tree;
	tree = m_Trees.begin();
	while (tree != m_Trees.end()) {
		tree->Draw2BK(this->m_showImg);;
		tree++;
	}
		//小车
	this->m_Car->Draw2BK(this->m_showImg);
	//刷新背景
	cvShowImage("PopkartGame", this->m_showImg);
}

void CGame::Pause(char key)
{
	if (key == 32) {
		this->m_Pause = (this->m_Pause + 1) % 2;
	}
}

void CGame::CreateAward()
{
	if (rand() % 50 == 49)
	{
		CAward award = CAward(m_Width, m_Height, this->m_Track->m_SpeedY);
		m_Awards.push_back(award);
	}
}

void CGame::CatchAward()
{
	vector<CAward>::iterator award;
	award = this->m_Awards.begin();
	while (award != m_Awards.end()) {
		award->Catch(this->m_Car->m_Position, 
					this->m_Car->m_Image->width);
		this->m_Car->Catch(award ->m_Die);
		if (award->m_Die) {
			award = m_Awards.erase(award);
		}
		else {
			award++;
		}
	}
}

void CGame::DeleteAward()
{
	vector<CAward>::iterator award;
	award = m_Awards.begin();
	while (award != m_Awards.end())
	{
		if (award->m_Die) {
			award = m_Awards.erase(award);
		}
		else {
			award++;
		}
	}
}

void CGame::CreateTree()
{
	if (rand() % 50 == 49)
	{
		CTree tree = CTree(m_Width, m_Height, this->m_Track->m_SpeedY);
		m_Trees.push_back(tree);
	}
}

void CGame::DeleteTree()
{
	vector<CTree>::iterator tree;
	tree = m_Trees.begin();
	while (tree != m_Trees.end())
	{
		if (tree->m_Die) {
			tree = m_Trees.erase(tree);
		}
		else {
			tree++;
		}
	}
}

void CGame::Run()
{
	cvShowImage("PopkartGame", this->m_loadImg);
	//cvWaitKey(3000);
	Draw();
	char key = cvWaitKey();
	if (key == 32) key = 0;
	while (key != 27 && !cvGetWindowHandle("PopkartGame")!=1)
	{
		Pause(key);
		if (!this->m_Pause) {
			Move(key);
			//刷新道具
			CreateAward();
			CatchAward();
			DeleteAward();
			//刷新树
			CreateTree();
			DeleteTree();
			//重绘
			Draw();
		}
		key = cvWaitKey(1000 / this->m_Frame);
	}
}