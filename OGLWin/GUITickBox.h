#pragma once
#include "Renderable.h"
#include <Windows.h>
#include <gl/GL.h>
#include "Vector2D.h"

class GUITickBox : public Renderable
{
private:
	Vector2D		m_PositionTL;
	Vector2D		m_PositionBR;
	bool			isTicked;

public:
	GUITickBox(Vector2D positionTL, Vector2D positionBR, bool boolStatus);
	~GUITickBox();

	void SetBoolValue(bool value);
	bool IsMouseInside(int x, int y);
	void Drag(int x, int y);
	bool IsTicked();
	void Render();
};

