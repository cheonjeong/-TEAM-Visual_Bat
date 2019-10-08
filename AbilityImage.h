#pragma once
class CAbilityImage
{
public:
	CAbilityImage();
	~CAbilityImage();
private:
	LPD3DXSPRITE						m_pSprite;
	LPDIRECT3DTEXTURE9					m_pTexture;
	D3DXIMAGE_INFO						m_ImageInfo;
	RECT								m_rc;

public:
	void Initialize(LPCWSTR	FileName);
	void Main_Render(D3DXVECTOR3 RenderPosition);
	void Render(D3DXVECTOR3 RenderPosition);

};

