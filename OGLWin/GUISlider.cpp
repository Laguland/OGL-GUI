#include "GUISlider.h"



GUISlider::GUISlider(Vector2D position, float length, const char* label, Vector2D labelPosition, int textSize)
{
	m_Position = position;
	m_Length = length;
	m_Label = label;
	m_LabelPosition = labelPosition;
	m_IsLabel = true;
	m_CircleCentre = position;

	m_pCircle = new GUICircle(position, 20, 5.0f, true);
	m_pText = new GUIText(labelPosition, textSize, label);
}

GUISlider::GUISlider(Vector2D position, float length)
{
	m_Position = position;
	m_Length = length;
	m_IsLabel = false;

	m_pCircle = new GUICircle(position, 20, 5.0f, true);
}

GUISlider::~GUISlider()
{
	delete m_pCircle;
	delete m_pText;
}


void GUISlider::Drag(int x, int y)
{
	m_Position.SetX(m_Position.GetX() + x);
	m_Position.SetY(m_Position.GetY() - y);
	m_LabelPosition.SetX(m_LabelPosition.GetX() + x);
	m_LabelPosition.SetY(m_LabelPosition.GetY() - y);
	m_CircleCentre.SetX(m_CircleCentre.GetX() + x);
	m_CircleCentre.SetY(m_CircleCentre.GetY() - y);
	m_pCircle->SetCircleCentre(m_CircleCentre);
	m_pText->SetPosition(m_LabelPosition);
}

void GUISlider::DragCircleX(int x)
{
	if (m_pCircle->GetCentreX() + x <= (m_Position.GetX() + m_Length) && 
		m_pCircle->GetCentreX() + x >= m_Position.GetX())
	{
		m_CircleCentre.SetX(m_CircleCentre.GetX() + x);
		m_pCircle->SetCircleCentre(m_CircleCentre);
	}
}

void GUISlider::SetCirclePosition(float newPosition) // niepotrzebne
{
	if (newPosition <= (m_Position.GetX() + m_Length) &&
		newPosition >= m_Position.GetX())
	{
		m_pCircle->SetCentreX(newPosition);
	}
}

float GUISlider::GetCirclePositionX()
{
	return m_pCircle->GetCentreX();
}

float GUISlider::GetRatio()
{
	m_RatioValue = m_pCircle->GetCentreX() - m_Position.GetX();
	if (m_RatioValue != 0)
	{
		return m_RatioValue / m_Length;
	}
	else
	{
		return 0;
	}
}

bool GUISlider::IsMouseInside(int x, int y)
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

void GUISlider::Render()
{
	if (m_IsLabel)
	{
		glBegin(GL_LINE_STRIP); // Draw Line

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(m_Position.GetX(), m_Position.GetY());
		glVertex2f(m_Position.GetX() + m_Length, m_Position.GetY());

		glEnd();

		// Draw Circle

		m_pCircle->Render();
		m_pText->Render();
	}
	else
	{
		glBegin(GL_LINE_STRIP); // Draw Line

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(m_Position.GetX(), m_Position.GetY());
		glVertex2f(m_Position.GetX() + m_Length, m_Position.GetY());

		glEnd();

		// Draw Circle

		m_pCircle->Render();
	}
}

void GUISlider::SetFontSize(int value)
{
	m_pText->SetSize(value);
}
