#include "TitleScene.h"

TitleScene::TitleScene() : m_StartBtnPos(), m_StartBtnRect()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	m_StartBtnPos = { 150, 400 }; //��ġ ã�Ƽ� �ϵ��ڵ�
	m_StartBtnRect = {};
}

void TitleScene::Update(float deltaTime)
{
}

void TitleScene::Render(HDC hdc, float deltaTime)
{
}

void TitleScene::Release()
{
}
