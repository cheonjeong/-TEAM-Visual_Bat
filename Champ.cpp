#include "BaseInclude.h"
#include "Champ.h"
#include "Image_Loader.h"


CChamp::CChamp(string name, LPCWSTR FileName, D3DXVECTOR3 pos)
	:m_vPosition(pos), m_name(name), m_FileName(FileName)
{
	
}


CChamp::~CChamp()
{
}

void CChamp::Initialize()
{
	m_ImageLoader = new CImage_Loader(m_FileName);
	m_ImageLoader->Initialize();
	m_Rect.left = m_vPosition.x;
	m_Rect.top = m_vPosition.y;
	m_Rect.right = m_vPosition.x + m_ImageLoader->GetImageInfo().Width;
	m_Rect.bottom = m_vPosition.y + m_ImageLoader->GetImageInfo().Height;
}

void CChamp::Render(D3DXVECTOR3 scale)
{
	m_ImageLoader->Render(m_vPosition, scale);
}