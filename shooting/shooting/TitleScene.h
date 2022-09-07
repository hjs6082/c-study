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
	POINT m_StartBtnPos; //���۹�ư�� ��ġ
	RECT m_StartBtnRect; //���۹�ư�� �簢�� =>�̰� ���߿� Button���� Ŭ������ ���ָ� �� ����.

};

