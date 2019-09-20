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
	// 1�ʿ� cpu�� ī�����ϴ� ����
	QueryPerformanceFrequency(&m_CpuTick);

	// ���� cpu�� ī������ ����
	// GetTickCount
	QueryPerformanceCounter(&m_LastTime);
	QueryPerformanceCounter(&m_InvaliTime);
	QueryPerformanceCounter(&m_FixTime);
}
