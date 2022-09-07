#include "TitleScene.h"

TitleScene::TitleScene() : m_StartBtnPos(), m_StartBtnRect()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	m_StartBtnPos = { 150, 400 }; //위치 찾아서 하드코딩
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
