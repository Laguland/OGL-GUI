#include "GUIComboBox.h"



GUIComboBox::GUIComboBox(Vector2D newPositionTL, Vector2D newPositionBR)
{
	isClicked = false;
	positionTL = newPositionTL;
	positionBR = newPositionBR;
	yDiff = positionTL.GetY() - positionBR.GetY();
	button1positionTL.SetX(positionTL.GetX());
	button1positionTL.SetY(positionTL.GetY() - yDiff - 2.0f);
	button1positionBR.SetX(positionBR.GetX());
	button1positionBR.SetY(positionBR.GetY() - yDiff - 2.0f);
	button2positionTL.SetX(positionTL.GetX());
	button2positionTL.SetY(button1positionTL.GetY() - yDiff - 2.0f);
	button2positionBR.SetX(positionBR.GetX());
	button2positionBR.SetY(button1positionBR.GetY() - yDiff - 2.0f);
	button3positionTL.SetX(positionTL.GetX());
	button3positionTL.SetY(button2positionTL.GetY() - yDiff - 2.0f);
	button3positionBR.SetX(positionBR.GetX());
	button3positionBR.SetY(button2positionBR.GetY() - yDiff - 2.0f);

	label1Position.SetX(positionTL.GetX() + 10.0f);
	label1Position.SetY(positionTL.GetY() - (yDiff / 2));
	label2Position.SetX(positionTL.GetX() + 10.0f);
	label2Position.SetY(button1positionTL.GetY() - (yDiff / 2));
	label3Position.SetX(positionTL.GetX() + 10.0f);
	label3Position.SetY(button2positionTL.GetY() - (yDiff / 2));
	label4Position.SetX(positionTL.GetX() + 10.0f);
	label4Position.SetY(button3positionTL.GetY() - (yDiff / 2));

	topButton = new GUIButton(positionTL, positionBR, 1.0f, 0.0f, 0.0f);
	smallMouseButton = new GUIButton(button1positionTL, button1positionBR, 1.0f, 0.0f, 0.0f);
	mediumMouseButton = new GUIButton(button2positionTL, button2positionBR, 1.0f, 0.0f, 0.0f);
	bigMouseButton = new GUIButton(button3positionTL, button3positionBR, 1.0f, 0.0f, 0.0f);
	topButtonLabel = new GUIText(label1Position, 6, "Change Size");
	smallLabel = new GUIText(label2Position, 6, "Small Size");
	midLabel = new GUIText(label3Position,6,"Medium Size");
	bigLabel = new GUIText(label4Position,6,"Big Size");
}


GUIComboBox::~GUIComboBox()
{
}

void GUIComboBox::SetIsClicked(bool value)
{
	isClicked = value;
}

void GUIComboBox::Drag(int x, int y)
{
	topButtonLabel->Drag(x, y);
	smallLabel->Drag(x, y);
	midLabel->Drag(x, y);
	bigLabel->Drag(x, y);
	topButton->Drag(x, y);
	smallMouseButton->Drag(x, y);
	mediumMouseButton->Drag(x, y);
	bigMouseButton->Drag(x, y);
}

bool GUIComboBox::IsMouseInsideTOP(int x, int y)
{
	if (topButton->IsMouseInside(x,y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GUIComboBox::IsMouseInsideSMALL(int x, int y)
{
	if (smallMouseButton->IsMouseInside(x,y))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool GUIComboBox::IsMouseInsideMID(int x, int y)
{
	if (mediumMouseButton->IsMouseInside(x,y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GUIComboBox::IsMouseInsideBIG(int x, int y)
{
	if (bigMouseButton->IsMouseInside(x,y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GUIComboBox::Render()
{
	if (isClicked)
	{
		topButton->Render();
		smallMouseButton->Render();
		mediumMouseButton->Render();
		bigMouseButton->Render();
		topButtonLabel->Render();
		smallLabel->Render();
		midLabel->Render();
		bigLabel->Render();
	}
	else
	{
		topButton->Render();
		topButtonLabel->Render();
	}
}