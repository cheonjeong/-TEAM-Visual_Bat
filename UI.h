#pragma once
class CImage_Loader;
class CUI
{
public:
	CUI();
	~CUI();
	explicit CUI(string name, LPCWSTR FileName, D3DXVECTOR3 pos);
public:
	virtual void Initialize() = 0;
	virtual void Render(D3DXVECTOR3 scale) = 0;
private:
	CImage_Loader*			m_ImageLoader;
	LPCWSTR					m_FileName;
	D3DXVECTOR3				m_vPosition;
};

