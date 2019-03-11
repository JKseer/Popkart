#include "stdafx.h"
#include "Track.h"


CTrack::CTrack()
{
}

CTrack::CTrack(int BKWidth, int BKHeight)
{	
	int TrackTop = BKHeight * 0.28;
	int TrackBottom = BKHeight * 0.78;
	m_TrackStartL = cvPoint(BKWidth * 0.4, TrackTop);
	m_TrackStartR = cvPoint(BKWidth * 0.6, TrackTop);
	m_TrackEndL = cvPoint(0, TrackBottom);
	m_TrackEndR = cvPoint(BKWidth, TrackBottom);
	
	m_TrackColor = cvScalar(255,255,255);
	
	m_TrackWidth = 8;
	
	int LineTop = TrackTop;
	int LineBottom = TrackBottom;
	m_LineStartL = cvPoint(BKWidth * 0.44, LineTop);
	m_LineStartC = cvPoint(BKWidth * 0.5, LineTop);
	m_LineStartR = cvPoint(BKWidth * 0.56, LineTop);
	m_LineEndL = cvPoint(0, LineBottom);
	m_LineEndC = cvPoint(BKWidth * 0.5, BKHeight);
	m_LineEndR = cvPoint(BKWidth, LineBottom);
	
	m_LineColor = cvScalar(255,255,255);
	
	m_LineWidth = 3;

	double LineX = abs(m_LineStartL.x - m_LineEndL.x);
	double LineY = abs(LineBottom - LineTop);
	double Angle = atan(LineX / LineY);	

	m_SpeedY = (BKHeight - TrackTop) / 9 * 0.2;
	m_SpeedX = m_SpeedY * Angle;

	m_LineRun = 0;
}


CTrack::~CTrack()
{
}

void CTrack::Move()
{
	this->m_LineRun++;
	if (this->m_LineRun == 5)
		this->m_LineRun = 0;
}

void CTrack::Draw2BK(IplImage * pbkImg)
{
	cvLine(pbkImg, this->m_TrackStartL, this->m_TrackEndL,
		this->m_TrackColor, this->m_TrackWidth, CV_AA);
	cvLine(pbkImg, this->m_TrackStartR, this->m_TrackEndR,
		this->m_TrackColor, this->m_TrackWidth, CV_AA);

	CvPoint Start, End;
	for (int i = 0; i < 10; i++) {
		Start.y = m_LineStartC.y + m_SpeedY * (5 * i + this->m_LineRun);
		End.y = Start.y + (int)(m_SpeedY * 2.5);
		for (int j = 0; j < 3; j++) {
			switch (j)
			{
			case 0:Start.x = m_LineStartL.x - m_SpeedX * (5 * i + this->m_LineRun);
				End.x = Start.x - (int)(m_SpeedX * 2.5);
				break;
			case 1:Start.x = m_LineStartC.x;
				End.x = Start.x;
				break;
			case 2:Start.x = m_LineStartR.x + m_SpeedX * (5 * i + this->m_LineRun);
				End.x = Start.x + (int)(m_SpeedX * 2.5);
				break;
			}
			cvLine(pbkImg, Start, End,
				this->m_LineColor, this->m_LineWidth, CV_AA);
		}
	}
}
