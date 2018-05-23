#pragma once
#include "Renderable.h"
#include <Windows.h>
#include <gl/GL.h>
#include "GUIButton.h"
#include "GUIText.h"
#include <string.h>

class GUIComboBox : public Renderable
{
private:
	Vector2D			positionTL;
	Vector2D			positionBR;
	Vector2D			button1positionTL;
	Vector2D			button1positionBR;
	Vector2D			button2positionTL;
	Vector2D			button2positionBR;
	Vector2D			button3positionTL;
	Vector2D			button3positionBR;
	Vector2D			label1Position;
	Vector2D			label2Position;
	Vector2D			label3Position;
	Vector2D			label4Position;
	float				yDiff;
	GUIButton*			topButton;
	GUIButton*			smallMouseButton;
	GUIButton*			mediumMouseButton;
	GUIButton*			bigMouseButton;
	GUIText*			topButtonLabel;
	GUIText*			smallLabel;
	GUIText*			midLabel;
	GUIText*			bigLabel;
	bool				isClicked;

public:
	GUIComboBox(Vector2D newPositionTL, Vector2D newPositionBR);
	~GUIComboBox();

	void SetIsClicked(bool value);
	void Drag(int x, int y);
	bool IsMouseInsideSMALL(int x, int y);
	bool IsMouseInsideMID(int x, int y);
	bool IsMouseInsideBIG(int x, int y);
	bool IsMouseInsideTOP(int x, int y);
	void Render();
};

