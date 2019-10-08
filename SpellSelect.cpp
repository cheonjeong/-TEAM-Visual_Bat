#include "BaseInclude.h"
#include "SpellSelect.h"


CSpellSelect::CSpellSelect()
	:m_pSprite(NULL), m_pTexture(NULL)
{
}


CSpellSelect::~CSpellSelect()
{
}

CSpellSelect::CSpellSelect(LPCWSTR SpellFile, D3DXVECTOR3 pos)
	:m_SpellFile(SpellFile), m_vPosition(pos)
{
}

void CSpellSelect::Initialize()
{
	D3DXCreateSprite(GetDevice(), &m_pSprite);

	D3DXCreateTextureFromFileEx(
		GetDevice(),
		m_SpellFile,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_DEFAULT,
		0,
		&m_ImageInfo,
		NULL,
		&m_pTexture
	);
	m_rc.left = m_vPosition.x;
	m_rc.top = m_vPosition.y;
	m_rc.right = m_vPosition.x + m_ImageInfo.Width;
	m_rc.bottom = m_vPosition.y + m_ImageInfo.Height;
}

void CSpellSelect::Render()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	D3DXMATRIXA16 matS, matR, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.5f, 0.5f, 0.5f);
	//D3DXMatrixScaling(&matS, 1.0F, 1.0F, 1.0F);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, 0);

	matWorld = matS * matT;

	m_pSprite->SetTransform(&matWorld);

	RECT rc;
	SetRect(&rc, 0, 0, m_ImageInfo.Width, m_ImageInfo.Height);
	m_pSprite->Draw(
		m_pTexture, 
		&rc, 
		NULL, 
		NULL, 
		D3DCOLOR_ARGB(255, 255, 255, 255));

	m_pSprite->End();
}

void CSpellSelect::Render(D3DXVECTOR3 pos)
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	D3DXMATRIXA16 matS, matR, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.5f, 0.5f, 0.5f);
	//D3DXMatrixScaling(&matS, 1.0F, 1.0F, 1.0F);
	D3DXMatrixTranslation(&matT, pos.x, pos.y, 0);

	matWorld = matS * matT;

	m_pSprite->SetTransform(&matWorld);

	RECT rc;
	SetRect(&rc, 0, 0, m_ImageInfo.Width, m_ImageInfo.Height);
	m_pSprite->Draw(
		m_pTexture,
		&rc,
		NULL,
		NULL,
		D3DCOLOR_ARGB(255, 255, 255, 255));

	m_pSprite->End();
}
