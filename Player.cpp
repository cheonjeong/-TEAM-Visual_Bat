#include "BaseInclude.h"
#include"ObjMgr.h"
#include "Player.h"
#include"MathMgr.h"
#include"Mouse.h"
#include"PipeLine.h"
CPlayer::CPlayer()
	:m_fCamDistance(1.f)
	
{
	m_fAngle[0] = 0.0f;		m_fAngle[1] = 0.0f;		m_fAngle[2] = 0.0f;

}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::KeyCheck()
{
	if (CheckPushKey(DIK_UP))
	{
		m_Info.vPos += m_Info.vDir * 0.007f;
	}

	if (CheckPushKey(DIK_DOWN))
	{
		m_Info.vPos -= m_Info.vDir * 0.007f;
	}

	// Y��ȸ��
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_fAngle[ANGLE_Y] += 0.001f;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_fAngle[ANGLE_Y] -= 0.001f;
	}
}

void CPlayer::MouseCheck()
{
	DIMOUSESTATE		MouseState = MyGetMouseState();

	if (MouseState.rgbButtons[0] & 0x80)
	{
		if (GET_SINGLE(CMouse)->CollisionMouseToTerrain())
		{
			m_vMousePos = *(GET_SINGLE(CMouse)->GetMousePos());

			m_bMove = true;
		}
	}

	if (MouseState.lX)
	{
		if (MouseState.rgbButtons[2])
			return;

		m_fAngle[ANGLE_Y] += D3DXToRadian(MouseState.lX / 5.0f);
	}
}

void CPlayer::SetCameraPos()
{

}

void CPlayer::SetContantTable()
{

	//LPD3DXEFFECT pEffect = GET_SINGLE(CShaderMgr)->GetEffect(EFFECTTYPE_OBJECT);

	D3DXMATRIX		matView, matProj;
	GetTransform(D3DTS_VIEW, &matView);
	GetTransform(D3DTS_PROJECTION, &matProj);

	//pEffect->SetMatrix("matWorld", &m_Info.matWorld);
	//pEffect->SetMatrix("matView", &matView);
	//pEffect->SetMatrix("matProj", &matProj);
}

HRESULT CPlayer::Initialize()
{
	m_SortID = SORTID_NORMAL;
	m_Info.vLook = D3DXVECTOR3(0.f, 0.f, 1.0f);
	m_Info.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_Info.vPos = D3DXVECTOR3(1.f, 0.f, 1.f);

	m_fCamDistance = 10.f;

	m_pOriVtx = new VTXTEX[4];
	m_pConVtx = new VTXTEX[4];
	CopyVertexInfo(L"RectTxture", m_pOriVtx);
	D3DXMatrixIdentity(&m_Info.matWorld);
	CloneMesh(GetDevice(), L"Map", &m_pAnimationCtrl);

	m_vMin = *(GetMin(BOUNDTYPE_CUBE));
	m_vMax = *(GetMax(BOUNDTYPE_CUBE));
	return S_OK;
}

void CPlayer::Progress()
{
	//const VTXTEX* pTerrianVtx = (*(CObjMgr::GetInstance()))->GetVtxInfo(L"Terrain");
	//m_Info.vPos.y = CMathMgr::GetHeight(pTerrianVtx, &m_Info.vPos);
	D3DXMATRIX matRotX, matRotY, matRotZ, matTrans;
	D3DXMatrixRotationX(&matRotX, m_fAngle[ANGLE_X]);
	D3DXMatrixRotationY(&matRotY, m_fAngle[ANGLE_Y]);
	D3DXMatrixRotationZ(&matRotZ, m_fAngle[ANGLE_Z]);
	D3DXMatrixTranslation(&matTrans, m_Info.vPos.x, m_Info.vPos.y, m_Info.vPos.z);

	m_Info.matWorld = matRotX*matRotY*matRotZ*matTrans;
	CPipeLine::MyVec3TransformNormal(&m_Info.vDir, &m_Info.vLook, &m_Info.matWorld);
	KeyCheck();
	//MouseCheck();
	SetCameraPos();
	if (m_bMove)
	{
		m_bMove = Move_Chase(&m_vMousePos, 5.0f);
	}
}

void CPlayer::Render()
{
	SetTransform(D3DTS_WORLD, &m_Info.matWorld);

	//��� �ִϸ��̼��� ������ ���� �����Ѵ�.
//	m_pAnimationCtrl->SetAnimationSet(9);
//
//	m_pAnimationCtrl->FrameMove(L"amumu", GetTime());

	Mesh_Render(GetDevice(), L"Map");
}

void CPlayer::Release()
{

}