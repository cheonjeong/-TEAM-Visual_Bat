#include "BaseInclude.h"
#include "AbilityPage.h"
#include "AbilityImage.h"


CAbilityPage::CAbilityPage()
{
}


CAbilityPage::~CAbilityPage()
{
}

void CAbilityPage::Initialize()
{
	ImageLoad_To_Detailed();
	ImageLoad_To_Control();
	ImageLoad_To_BrainStorm();
	ImageLoad_To_Masic();
	ImageLoad_To_Resolution();
}
void CAbilityPage::Progress()
{
	
}

void CAbilityPage::Render()
{
	ImageRender_To_Detailed();
	ImageRender_To_Control();
	ImageRender_To_BrainStorm();
	ImageRender_To_Masic();
	ImageRender_To_Resolution();	
}

void CAbilityPage::Release()
{
}

void CAbilityPage::ImageLoad_To_Detailed()
{
	CAbilityImage*	Main = new CAbilityImage;
	Main->Initialize(L"Resource/cheon/Runepage/정밀/Main.png");
	m_mapDetailedRune["Main"] = Main;

	CAbilityImage*	Press_the_Attack_rune = new CAbilityImage;
	Press_the_Attack_rune->Initialize(L"Resource/cheon/Runepage/정밀/Press_the_Attack_rune.png");
	m_mapDetailedRune["Press_the_Attack_rune"] = Press_the_Attack_rune;
}

void CAbilityPage::ImageLoad_To_Control()
{
	CAbilityImage*	Main = new CAbilityImage;
	Main->Initialize(L"Resource/cheon/Runepage/지배/Main.png");
	m_mapContolRune["Main"] = Main;
}

void CAbilityPage::ImageLoad_To_BrainStorm()
{
	CAbilityImage*	Main = new CAbilityImage;
	Main->Initialize(L"Resource/cheon/Runepage/영감/Main.png");
	m_mapBrainStormRune["Main"] = Main;
}

void CAbilityPage::ImageLoad_To_Masic()
{
	CAbilityImage*	Main = new CAbilityImage;
	Main->Initialize(L"Resource/cheon/Runepage/마법/Main.png");
	m_mapMasicRune["Main"] = Main;
}

void CAbilityPage::ImageLoad_To_Resolution()
{
	CAbilityImage*	Main = new CAbilityImage;
	Main->Initialize(L"Resource/cheon/Runepage/결의/Main.png");
	m_mapResolutionRune["Main"] = Main;
}

void CAbilityPage::ImageRender_To_Detailed()
{
	m_mapDetailedRune["Main"]->Main_Render(D3DXVECTOR3(200, 200, 0));
	m_mapDetailedRune["Press_the_Attack_rune"]->Render(D3DXVECTOR3(150, 250, 0));
}

void CAbilityPage::ImageRender_To_Control()
{
	m_mapContolRune["Main"]->Main_Render(D3DXVECTOR3(350, 200, 0));
}

void CAbilityPage::ImageRender_To_BrainStorm()
{
	m_mapBrainStormRune["Main"]->Main_Render(D3DXVECTOR3(500, 200, 0));
}

void CAbilityPage::ImageRender_To_Masic()
{
	m_mapMasicRune["Main"]->Main_Render(D3DXVECTOR3(650, 200, 0));
}

void CAbilityPage::ImageRender_To_Resolution()
{
	m_mapResolutionRune["Main"]->Main_Render(D3DXVECTOR3(800, 200, 0));
}
