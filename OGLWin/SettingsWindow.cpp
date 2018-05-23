#include "SettingsWindow.h"



SettingsWindow::SettingsWindow()
{
	redColor = 0.1f;
	greenColor = 0.1f;
	blueColor = 0.7f;
	m_fontSize = 10;
	mouseSize = 0.0f;

	// SETTINGS WINDOW 

	settingsWindow_topleft.SetX(-100.0f);
	settingsWindow_topleft.SetY(300.0f);
	settingsWindow_bottomright.SetX(300.0f);
	settingsWindow_bottomright.SetY(-100.0f);

	positionLabelColor.SetX(-90.0f);
	positionLabelColor.SetY(230.0f);
	positionSliderRed.SetX(-10.0f);
	positionSliderRed.SetY(195.0f);
	positionSliderRedLabel.SetX(-90.0f);
	positionSliderRedLabel.SetY(210.0f);
	positionSliderGreen.SetX(-10.0f);
	positionSliderGreen.SetY(175.0f);
	positionSliderGreenLabel.SetX(-90.0f);
	positionSliderGreenLabel.SetY(190.0f);
	positionSliderBlue.SetX(-10.0f);
	positionSliderBlue.SetY(155.0f);
	positionSliderBlueLabel.SetX(-90.0f);
	positionSliderBlueLabel.SetY(170.0f);

	positionLabelInvert.SetX(-90.0f);
	positionLabelInvert.SetY(140.0f);
	tickBoxPositionTL.SetX(100.0f);
	tickBoxPositionTL.SetY(135.0f);
	tickBoxPositionBR.SetX(120.0f);
	tickBoxPositionBR.SetY(115.0f);

	labelChangePosition.SetX(-90.0f);
	labelChangePosition.SetY(110.0f);
	labelSize8Position.SetX(-90.0f);
	labelSize8Position.SetY(90.0f);
	labelSize10Position.SetX(10.0f);
	labelSize10Position.SetY(90.0f);
	labelSize12Position.SetX(120.0f);
	labelSize12Position.SetY(90.0f);

	radioButtonSize8Position.SetX(-5.0f);
	radioButtonSize8Position.SetY(75.0f);
	radioButtonSize10Position.SetX(105.0f);
	radioButtonSize10Position.SetY(75.0f);
	radioButtonSize12Position.SetX(215.0f);
	radioButtonSize12Position.SetY(75.0f);

	labelComboBoxPosition.SetX(-90.0f);
	labelComboBoxPosition.SetY(45.0f);
	comboBoxPositionTL.SetX(150.0f);
	comboBoxPositionTL.SetY(55.0f);
	comboBoxPositionBR.SetX(250.0f);
	comboBoxPositionBR.SetY(15.0f);

	m_pSettingsWindow = new GUIWindow(settingsWindow_topleft, settingsWindow_bottomright, "Settings", 0.0f, 1.0f, 0.0f, redColor, greenColor, blueColor);
	labelColor = new GUIText(positionLabelColor, 10, "Change Frame Color");
	sliderRed = new GUISlider(positionSliderRed, 200.0f, "Red", positionSliderRedLabel, m_fontSize);
	sliderGreen = new GUISlider(positionSliderGreen, 200.0f, "Green", positionSliderGreenLabel, m_fontSize);
	sliderBlue = new GUISlider(positionSliderBlue, 200.0f, "Blue", positionSliderBlueLabel, m_fontSize);
	labelInvert = new GUIText(positionLabelInvert, 10, "Invert Y Axis");
	tickBoxInvert = new GUITickBox(tickBoxPositionTL, tickBoxPositionBR, false);
	labelChangeSize = new GUIText(labelChangePosition, 10, "Change Font Size");
	labelSize8 = new GUIText(labelSize8Position, 10, "Size 8:");
	labelSize10 = new GUIText(labelSize10Position, 10, "Size 10:");
	labelSize12 = new GUIText(labelSize12Position, 10, "Size 12:");
	radioButtonSize8 = new GUIRadioButton(radioButtonSize8Position, 7, false);
	radioButtonSize10 = new GUIRadioButton(radioButtonSize10Position, 7, true);
	radioButtonSize12 = new GUIRadioButton(radioButtonSize12Position, 7, false);
	comboBox = new GUIComboBox(comboBoxPositionTL, comboBoxPositionBR);
	labelComboBox = new GUIText(labelComboBoxPosition, 10, "Slecect Mouse Size");
}


SettingsWindow::~SettingsWindow()
{
}

void SettingsWindow::Render()
{
	m_pSettingsWindow->Render();

	labelColor->Render();
	sliderRed->Render();
	sliderGreen->Render();
	sliderBlue->Render();

	//// Invert Y Axis

	labelInvert->Render();
	tickBoxInvert->Render();

	//// Change Font Size

	labelChangeSize->Render();
	labelSize8->Render();
	labelSize10->Render();
	labelSize12->Render();

	radioButtonSize8->Render();
	radioButtonSize10->Render();
	radioButtonSize12->Render();

	//// Change mouse size

	labelComboBox->Render();
	comboBox->Render();
}
