#pragma once
#include "UI.h"

class CImage_Loader;
class CSpell_ :
	public CUI
{
public:
	CSpell_(string name, LPCWSTR FileName, D3DXVECTOR3 pos);
	~CSpell_();
public:
	void Initialize() override;
	void Render(D3DXVECTOR3 scale) override;
private:
	D3DXVECTOR3				m_vPosition;
	string					m_name;
	LPCWSTR					m_FileName;
	RECT					m_Rect;
public:
	D3DXVECTOR3 GetPosition() { return m_vPosition; }
private:
	CImage_Loader*				m_ImageLoader;
public:
	RECT GetRect() override { return m_Rect; }
	string GetName() override { return m_name; }
};

