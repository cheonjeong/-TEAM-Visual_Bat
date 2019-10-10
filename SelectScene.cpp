#include "BaseInclude.h"
#include "SelectScene.h"
#include "C2DMouse.h"
#include "AbilityPage.h"
#include "Image_Loader.h"
#include "Champ.h"
#include "Spell_.h"


CSelectScene::CSelectScene()
	:m_p2Dmouse(NULL)
	, m_testsuzi(NULL)
	, m_pUI(NULL)
{
	
}


CSelectScene::~CSelectScene()
{
}

HRESULT CSelectScene::Initialize()
{
	m_p2Dmouse = new C2DMouse;

	m_testsuzi = new CImage_Loader(L"Resource/choen/suzi.jpeg");
	if(m_testsuzi)	m_testsuzi->Initialize();
	
	

	m_vecChamp.push_back(new CChamp("Garen", L"Resource/choen/ChampImage/Garen/Garen_Square.dds", D3DXVECTOR3(250, 150, 0)));
	m_vecChamp.push_back(new CChamp("Aatrox", L"Resource/choen/ChampImage/Atrox/Aatrox_Square.dds", D3DXVECTOR3(350, 150, 0)));
	m_mapUI_List.insert(make_pair("Champ", &m_vecChamp));

	m_vecSpell.push_back(new CSpell_("Cleanse", L"Resource/choen/Spell_Image/Cleanse.png", D3DXVECTOR3(500, 500, 0)));
	m_mapUI_List.insert(make_pair("Spell", &m_vecSpell));
	
	
	map<string, vector<CUI*>*>::iterator iter = m_mapUI_List.begin();
	for(iter; iter != m_mapUI_List.end(); ++iter)
	{
		vector<CUI*>::iterator iter2 = (*m_mapUI_List[iter->first]).begin();
		for (iter2; iter2!=(*m_mapUI_List[iter->first]).end();++iter2)
		{
			(*iter2)->Initialize();
		}
	}

	return E_NOTIMPL;
}
void CSelectScene::Progress()
{
	m_p2Dmouse->Progress();
	if (GetAsyncKeyState(VK_LBUTTON) & 0X8000)
	{
		
	}
}

void CSelectScene::Render()
{
	if (m_testsuzi) m_testsuzi->Render(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(2.0f, 2.0f, 1.0f));

	map<string, vector<CUI*>*>::iterator iter = m_mapUI_List.begin();
	for (iter; iter != m_mapUI_List.end(); ++iter)
	{
		vector<CUI*>::iterator iter2 = (*m_mapUI_List[iter->first]).begin();
		for (iter2; iter2 != (*m_mapUI_List[iter->first]).end(); ++iter2)
		{
			(*iter2)->Render(D3DXVECTOR3(0.5f, 0.5f, 0.5f));
		}
	}
}

void CSelectScene::Release()
{
}

void CSelectScene::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}
