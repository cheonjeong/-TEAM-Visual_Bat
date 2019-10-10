#pragma once
class CImage_Loader
{
public:
	CImage_Loader();
	~CImage_Loader();
	explicit CImage_Loader(LPCWSTR FileName);
public:
	virtual void Initialize();
	virtual void Render(D3DXVECTOR3 scale);
	virtual void Render(D3DXVECTOR3 pos, D3DXVECTOR3 scale);


protected:
	LPD3DXSPRITE					m_pSprite;
	PDIRECT3DTEXTURE9				m_pTexture;
	D3DXIMAGE_INFO					m_ImageInfo;
	RECT							m_Rect;
	LPCWSTR							m_FileName;
public:
	RECT GetRect() { return m_Rect; }
	LPCWSTR	GetFileName() { return m_FileName; }
	D3DXIMAGE_INFO	GetImageInfo() { return m_ImageInfo; }
};

