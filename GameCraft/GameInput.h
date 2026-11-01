#pragma once
#include <glc2d.h>

class GameInput
{
public:
	int Init();
	int Update();

	bool IsMoveLeft() const;
	bool IsMoveRight() const;
	bool IsShootPressed() const;
	bool IsEnterPressed() const;
	bool IsEscPressed() const;

	int GetKeyState(KEYCODE keyCode) const;
	int GetMouseEvent(int nMouse) const;

private:
	bool m_moveLeft		{};
	bool m_moveRight	{};
	bool m_shootPressed	{};
	bool m_enterPressed	{};
	bool m_escPressed	{};
};

extern GameInput* GetGameInput();