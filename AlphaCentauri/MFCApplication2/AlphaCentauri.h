#pragma once
#include "pch.h"

class CAlphaCentauri
{

	//// Member Variables
private:

	vector<int> m_viStep;
	int m_iMaxSpeed;
	int m_iFirstMaxSpeedIndex;


public:


	//// Member Functions

private:

	void CalcMaxSpeed(long long iDistance);
	bool MakeBasicRoute();
	int CountMaxSpeed();
	bool PreProcess();

public:
	CAlphaCentauri();
	~CAlphaCentauri();

	int GetMinWarpCount(long long llOriginPos, long long llTargetPos);
	int GetMaxSpeed() { return m_iMaxSpeed; };
	vector<int>* GetSteps() { return &m_viStep; };
};

