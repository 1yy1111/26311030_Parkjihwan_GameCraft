#pragma once

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

private:
	bool m_moveLeft		{};
	bool m_moveRight	{};
	bool m_shootPressed	{};
	bool m_enterPressed	{};
	bool m_escPressed	{};
};