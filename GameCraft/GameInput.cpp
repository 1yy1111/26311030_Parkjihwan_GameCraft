#include "GameInput.h"
#include <glc2d.h>

int GameInput::Init()
{
	m_moveLeft = false;
	m_moveRight = false;
	m_shootPressed = false;
	m_enterPressed = false;
	m_escPressed = false;

	return 0;
}

int GameInput::Update()
{
	const KEYCODE* key{ g2_GetKeyboard() };

	m_moveLeft =
		(EINPUT_DOWN == key[VK_LEFT] || EINPUT_PRESS == key[VK_LEFT]) ||
		(EINPUT_DOWN == key['A'] || EINPUT_PRESS == key['A']);

	m_moveRight =
		(EINPUT_DOWN == key[VK_RIGHT] || EINPUT_PRESS == key[VK_RIGHT]) ||
		(EINPUT_DOWN == key['D'] || EINPUT_PRESS == key['D']);

	m_shootPressed = (EINPUT_DOWN == g2_GetMouseEvent(0));

	m_enterPressed = (EINPUT_DOWN == key[VK_RETURN]);

	m_escPressed = (EINPUT_DOWN == key[VK_ESCAPE]);

	return 0;

}

bool GameInput::IsMoveLeft() const
{
	return m_moveLeft;
}

bool GameInput::IsMoveRight() const
{
	return m_moveRight;
}

bool GameInput::IsShootPressed() const
{
	return m_shootPressed;
}

bool GameInput::IsEnterPressed() const
{
	return m_enterPressed;
}

bool GameInput::IsEscPressed() const
{
	return m_escPressed;
}
