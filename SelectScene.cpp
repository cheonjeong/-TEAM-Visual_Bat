#include "BaseInclude.h"
#include "SelectScene.h"
#include "ChampionSelect.h"
#include "C2DMouse.h"
#include "SpellSelect.h"
#include "AbilityPage.h"


CSelectScene::CSelectScene()
	:m_p2Dmouse(NULL), m_ChampionRender(NULL)
	, m_pSpellSelect_1(NULL), m_pSpellSelect_2(NULL)
{
	m_vecSpellList.reserve(2);
}


CSelectScene::~CSelectScene()
{
}

HRESULT CSelectScene::Initialize()
{
	m_p2Dmouse = new C2DMouse;
	
	Champ_Initialize();
	Spell_Initialize();

	/*m_page = new CAbilityPage;
	m_page->Initialize();*/
	

	return E_NOTIMPL;
}
void CSelectScene::Progress()
{
	m_p2Dmouse->Progress();
	if (GetAsyncKeyState(VK_LBUTTON) & 0X8000)
	{
		MouseChampionCheck();
		MouseSpellCheck();
	}
}

void CSelectScene::Render()
{
	Champ_Render();
	Spell_Render();

	//m_page->Render();
}

void CSelectScene::Release()
{
}

void CSelectScene::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}

void CSelectScene::MouseChampionCheck()
{
	string ReturnName;
	ReturnName = m_p2Dmouse->IsInImage(m_mapChampionList);
	if (ReturnName != "")
		m_ChampionRender = m_CircleChampImage[ReturnName];
}

void CSelectScene::MouseSpellCheck()
{
	for (int i = 0; i < m_vecSpellList.size(); i++)
	{
		if(m_vecSpellList[i]->Getpos() == D3DXVECTOR3(537, 737, 0))				m_pSpellSelect_1 = m_p2Dmouse->IsInImage(m_vecSpellList);
		else if(m_vecSpellList[i]->Getpos() == D3DXVECTOR3(575, 737, 0))		m_pSpellSelect_2 = m_p2Dmouse->IsInImage(m_vecSpellList);
	}
}

void CSelectScene::Champ_Initialize()
{
	//Champion
	{
		{//Champion Image
		 //이미지 객체 만들때 객체간의 거리 x = 70, y = 70

			CChampionSelect*		pGaren;
			pGaren = new CChampionSelect(L"Resource/choen/ChampImage/Garen/Garen_Square.dds", D3DXVECTOR3(363, 152, 0));

			if (pGaren)
				m_mapChampionList["Garen"] = pGaren;


			CChampionSelect*		pAatrox;
			pAatrox = new CChampionSelect(L"Resource/choen/ChampImage/Atrox/Aatrox_Square.dds", D3DXVECTOR3(446, 152, 0));

			if (pAatrox)
				m_mapChampionList["Aatrox"] = pAatrox;
		}
		//Circle Image;
		{
			D3DXVECTOR3	pickpos = D3DXVECTOR3(95, 200, 0);// 고정위치
			CChampionSelect*	pCircleGaren;
			pCircleGaren = new CChampionSelect(L"Resource/choen/ChampImage/Garen/Garen_Circle.dds", pickpos);
			if (pCircleGaren)
				m_CircleChampImage["Garen"] = pCircleGaren;


			CChampionSelect*	pCircleAatox;
			pCircleAatox = new CChampionSelect(L"Resource/choen/ChampImage/Atrox/Aatrox_Circle.dds", pickpos);
			if (pCircleAatox)
				m_CircleChampImage["Aatrox"] = pCircleAatox;
		}
	}

	//Champion
	{
		//Champion square Image list
		for (auto it = m_mapChampionList.begin(); it != m_mapChampionList.end(); it++)
			it->second->Initialize();

		//Champion Circle Image List
		for (auto it = m_CircleChampImage.begin(); it != m_CircleChampImage.end(); it++)
			it->second->Initialize();
	}
}

void CSelectScene::Champ_Render()
{
	//챔피언 선택 이미지
	for (auto it = m_mapChampionList.begin(); it != m_mapChampionList.end(); ++it)
	{
		if (it->second != NULL)
			it->second->Render();
	}

	//챔피언 선택 후 내 챔피언 이미지
	if (m_ChampionRender)
		m_ChampionRender->Render();
}

void CSelectScene::Spell_Initialize()
{
	{
		m_vecSpellList.resize(9);

		{
			D3DXVECTOR3 pos_01 = D3DXVECTOR3(480, 503, 0);
			D3DXVECTOR3 pos_02 = D3DXVECTOR3(530, 503, 0);
			D3DXVECTOR3 pos_03 = D3DXVECTOR3(580, 503, 0);
			D3DXVECTOR3 pos_04 = D3DXVECTOR3(630, 503, 0);
			D3DXVECTOR3 pos_05 = D3DXVECTOR3(480, 570, 0);
			D3DXVECTOR3 pos_06 = D3DXVECTOR3(530, 570, 0);
			D3DXVECTOR3 pos_07 = D3DXVECTOR3(580, 570, 0);
			D3DXVECTOR3 pos_08 = D3DXVECTOR3(630, 570, 0);
			D3DXVECTOR3 pos_09 = D3DXVECTOR3(480, 640, 0);

			m_vecSpellList[0] = new CSpellSelect(L"Resource/choen/Spell_Image/gangta.dds", pos_01);
			m_vecSpellList[1] = new CSpellSelect(L"Resource/choen/Spell_Image/gangta.dds", pos_02);
			m_vecSpellList[2] = new CSpellSelect(L"Resource/choen/Spell_Image/gangta.dds", pos_03);
			m_vecSpellList[3] = new CSpellSelect(L"Resource/choen/Spell_Image/gangta.dds", pos_04);
			m_vecSpellList[4] = new CSpellSelect(L"Resource/choen/Spell_Image/gangta.dds", pos_05);
			m_vecSpellList[5] = new CSpellSelect(L"Resource/choen/Spell_Image/gangta.dds", pos_06);
			m_vecSpellList[6] = new CSpellSelect(L"Resource/choen/Spell_Image/gangta.dds", pos_07);
			m_vecSpellList[7] = new CSpellSelect(L"Resource/choen/Spell_Image/gangta.dds", pos_08);
			m_vecSpellList[8] = new CSpellSelect(L"Resource/choen/Spell_Image/gangta.dds", pos_09);
		}
	}
	
	for (int i = 0; i < m_vecSpellList.size(); i++)
		m_vecSpellList[i]->Initialize();

	m_pSpellSelect_1 = new CSpellSelect(L"Resource/choen/Spell_Image/gangta.dds", D3DXVECTOR3(10, 10, 0));
	m_pSpellSelect_2 = new CSpellSelect(L"Resource/choen/Spell_Image/gangta.dds", D3DXVECTOR3(60, 60, 0));

	m_pSpellSelect_1->Initialize();
	m_pSpellSelect_2->Initialize();
}

void CSelectScene::Spell_Render()
{
	for (int i = 0; i < m_vecSpellList.size(); i++)
		m_vecSpellList[i]->Render();

	if (m_pSpellSelect_1)
	{
		m_pSpellSelect_1->Render(D3DXVECTOR3(537, 737, 0));
		m_pSpellSelect_1->Render(D3DXVECTOR3(35, 200, 0));
	}

	if (m_pSpellSelect_2)
	{
		m_pSpellSelect_2->Render(D3DXVECTOR3(575, 737, 0));
		m_pSpellSelect_2->Render(D3DXVECTOR3(35, 235, 0));
	}
}