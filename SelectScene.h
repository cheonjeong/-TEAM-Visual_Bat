#pragma once
#include "Scene.h"

class CChampionSelect;
class CAbilityPage;
class CSpellSelect;
class C2DMouse;

class CSelectScene :
	public CScene
{
public:
	CSelectScene();
	~CSelectScene();

public:
	HRESULT Initialize() override;
	void Progress() override;
	void Render() override;
	void Release() override;
private:
	C2DMouse*					m_p2Dmouse;
	bool m_bView;

private:
	void WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) override;

private:// Champion map
	map<string, CChampionSelect*>			m_mapChampionList;
	map<string, CChampionSelect*>			m_CircleChampImage;
	void MouseChampionCheck();
	CChampionSelect*				m_ChampionRender;

private://Ability map
	map<string, CAbilityPage*>			m_mapAbilityList;

private://Spell map
	vector<CSpellSelect*>				m_vecSpellList;
	CSpellSelect*						m_pSpellSelect_1;
	CSpellSelect*						m_pSpellSelect_2;


	void MouseSpellCheck();

private:
	void Champ_Initialize();
	void Champ_Render();

	void Spell_Initialize();
	void Spell_Render();

private:
	CAbilityPage*						m_page;
};

