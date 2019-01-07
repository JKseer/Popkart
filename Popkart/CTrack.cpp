#include "stdafx.h"
#include "Track.h"


CTrack::CTrack()
{
}

CTrack::CTrack(int BKWidth, int BKHeight)
{	
	m_TrackStartL = cvPoint(BKWidth * 0.4, BKHeight * 0.28);
	m_TrackStartR = cvPoint(BKWidth * 0.6, BKHeight * 0.28);
	m_TrackEndL = cvPoint(0, BKHeight * 0.78);
	m_TrackEndR = cvPoint(BKWidth, BKHeight * 0.78);
	
	m_TrackColor = cvScalar(255,255,255);
	
	m_TrackWidth = 5;
	
	m_LineStartL = cvPoint(BKWidth * 0.43, BKHeight * 0.7);
	m_LineStartC = cvPoint(BKWidth * 0.57, BKHeight * 0.7);
	m_LineStartR = cvPoint(BKWidth * 0.5, BKHeight * 0.7);
	m_LineEndL = cvPoint(0, BKHeight * 0.9);
	m_LineEndC = cvPoint(BKWidth, BKHeight * 0.9);
	m_LineEndR = cvPoint(BKWidth * 0.5, BKHeight);
	
	m_LineColor = cvScalar(0,255,255);
	
	m_LineWidth = 3;
	
	m_LineLength = BKHeight / 20;

	int tempX = abs(m_LineStartL.x - m_LineEndL.x);
	int tempY = abs(m_LineStartL.y - m_LineEndL.y);
	m_Angle = atan(tempY / tempX);
}


CTrack::~CTrack()
{
}

void CTrack::Move(char key)
{

}

void CTrack::Draw2BK(IplImage * pbkImg)
{
	cvLine(pbkImg, this->m_TrackStartL, this->m_TrackEndL,
		this->m_TrackColor, this->m_TrackWidth, CV_AA);

	cvLine(pbkImg, this->m_TrackStartR, this->m_TrackEndR,
		this->m_TrackColor, this->m_TrackWidth, CV_AA);


}
