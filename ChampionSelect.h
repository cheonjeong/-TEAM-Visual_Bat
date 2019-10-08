#pragma once
class CChampionSelect
{
public:
	CChampionSelect();
	~CChampionSelect();
private:
	D3DXIMAGE_INFO							m_stImageInfo;
	LPD3DXSPRITE							m_pSprite;
	LPDIRECT3DTEXTURE9						m_pTexture;
	
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();

public:
	explicit CChampionSelect(LPCWSTR	ChampFile, D3DXVECTOR3 pos);
private:
	LPCWSTR									m_ChampFile;
	D3DXVECTOR3								m_vPosition;
public:
	D3DXIMAGE_INFO	GetImageInfo() { return m_stImageInfo; }
	D3DXVECTOR3	GetPos() { return m_vPosition; }
private:
	RECT							m_rc;
public:
	RECT	GetRect() { return m_rc; }

private:
	D3DXVECTOR3							m_Center;
};

