#pragma once

#include "Renderable.h"
#include <Windows.h>
#include <gl/GL.h>
#include "Vector2D.h"
#include "GUIText.h"
#include "GUIButton.h"
#include "GUICircle.h"
#include "GUIWindow.h"
#include "GUISlider.h"
#include "GUIComboBox.h"
#include "GUITickBox.h"
#include "GUIRadioButton.h"

class SettingsWindow : public Renderable
{
private:
	GUIWindow*			m_pSettingsWindow;          // window pointer
	Vector2D			settingsWindow_topleft;     // window coord
	Vector2D			settingsWindow_bottomright; // window coord
	GUIText*			labelColor;					// label "Change Frame Color" pointer
	Vector2D			positionLabelColor;         // label coord
	GUISlider*			sliderRed;					// Red slider pointer
	Vector2D			positionSliderRed;			// Red slider coord
	Vector2D			positionSliderRedLabel;		// Red slider label coord
	GUISlider*			sliderGreen;				// Green slider pointer
	Vector2D			positionSliderGreen;		// Green slider coord
	Vector2D			positionSliderGreenLabel;	// Green slider label coord
	GUISlider*			sliderBlue;					// Blue slider pointer
	Vector2D			positionSliderBlue;			// Blue slider coord
	Vector2D			positionSliderBlueLabel;	// Blue slider label coord
	GUIText*			labelInvert;				// label "Invert Y Axis"
	Vector2D			positionLabelInvert;		// label position
	GUITickBox*			tickBoxInvert;				// tick box pointer
	Vector2D			tickBoxPositionTL;
	Vector2D			tickBoxPositionBR;
	GUIText*			labelChangeSize;
	Vector2D			labelChangePosition;
	GUIText*			labelSize8;
	Vector2D			labelSize8Position;
	GUIRadioButton*		radioButtonSize8;
	Vector2D			radioButtonSize8Position;
	GUIText*			labelSize10;
	Vector2D			labelSize10Position;
	GUIRadioButton*		radioButtonSize10;
	Vector2D			radioButtonSize10Position;
	GUIText*			labelSize12;
	Vector2D			labelSize12Position;
	GUIRadioButton*		radioButtonSize12;
	Vector2D			radioButtonSize12Position;
	bool				radioButton8Clicked;
	bool				radioButton10Clicked;
	bool				radioButton12Clicked;
	Vector2D			settingsButtonApplyTL;
	Vector2D			settingsButtonApplyBR;
	Vector2D			settingsButtonBackTL;
	Vector2D			settingsButtonBackBR;
	GUIComboBox*		comboBox;
	Vector2D			comboBoxPositionTL;
	Vector2D			comboBoxPositionBR;
	GUIText*			labelComboBox;
	Vector2D			labelComboBoxPosition;
	bool				comboBoxClicked;
	bool				smallButtonClicked;
	bool				midButtonClicked;
	bool				bigButtonClicked;

public:
	SettingsWindow();
	~SettingsWindow();

	void				Render();
};

