#include "GUIButton.h"
#include <Windows.h>
#include <gl/GL.h>

GUIButton::GUIButton(Vector2D topLeft, Vector2D bottomRight, float red, float green, float blue)
{
	m_TopLeft = topLeft;
	m_BottomRight = bottomRight;
	m_Red = red;
	m_Green = green;
	m_Blue = blue;
}

GUIButton::~GUIButton()
{
}


bool GUIButton::IsMouseInside(int x, int y)
{
	if (x >= m_TopLeft.GetX() &&
		x <= m_BottomRight.GetX() &&
		y >= m_BottomRight.GetY() &&
		y <= m_TopLeft.GetY())
	{
		return true;
	}
	else
	{
		return false;
	}
}
void GUIButton::Drag(int x, int y)
{
	m_TopLeft.SetX(m_TopLeft.GetX() + x);
	m_TopLeft.SetY(m_TopLeft.GetY() - y);
	m_BottomRight.SetX(m_BottomRight.GetX() + x);
	m_BottomRight.SetY(m_BottomRight.GetY() - y);
}
void GUIButton::SetTopLeft(Vector2D topLeft)
{
	m_TopLeft = topLeft;
}

void GUIButton::SetBottomRight(Vector2D bottomRight)
{
	m_BottomRight = bottomRight;
}

void GUIButton::SetRed(float red)
{
	m_Red = red;
}

void GUIButton::SetGreen(float green)
{
	m_Green = green;
}

void GUIButton::SetBlue(float blue)
{
	m_Blue = blue;
}

Vector2D GUIButton::GetTopLeft()
{
	return m_TopLeft;
}

Vector2D GUIButton::GetBottomRight()
{
	return m_BottomRight;
}

float GUIButton::GetRed()
{
	return m_Red;
}

float GUIButton::GetGreen()
{
	return m_Green;
}

float GUIButton::GetBlue()
{
	return m_Blue;
}

void GUIButton::Render()
{
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(m_Red, m_Green, m_Blue);
	glVertex2f(m_TopLeft.GetX(), m_BottomRight.GetY());
	glVertex2f(m_BottomRight.GetX(), m_BottomRight.GetY());
	glVertex2f(m_TopLeft.GetX(), m_TopLeft.GetY());
	glVertex2f(m_BottomRight.GetX(), m_TopLeft.GetY());

	glEnd();
}