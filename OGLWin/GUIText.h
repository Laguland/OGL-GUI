#pragma once

#include "Renderable.h"
#include <string.h>
#include "Vector2D.h"
#include <Windows.h>
#include <gl/GL.h>
#include "GLFont.h"

class GUIText : public Renderable
{
private:
	const char*		m_Text;
	Vector2D		m_Position;
	int				m_Size;
	GLFont*			pGLfont;

public:
					GUIText(Vector2D position, int size, const char* text);
					~GUIText();

	void			Drag(int x, int y);
	void			SetText(const char* text);
	void			SetPosition(Vector2D position);
	void			SetSize(int size);
	const char*		GetText();
	Vector2D		GetPosition();
	int				GetSize();
	void			Render();

};

