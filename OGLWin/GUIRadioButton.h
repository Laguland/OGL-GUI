#pragma once
#include "Renderable.h"
#include <Windows.h>
#include <gl/GL.h>
#include "GUICircle.h"

class GUIRadioButton : public Renderable
{
	Vector2D			m_ButtonCentre;
	int					m_CircleSize;
	GUICircle*			m_pCircle;
	bool				isTicked;

public:
						GUIRadioButton(Vector2D	buttonCentre, int circleSisze, bool ticked);
						~GUIRadioButton();

	bool				IsMouseInside(int x, int y);
	void				SetBoolValue(bool value);
	void				Drag(int x, int y);
	void				Render();
};

