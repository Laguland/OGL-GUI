#pragma once

#include "Renderable.h"
#include <Windows.h>
#include <gl/GL.h>
#include "Vector2D.h"
#include <math.h>

class GUICircle : public Renderable
{
private:
	Vector2D		m_CircleCentre;
	int				m_NumSegments;
	float			m_Size;
	bool			m_isFilled;
	float			theta;
	float			x, y;

public:
					GUICircle(Vector2D circleCentre, int numSegments, float size, bool isFilled);
					~GUICircle();

	void			IsFilled(bool value);
	void			SetCircleCentre(Vector2D newCentre);
	float			GetCentreX();
	void			SetCentreX(float newX);
	bool			IsMouseInside(int x, int y);
	void			Render();
};

