#include "BaseInclude.h"
#include "TimeMgr.h"


CTimeMgr::CTimeMgr()
{
}


CTimeMgr::~CTimeMgr()
{
}

void CTimeMgr::SetTime()
{
	QueryPerformanceCounter(&m_InvaliTime);

	if (m_InvaliTime.QuadPart - m_LastTime.QuadPart > m_CpuTick.QuadPart)
	{
		QueryPerformanceFrequency(&m_CpuTick);
		m_LastTime = m_InvaliTime;
	}

	m_fTime = float(m_InvaliTime.QuadPart - m_FixTime.QuadPart) / m_CpuTick.QuadPart;
	m_FixTime = m_InvaliTime;
}

void CTimeMgr::InitTimeMgr()
{
	// 1초에 cpu가 카운팅하는 숫자
	QueryPerformanceFrequency(&m_CpuTick);

	// 현재 cpu가 카운팅한 숫자
	// GetTickCount
	QueryPerformanceCounter(&m_LastTime);
	QueryPerformanceCounter(&m_InvaliTime);
	QueryPerformanceCounter(&m_FixTime);
}
