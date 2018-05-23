#pragma once

#include "Renderable.h"
#include "Vector2D.h"



class GUIButton : public Renderable
{
private:

	Vector2D		m_TopLeft;
	Vector2D		m_BottomRight;
	float			m_Red;
	float			m_Green;
	float			m_Blue;

public:

	GUIButton(Vector2D topLeft, Vector2D bottomRight, float red, float green, float blue);
	~GUIButton();

	bool IsMouseInside(int x, int y);
	void Drag(int x, int y);

	void			SetTopLeft(Vector2D topLeft);
	void			SetBottomRight(Vector2D bottomRight);
	void			SetRed(float red);
	void			SetGreen(float green);
	void			SetBlue(float blue);
	Vector2D		GetTopLeft();
	Vector2D		GetBottomRight();
	float			GetRed();
	float			GetGreen();
	float			GetBlue();
	void			Render();
};

