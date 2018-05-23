#include "GUITickBox.h"


GUITickBox::GUITickBox(Vector2D positionTL, Vector2D positionBR, bool boolStatus)
{
	m_PositionTL = positionTL;
	m_PositionBR = positionBR;
	isTicked = boolStatus;
}

GUITickBox::~GUITickBox()
{
}

void GUITickBox::SetBoolValue(bool value)
{
	isTicked = value;
}

bool GUITickBox::IsMouseInside(int x, int y)
{
	if (x >= m_PositionTL.GetX() &&
		x <= m_PositionBR.GetX() &&
		y >= m_PositionBR.GetY() &&
		y <= m_PositionTL.GetY())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GUITickBox::Drag(int x, int y)
{
	m_PositionTL.SetX(m_PositionTL.GetX() + x);
	m_PositionTL.SetY(m_PositionTL.GetY() - y);
	m_PositionBR.SetX(m_PositionBR.GetX() + x);
	m_PositionBR.SetY(m_PositionBR.GetY() - y);
}

bool GUITickBox::IsTicked()
{
	if (isTicked)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GUITickBox::Render()
{
	if (isTicked)
	{
		glBegin(GL_LINE_LOOP);

		glVertex2f(m_PositionTL.GetX(), m_PositionTL.GetY());
		glVertex2f(m_PositionTL.GetX(), m_PositionBR.GetY());
		glVertex2f(m_PositionBR.GetX(), m_PositionBR.GetY());
		glVertex2f(m_PositionBR.GetX(), m_PositionTL.GetY());

		glEnd();

		glBegin(GL_LINE_STRIP);

		glVertex2f(m_PositionBR.GetX(), m_PositionBR.GetY());
		glVertex2f(m_PositionTL.GetX(), m_PositionTL.GetY());

		glEnd();

		glBegin(GL_LINE_STRIP);

		glVertex2f(m_PositionTL.GetX(), m_PositionBR.GetY());
		glVertex2f(m_PositionBR.GetX(), m_PositionTL.GetY());

		glEnd();
	}
	else
	{
		glBegin(GL_LINE_LOOP);

		glVertex2f(m_PositionTL.GetX(), m_PositionTL.GetY());
		glVertex2f(m_PositionTL.GetX(), m_PositionBR.GetY());
		glVertex2f(m_PositionBR.GetX(), m_PositionBR.GetY());
		glVertex2f(m_PositionBR.GetX(), m_PositionTL.GetY());

		glEnd();
	}
}
