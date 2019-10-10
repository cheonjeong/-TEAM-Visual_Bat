#include "BaseInclude.h"
#include "UI.h"
#include "Image_Loader.h"

CUI::CUI()
{
}


CUI::~CUI()
{
}

CUI::CUI(string name, LPCWSTR FileName, D3DXVECTOR3 pos)
	:m_ImageLoader(NULL)
	, m_FileName(FileName)
	, m_vPosition(pos)
{
}