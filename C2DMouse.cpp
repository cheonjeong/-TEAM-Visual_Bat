#include "BaseInclude.h"
#include "C2DMouse.h"
#include "UI.h"

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

CUI* C2DMouse::IsInImage(vector<CUI*> vecUI)
{
	for (int i = 0; i < vecUI.size(); i++)
	{
		if (PtInRect(&vecUI[i]->GetRect(), m_GetCur)) return vecUI[i];
	}
	return NULL;
}
