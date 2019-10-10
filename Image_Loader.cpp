#include "BaseInclude.h"
#include "Image_Loader.h"


CImage_Loader::CImage_Loader()
{
}


CImage_Loader::~CImage_Loader()
{
}

CImage_Loader::CImage_Loader(LPCWSTR FileName)
	: m_pSprite(NULL), m_pTexture(NULL), m_FileName(FileName)
{
}

void CImage_Loader::Initialize()
{
	D3DXCreateSprite(GetDevice(), &m_pSprite);

	D3DXCreateTextureFromFileEx(
		GetDevice(),
		m_FileName,
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
}

void CImage_Loader::Render(D3DXVECTOR3 scale)
{
	
}

void CImage_Loader::Render(D3DXVECTOR3 pos, D3DXVECTOR3 scale)
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	D3DXMATRIXA16	matT, matR, matS, matWorld;

	D3DXMatrixScaling(&matS, scale.x, scale.y, scale.z);
	D3DXMatrixTranslation(&matT, pos.x, pos.y, 0);

	m_Rect.left = pos.x;
	m_Rect.top = pos.y;
	m_Rect.right = pos.x + m_ImageInfo.Width * scale.x;
	m_Rect.bottom = pos.y + m_ImageInfo.Height * scale.x;

	matWorld = matS * matT;

	m_pSprite->SetTransform(&matWorld);

	

	RECT rc;
	SetRect(&rc, 0, 0, m_ImageInfo.Width, m_ImageInfo.Height);

	m_pSprite->Draw(m_pTexture, &rc, NULL,
		NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	m_pSprite->End();
}