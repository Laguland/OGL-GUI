#include "GUIText.h"

GUIText::GUIText(Vector2D position, int size, const char* text)
{
	m_Position = position;
	m_Size = size;
	m_Text = text;

	pGLfont = new GLFont();
	pGLfont->Create("franklin_gothic.glf");
}


GUIText::~GUIText()
{
	delete pGLfont;
}

void GUIText::Drag(int x, int y)
{
	m_Position.SetX(m_Position.GetX() + x);
	m_Position.SetY(m_Position.GetY() - y);
}

void GUIText::SetText( const char* text )
{
	m_Text = text;
}
void GUIText::SetPosition(Vector2D position)
{
	m_Position = position;
}
void GUIText::SetSize(int size)
{
	m_Size = size;
}
const char* GUIText::GetText()
{
	return m_Text;
}
Vector2D GUIText::GetPosition()
{
	return m_Position;
}
int GUIText::GetSize()
{
	return m_Size;
}
void GUIText::Render()
{
	pGLfont->Begin();
	glColor3f(1.0f, 1.0f, 1.0f);
	pGLfont->RenderText(m_Text, m_Position.GetX(), m_Position.GetY(), 0, m_Size);
	pGLfont->End();
}