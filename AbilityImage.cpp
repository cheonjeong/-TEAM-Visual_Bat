#include "BaseInclude.h"
#include "AbilityImage.h"


CAbilityImage::CAbilityImage()
{
}


CAbilityImage::~CAbilityImage()
{
}

void CAbilityImage::Initialize(LPCWSTR FileName)
{
	D3DXCreateSprite(GetDevice(), &m_pSprite);

	D3DXCreateTextureFromFileEx(
		GetDevice(),
		FileName,
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

void CAbilityImage::Main_Render(D3DXVECTOR3 RenderPosition)
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	D3DXMATRIXA16	matS, matR, matT, matWorld;
	D3DXMatrixScaling(&matS, 1.5f, 1.5f, 1.5f);
	D3DXMatrixTranslation(&matT, RenderPosition.x, RenderPosition.y, RenderPosition.z);

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

void CAbilityImage::Render(D3DXVECTOR3 RenderPosition)
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	D3DXMATRIXA16	matS, matR, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.7f, 0.7f, 0.7f);
	D3DXMatrixTranslation(&matT, RenderPosition.x, RenderPosition.y, RenderPosition.z);

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
