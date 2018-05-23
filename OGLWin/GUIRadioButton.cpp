#include "GUIRadioButton.h"



GUIRadioButton::GUIRadioButton(Vector2D	buttonCentre, int circleSize, bool ticked)
{
	m_ButtonCentre = buttonCentre;
	m_CircleSize = circleSize;
	isTicked = ticked;

	m_pCircle = new GUICircle(m_ButtonCentre, 20, m_CircleSize, isTicked);
}


GUIRadioButton::~GUIRadioButton()
{
	delete m_pCircle;
}

bool GUIRadioButton::IsMouseInside(int x, int y)
{
	if (m_pCircle->IsMouseInside(x, y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GUIRadioButton::SetBoolValue(bool value)
{
	m_pCircle->IsFilled(value);
	isTicked = value;
}

void GUIRadioButton::Drag(int x, int y)
{
	m_ButtonCentre.SetX(m_ButtonCentre.GetX() + x);
	m_ButtonCentre.SetY(m_ButtonCentre.GetY() - y);
	m_pCircle->SetCircleCentre(m_ButtonCentre);
}

void GUIRadioButton::Render()
{
	m_pCircle->Render();
}
