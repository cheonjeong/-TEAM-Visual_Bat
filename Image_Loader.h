#pragma once
class CImage_Loader
{
public:
	CImage_Loader();
	~CImage_Loader();
	explicit CImage_Loader(LPCWSTR FileName, D3DXVECTOR3 pos);
public:
	void Initialize();
	void Render(D3DXVECTOR3 scale);
	void Render(D3DXVECTOR3 pos, D3DXVECTOR3 scale);


private:
	LPD3DXSPRITE					m_pSprite;
	PDIRECT3DTEXTURE9				m_pTexture;
	D3DXIMAGE_INFO					m_ImageInfo;
	RECT							m_Rect;
	D3DXVECTOR3						m_vPosition;
	LPCWSTR							m_FileName;
public:
	RECT GetRect() { return m_Rect; }
	D3DXVECTOR3 Getpos() { return m_vPosition; }
};

