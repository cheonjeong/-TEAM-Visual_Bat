#pragma once
class CSpellSelect
{
public:
	CSpellSelect();
	~CSpellSelect();
public:
	explicit CSpellSelect(LPCWSTR SpellFile, D3DXVECTOR3 pos);

	void Initialize();
	void Render();

private:
	LPD3DXSPRITE						m_pSprite;
	LPDIRECT3DTEXTURE9					m_pTexture;
	D3DXIMAGE_INFO						m_ImageInfo;
private:
	LPCWSTR								m_SpellFile;
	D3DXVECTOR3							m_vPosition;
	RECT								m_rc;

public:
	RECT GetRect() { return m_rc; }
	void Render(D3DXVECTOR3 pos);
	D3DXVECTOR3 Getpos() { return m_vPosition; }
};