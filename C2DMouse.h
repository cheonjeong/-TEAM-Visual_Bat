#pragma once

class CChampionSelect;
class CSpellSelect;



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
	template<typename T>
	T IsInImage(vector<T> vecImageList);
	

public:
	template <typename T1>
	string IsInImage(map<string, T1> ImageList);
};

template<typename T>
inline T C2DMouse::IsInImage(vector<T> vecImageList)
{
	T s = 0;
	for (int i = 0; i < vecImageList.size(); i++)
	{
		if (PtInRect(&vecImageList[i]->GetRect(), m_GetCur))
		{
			return vecImageList[i];
			break;
		}
	}
	return NULL;
}

template<typename T1>
inline string C2DMouse::IsInImage(map<string, T1> ImageList)
{
	string s = "";
	for (auto it = ImageList.begin(); it != ImageList.end(); ++it)
	{
		if (PtInRect(&it->second->GetRect(), m_GetCur))
		{
			return it->first;
			break;
		}
	}
	return s;
}