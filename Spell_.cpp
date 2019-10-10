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
}

void CSpell_::Render(D3DXVECTOR3 scale)
{
	m_ImageLoader->Render(m_vPosition, scale);
}
