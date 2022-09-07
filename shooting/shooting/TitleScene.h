#pragma once

#include "Scene.h"
#include "BBasicSys.h"

class TitleScene : public Scene
{
public:
	TitleScene();
	virtual ~TitleScene();

public:
	void Init() override;
	void Update(float deltaTime) override;
	void Render(HDC hdc, float deltaTime) override;
	void Release() override;

private:
	POINT m_StartBtnPos; //시작버튼의 위치
	RECT m_StartBtnRect; //시작버튼의 사각형 =>이건 나중에 Button등의 클래스로 해주면 더 좋다.

};

