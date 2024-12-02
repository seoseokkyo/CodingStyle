#include "pch.h"
#include "AlphaCentauri.h"

CAlphaCentauri::CAlphaCentauri()
{
    m_iMaxSpeed = 0;
    m_iFirstMaxSpeedIndex = 0;
}

CAlphaCentauri::~CAlphaCentauri()
{
}

int CAlphaCentauri::GetMinWarpCount(long long llOriginPos, long long llTargetPos)
{
    long long llDist = llTargetPos - llOriginPos;

    CalcMaxSpeed(llDist);
    MakeBasicRoute();

    int iProcessCount = llDist - pow(m_iMaxSpeed, 2);

    for (int i = 0; i < iProcessCount; i++)
    {
        bool bRunCheck = PreProcess();

        if (bRunCheck)
            continue;
        else
        {
            int iMaxIndex = (int)m_viStep.size() - 1;
            int iFind = 0;

            while (1)
            {
                if (iFind >= iMaxIndex / 2)
                    break;

                if (m_viStep[iMaxIndex - iFind - 1] == m_viStep[iMaxIndex - iFind])
                {
                    m_viStep[iMaxIndex - iFind - 1]++;
                    break;
                }
                else
                {
                    iFind++;
                }
            }
        }
    }

    return (int)m_viStep.size();
}

void CAlphaCentauri::CalcMaxSpeed(long long iDistance)
{
    m_iMaxSpeed = 0;

    while (1)
    {
        if (pow(m_iMaxSpeed, 2) <= iDistance && pow(m_iMaxSpeed + 1, 2) <= iDistance)
            m_iMaxSpeed++;
        else
            break;
    }
}

bool CAlphaCentauri::MakeBasicRoute()
{
    if (m_iMaxSpeed == 0)
        return false;

    m_viStep.clear();
    int iCount = 0;

    for (int i = 1; i <= m_iMaxSpeed; i++)
    {
        m_viStep.emplace_back(i);

        if (i <= m_iMaxSpeed)
            m_iFirstMaxSpeedIndex = iCount;

        iCount++;
    }

    for (int i = m_iMaxSpeed-1; i >= 1; i--)
    {
        m_viStep.emplace_back(i);
    }

    return true;
}

int CAlphaCentauri::CountMaxSpeed()
{
    int iCount = 0;
    for (int i = m_iFirstMaxSpeedIndex; i < m_iFirstMaxSpeedIndex + 2; i++)
    {
        if (m_viStep[i] == m_iMaxSpeed)
            iCount++;
    }

    return iCount;
}

bool CAlphaCentauri::PreProcess()
{
    int iCheck = CountMaxSpeed();

    if (iCheck == 3)
    {
        m_viStep[m_iFirstMaxSpeedIndex + 1]++;
        return true;
    }
    else
    {
        int iCompareStartStep = m_iFirstMaxSpeedIndex + iCheck-1;
        int iSpeedCompare = m_iMaxSpeed;
        bool bSameCheck = false;
        int iSize = (int)m_viStep.size();

        while (1)
        {
            if (m_viStep[iCompareStartStep] == iSpeedCompare)
            {
                if (iSpeedCompare == 1 && (iCompareStartStep == iSize-1))
                {
                    bSameCheck = true;
                    break;
                }

                iCompareStartStep++;
                iSpeedCompare--;
                continue;
            }
            else
                break;
        }

        if (bSameCheck)
        {
            m_viStep.emplace_back(1);
            return true;
        }            
    }

    return false;
}
