#include "BaseInclude.h"
#include "Spell_.h"
#include "Image_Loader.h"


CSpell_::CSpell_(string name, LPCWSTR FileName, D3DXVECTOR3 pos)
	:m_name(name)
	, m_FileName(FileName)
	, m_vPosition(pos)
{
}


CSpell_::~CSpell_()
{
}

void CSpell_::Initialize()
{
	m_ImageLoader = new CImage_Loader(m_FileName);
	m_ImageLoader->Initialize();
	m_Rect.left = m_vPosition.x;
	m_Rect.top = m_vPosition.y;
	m_Rect.right = m_vPosition.x + m_ImageLoader->GetImageInfo().Width;
	m_Rect.bottom = m_vPosition.y + m_ImageLoader->GetImageInfo().Height;
}

void CSpell_::Render(D3DXVECTOR3 scale)
{
	m_ImageLoader->Render(m_vPosition, scale);
}
