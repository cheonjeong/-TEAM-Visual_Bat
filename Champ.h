#pragma once
#include "UI.h"

class CImage_Loader;
class CChamp :
	public CUI
{
public:
	CChamp(string name, LPCWSTR FileName, D3DXVECTOR3 pos);
	~CChamp();
public:
	void Initialize() override;
	void Render(D3DXVECTOR3 scale) override;
private:
	D3DXVECTOR3				m_vPosition;
	string					m_name;
	LPCWSTR					m_FileName;
public:
	D3DXVECTOR3 GetPosition() { return m_vPosition; }
	string GetnName() { return m_name; }
private:
	CImage_Loader*				m_ImageLoader;
};

