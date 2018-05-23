#pragma once

#include "Renderable.h"
#include <Windows.h>
#include <gl/GL.h>
#include "GUIText.h"
#include "Vector2D.h"
#include <string.h>
#include "GUICircle.h"


class GUISlider : public Renderable
{
private:
	Vector2D		m_Position;
	Vector2D		m_LabelPosition;
	Vector2D		m_CircleCentre;
	GUICircle*		m_pCircle;
	GUIText*		m_pText;
	float			m_Length;
	const char*		m_Label;
	bool			m_IsLabel;
	float			m_RatioValue;

public:
					GUISlider(Vector2D position, float length, const char* label, Vector2D labelPosition, int textSize);
					GUISlider(Vector2D position, float length);
					~GUISlider();

	void			Render();
	void			SetFontSize(int value);
	void			Drag(int x, int y);
	void			DragCircleX(int x);
	void			SetCirclePosition(float newPosition);
	float			GetCirclePositionX();
	float			GetRatio();
	bool			IsMouseInside(int x, int y);
};

