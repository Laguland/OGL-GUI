#include "GUIWindow.h"



GUIWindow::GUIWindow(Vector2D topLeft, Vector2D bottomRight, const char* windowName, float windowRed, float windowGreen, float windowBlue, float frameRed, float frameGreen, float frameBlue)
{
	m_TopLeft = topLeft;
	m_BottomRight = bottomRight;
	m_TopBarBottomRight.SetX(bottomRight.GetX());
	m_TopBarBottomRight.SetY(bottomRight.GetY() + 360.f);
	m_WindowName = windowName;
	m_WindowRed = windowRed;
	m_WindowGreen = windowGreen;
	m_WindowBlue = windowBlue;
	m_FrameRed = frameRed;
	m_FrameGreen = frameGreen;
	m_FrameBlue = frameBlue;

	m_TextPosition.SetX(topLeft.GetX() + 15);
	m_TextPosition.SetY(topLeft.GetY() - 5);
	m_pNameLabel = new GUIText(m_TextPosition,12, windowName);
}

GUIWindow::~GUIWindow()
{
	delete m_pNameLabel;
}

void GUIWindow::SetTopLeft(Vector2D topLeft)
{
	m_TopLeft = topLeft;
}

void GUIWindow::SetBottomRight(Vector2D bottomRight)
{
	m_BottomRight = bottomRight;
}

void GUIWindow::SetTopLeftX(int newX)
{
	m_TopLeft.SetX(newX);
}

void GUIWindow::SetBottomRightX(int newX)
{
	m_BottomRight.SetX(newX);
	m_TopBarBottomRight.SetX(newX);
}

void GUIWindow::SetTopLeftY(int newY)
{
	m_TopLeft.SetY(newY);
	m_TopBarBottomRight.SetY(newY - 40.0f);
}

void GUIWindow::SetBottomRightY(int newY)
{
	m_BottomRight.SetY(newY);
}

void GUIWindow::SetWindowName(const char* windowName)
{
	m_WindowName = windowName;
}
void GUIWindow::SetWindowRed(float windowRed)
{
	m_WindowRed = windowRed;
}

void GUIWindow::SetWindowGreen(float windowGreen)
{
	m_WindowGreen = windowGreen;
}

void GUIWindow::SetWindowBlue(float windowBlue)
{
	m_WindowBlue = windowBlue;
}

void GUIWindow::SetFrameRed(float frameRed)
{
	m_FrameRed = frameRed;
}

void GUIWindow::SetFrameGreen(float frameGreen)
{
	m_FrameGreen = frameGreen;
}

void GUIWindow::SetFrameBlue(float frameBlue)
{
	m_FrameBlue = frameBlue;
}

Vector2D GUIWindow::GetTopLeft()
{
	return m_TopLeft;
}

Vector2D GUIWindow::GetBottomRight()
{
	return m_BottomRight;
}

float GUIWindow::GetTopLeftX()
{
	return m_TopLeft.GetX();
}

float GUIWindow::GetBottomRightX()
{
	return m_BottomRight.GetX();
}

float GUIWindow::GetTopLeftY()
{
	return m_TopLeft.GetY();
}

float GUIWindow::GetBottomRightY()
{
	return m_BottomRight.GetY();
}

bool GUIWindow::IsDragable(int x, int y)
{
	if (x >= m_TopLeft.GetX() &&
		x <= m_TopBarBottomRight.GetX() &&
		y <= m_TopLeft.GetY() &&
		y >= m_TopBarBottomRight.GetY())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GUIWindow::Render()
{
	float tlx = m_TopLeft.GetX();
	float tly = m_TopLeft.GetY();
	float brx = m_BottomRight.GetX();
	float bry = m_BottomRight.GetY();
	float topBarBRx = m_BottomRight.GetX();
	float topBarBRy = m_TopBarBottomRight.GetY();

	// Draw Window
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(m_WindowRed, m_WindowGreen, m_WindowBlue);
	glVertex2f(tlx, bry);
	glVertex2f(brx, bry);
	glVertex2f(tlx, tly);
	glVertex2f(brx, tly);

	glEnd();

	// Draw Top Bar
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(m_FrameRed, m_FrameGreen, m_FrameBlue);
	glVertex2f(tlx, topBarBRy);
	glVertex2f(topBarBRx, topBarBRy);
	glVertex2f(tlx, tly);
	glVertex2f(topBarBRx, tly);

	glEnd();

	// Draw Frame
	glBegin(GL_TRIANGLE_STRIP); // left edge

	glVertex2f(tlx, bry);
	glVertex2f(tlx + 5.0f, bry);
	glVertex2f(tlx, topBarBRy);
	glVertex2f(tlx + 5.0f, topBarBRy);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP); // bottom edge

	glVertex2f(tlx, bry);
	glVertex2f(brx, bry);
	glVertex2f(tlx + 5.0f, bry + 5.0f);
	glVertex2f(brx, bry + 5.0f);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP); // right edge

	glVertex2f(brx - 5.0f, bry);
	glVertex2f(brx, bry);
	glVertex2f(topBarBRx - 5.0f, topBarBRy);
	glVertex2f(topBarBRx, topBarBRy);

	glEnd();

	// Draw Exit button

	glBegin(GL_LINE_LOOP);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(topBarBRx - 45.0f, topBarBRy + 35.0f);
	glVertex2f(topBarBRx - 45.0f, topBarBRy + 5.0f);
	glVertex2f(topBarBRx - 15.0f, topBarBRy + 5.0f);
	glVertex2f(topBarBRx - 15.0f, topBarBRy + 35.0f);

	glEnd();

	glBegin(GL_LINE_STRIP);

	glVertex2f(topBarBRx - 45.0f, topBarBRy + 5.0f);
	glVertex2f(topBarBRx - 15.0f, topBarBRy + 35.0f);

	glEnd();

	glBegin(GL_LINE_STRIP);

	glVertex2f(topBarBRx - 45.0f, topBarBRy + 35.0f);
	glVertex2f(topBarBRx - 15.0f, topBarBRy + 5.0f);

	glEnd();

	// Draw Minimalise button

	glBegin(GL_LINE_LOOP);

	glVertex2f(topBarBRx - 115.0f, topBarBRy + 35.0f);
	glVertex2f(topBarBRx - 115.0f, topBarBRy + 5.0f);
	glVertex2f(topBarBRx - 85.0f, topBarBRy + 5.0f);
	glVertex2f(topBarBRx - 85.0f, topBarBRy + 35.0f);

	glEnd();

	glBegin(GL_LINE_STRIP);

	glVertex2f(topBarBRx - 110.0f, topBarBRy + 10.0f);
	glVertex2f(topBarBRx - 90.0f, topBarBRy + 10.0f);

	glEnd();

	// Draw Minimalise button

	glBegin(GL_LINE_LOOP);

	glVertex2f(topBarBRx - 80.0f, topBarBRy + 35.0f);
	glVertex2f(topBarBRx - 80.0f, topBarBRy + 5.0f);
	glVertex2f(topBarBRx - 50.0f, topBarBRy + 5.0f);
	glVertex2f(topBarBRx - 50.0f, topBarBRy + 35.0f);

	glEnd();

	// Draw Text

	m_TextPosition.SetX(m_TopLeft.GetX() + 15.0f);
	m_TextPosition.SetY(m_TopLeft.GetY() - 5.0f);
	m_pNameLabel->SetPosition(m_TextPosition);
	m_pNameLabel->Render();
}