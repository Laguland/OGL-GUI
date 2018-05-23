#pragma once

#include "Renderable.h"
#include <Windows.h>
#include <gl/GL.h>
#include "GUIText.h"
#include "Vector2D.h"
#include <string.h>

class GUIWindow : public Renderable
{
private:
	Vector2D		m_TopLeft;
	Vector2D		m_BottomRight;
	Vector2D		m_TextPosition;
	Vector2D		m_TopBarBottomRight;
	GUIText*		m_pNameLabel;
	const char*		m_WindowName;
	float			m_WindowRed;
	float			m_WindowGreen;
	float			m_WindowBlue;
	float			m_FrameRed;
	float			m_FrameGreen;
	float			m_FrameBlue;
	bool			m_Dragable;

public:

					GUIWindow(Vector2D topLeft, Vector2D bottomRight, const char* windowName, float windowRed, float windowGreen, float windowBlue, float frameRed, float frameGreen, float frameBlue);
					~GUIWindow();

	void			SetTopLeft(Vector2D topLeft);
	void			SetBottomRight(Vector2D bottomRight);
	void			SetTopLeftX(int newX);
	void			SetBottomRightX(int newX);
	void			SetTopLeftY(int newY);
	void			SetBottomRightY(int newY);
	void			SetWindowName(const char* windowName);
	void			SetWindowRed(float windowRed);
	void			SetWindowGreen(float windowGreen);
	void			SetWindowBlue(float windowBlue);
	void			SetFrameRed(float frameRed);
	void			SetFrameGreen(float frameGreen);
	void			SetFrameBlue(float frameBlue);
	Vector2D		GetTopLeft();
	Vector2D		GetBottomRight();
	float			GetTopLeftX();
	float			GetBottomRightX();
	float			GetTopLeftY();
	float			GetBottomRightY();
	bool			IsDragable(int x, int y);
	void			Render();
};

