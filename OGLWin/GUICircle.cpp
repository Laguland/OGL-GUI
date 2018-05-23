#include "GUICircle.h"


GUICircle::GUICircle(Vector2D circleCentre, int numSegments, float size, bool isFilled)
{
	m_CircleCentre = circleCentre;
	m_NumSegments = numSegments;
	m_Size = size;
	m_isFilled = isFilled;
}


GUICircle::~GUICircle()
{
}

void GUICircle::IsFilled(bool value)
{
	m_isFilled = value;
}

void GUICircle::SetCircleCentre(Vector2D newCentre)
{
	m_CircleCentre = newCentre;
}

float GUICircle::GetCentreX()
{
	return m_CircleCentre.GetX();
}

void GUICircle::SetCentreX(float newX)
{
	m_CircleCentre.SetX(newX);
}

bool GUICircle::IsMouseInside(int x, int y)
{
	if (x >= (m_CircleCentre.GetX() - m_Size) &&
		x <= (m_CircleCentre.GetX() + m_Size) &&
		y >= (m_CircleCentre.GetY() - m_Size) &&
		y <= (m_CircleCentre.GetY() + m_Size))
	{
		if (m_Size <= sqrt(pow(x,2) + pow(y,2)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void GUICircle::Render()
{
	if (m_isFilled)
	{
		glBegin(GL_TRIANGLE_FAN); // Green color circle
		for (int i = 0; i < m_NumSegments; i++)
		{
			theta = 2.0f * 3.1415926f * float(i) / m_NumSegments; //get the current angle 

			x = m_Size * cosf(theta); //calculate the x component 
			y = m_Size * sinf(theta); //calculate the y component 

			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex2f(x + m_CircleCentre.GetX(), y + m_CircleCentre.GetY()); //output vertex 
		}
		glEnd();
	}
	else
	{
		glBegin(GL_LINE_LOOP); // Green color circle
		for (int i = 0; i < m_NumSegments; i++)
		{
			theta = 2.0f * 3.1415926f * float(i) / m_NumSegments; //get the current angle 

			x = m_Size * cosf(theta); //calculate the x component 
			y = m_Size * sinf(theta); //calculate the y component 

			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex2f(x + m_CircleCentre.GetX(), y + m_CircleCentre.GetY()); //output vertex 
		}
		glEnd();
	}
}