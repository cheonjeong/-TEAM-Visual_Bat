#include "BaseInclude.h"
#include "C2DMouse.h"

C2DMouse::C2DMouse()
{
}


C2DMouse::~C2DMouse()
{
}

void C2DMouse::Initialize()
{
}

void C2DMouse::Progress()
{
	GetCursorPos(&m_GetCur);
	ScreenToClient(g_hWnd, &m_GetCur);
}

