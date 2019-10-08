#include "BaseInclude.h"
#include "ChampionSelect.h"


CChampionSelect::CChampionSelect()
	: m_pSprite(NULL)
	, m_pTexture(NULL)
{
}
CChampionSelect::CChampionSelect(LPCWSTR ChampFile, D3DXVECTOR3 pos)
	:m_ChampFile(ChampFile), m_vPosition(pos)
{

}



CChampionSelect::~CChampionSelect()
{
}

void CChampionSelect::Initialize()
{
	D3DXCreateSprite(GetDevice(), &m_pSprite);

	D3DXCreateTextureFromFileEx(
		GetDevice(),
		m_ChampFile,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_DEFAULT,
		0,
		&m_stImageInfo,
		NULL,
		&m_pTexture
	);
	m_rc.left =   m_vPosition.x;
	m_rc.top =    m_vPosition.y;
	m_rc.right =  m_vPosition.x + m_stImageInfo.Width;
	m_rc.bottom = m_vPosition.y + m_stImageInfo.Height;
}

void CChampionSelect::Progress()
{

}

void CChampionSelect::Render()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	D3DXMATRIXA16	matT, matR, matS, matWorld;

	D3DXMatrixScaling(&matS, 0.5f, 0.5f, 0.5f);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, 0);
	
	matWorld = matS * matT;

	m_pSprite->SetTransform(&matWorld);

	RECT rc;
	SetRect(&rc, 0, 0, m_stImageInfo.Width, m_stImageInfo.Height);

	m_pSprite->Draw(m_pTexture, &rc, NULL, 
		NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	//Rectangle(GetDC(g_hWnd), m_rc.left, m_rc.top, m_rc.right, m_rc.bottom);
	m_pSprite->End();
}

void CChampionSelect::Release()
{
}

