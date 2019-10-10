#pragma once
class CUI;
class C2DMouse
{
public:
	C2DMouse();
	~C2DMouse();
private:
	POINT			m_GetCur;
public:
	void Initialize();
	void Progress();

public:
	CUI* IsInImage(vector<CUI*> vecUI);
	
};
