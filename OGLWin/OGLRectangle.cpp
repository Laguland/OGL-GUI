#include "OGLRectangle.h"

OGLRectangle::OGLRectangle()
{
	redColor = 0.1f;
	greenColor = 0.1f;
	blueColor = 0.7f;
	m_fontSize = 10;
	mouseSize = 0.0f;

	mouseButtonUp = true;
	//mainMenuOpened = true;
	settingsWindowOpened = false;
	playWindowOpened = false;
	imageWindowOpened = false;
	resizeInProgress = false;

	mousePosition.SetX(0.0f);
	mousePosition.SetY(0.0f);


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
	tickBoxInvert = new GUITickBox(tickBoxPositionTL,tickBoxPositionBR,false);
	labelChangeSize = new GUIText(labelChangePosition, 10, "Change Font Size");
	labelSize8 = new GUIText(labelSize8Position,10,"Size 8:");
	labelSize10 = new GUIText(labelSize10Position,10,"Size 10:");
	labelSize12 = new GUIText(labelSize12Position,10,"Size 12:");
	radioButtonSize8 = new GUIRadioButton(radioButtonSize8Position,7,false);
	radioButtonSize10 = new GUIRadioButton(radioButtonSize10Position,7,true);
	radioButtonSize12 = new GUIRadioButton(radioButtonSize12Position,7,false);
	comboBox = new GUIComboBox(comboBoxPositionTL, comboBoxPositionBR);
	labelComboBox = new GUIText(labelComboBoxPosition,10,"Slecect Mouse Size");

	// MAIN MENU WINDOW

	mainWindow_topleft.SetX(-100.0f);
	mainWindow_topleft.SetY(300.0f);
	mainWindow_bottomright.SetX(300.0f);
	mainWindow_bottomright.SetY(-100.0f);

	m_pMainWindow = new GUIWindow(mainWindow_topleft,mainWindow_bottomright, "Main Menu", 0.0f, 1.0f, 0.0f, redColor, greenColor, blueColor);

	// PLAY WINDOW

	playWindow_topleft.SetX(-100.0f);
	playWindow_topleft.SetY(300.0f);
	playWindow_bottomright.SetX(300.0f);
	playWindow_bottomright.SetY(-100.0f);

	m_pPlayWindow = new GUIWindow(playWindow_topleft, playWindow_bottomright, "Play", 0.0f, 1.0f, 0.0f, redColor, greenColor, blueColor);

	// IMAGE WINDOW

	imageWindow_topleft.SetX(-100.0f);
	imageWindow_topleft.SetY(300.0f);
	imageWindow_bottomright.SetX(300.0f);
	imageWindow_bottomright.SetY(-100.0f);

	m_pImageWindow = new GUIWindow(imageWindow_topleft, imageWindow_bottomright, "Image", redColor, greenColor, blueColor, redColor, greenColor, blueColor);
}

OGLRectangle::~OGLRectangle()
{
	delete m_pSettingsWindow;
	delete labelColor;
	delete sliderRed;
	delete sliderGreen;
	delete sliderBlue;
	delete labelInvert;
	delete tickBoxInvert;
	delete labelChangeSize;
	delete radioButtonSize8;
	delete labelSize10;
	delete radioButtonSize10;
	delete labelSize12;
	delete radioButtonSize12;
	delete comboBox;
	delete labelComboBox;
	delete m_pImageWindow;
	delete m_pPlayWindow;
	delete m_pMainWindow;
}

void OGLRectangle::DrawMouse()
{
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(mousePosition.GetX(), mousePosition.GetY());
	glVertex2f(mousePosition.GetX(), (mousePosition.GetY() - 15.0f) - mouseSize);
	glVertex2f((mousePosition.GetX() + 10.0f) + mouseSize, (mousePosition.GetY() - 8.0f) - mouseSize);

	glEnd();
}

void OGLRectangle::ImageWindow() 
{
	m_pImageWindow->Render();
}

void OGLRectangle::PlayWindow()
{
	m_pPlayWindow->Render();
}

void OGLRectangle::SettingsWindow()
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


	//// Draw Apply Button

	//DrawButton(settingsWindow_topleft.GetX() + 10.0f, settingsWindow_topleft.GetY() - 330.0f, settingsWindow_topleft.GetX() + 150.0f, settingsWindow_topleft.GetY() - 380.0f);
	//Text(settingsWindow_topleft.GetX() + 20.0f, settingsWindow_topleft.GetY() - 340.0f, 10 + fontSize, "Apply");

	//// Draw Back Button

	//DrawButton(settingsWindow_topleft.GetX() + 250.0f, settingsWindow_topleft.GetY() - 330.0f, settingsWindow_topleft.GetX() + 390.0f, settingsWindow_topleft.GetY() - 380.0f);
	//Text(settingsWindow_topleft.GetX() + 260.0f, settingsWindow_topleft.GetY() - 340.0f, 10 + fontSize, "Back");
}

void OGLRectangle::MainWindow()
{

}
void OGLRectangle::Render()
{
	//mainMenuOpened = true;
	//MainWindow();
	//imageWindowOpened = true;
	//ImageWindow();
	//playWindowOpened = true;
	//PlayWindow();

	settingsWindowOpened = true;
	SettingsWindow();

	DrawMouse();
}

bool OGLRectangle::MouseMove( int x, int y, int diffx, int diffy )
{
	// Mouse move

	if (tickBoxInvert->IsTicked())
	{
		y = -y;
		mousePosition.SetX(x);
		mousePosition.SetY(y);
	}
	else
	{
		mousePosition.SetX(x);
		mousePosition.SetY(y);
	}

	// Main Window Drag
	if (mainMenuOpened &&
		mouseButtonUp == false &&
		m_pMainWindow->IsDragable(x,y))
	{
		mainWindow_topleft.SetX(mainWindow_topleft.GetX() + diffx);
		mainWindow_bottomright.SetX(mainWindow_bottomright.GetX() + diffx);
		mainWindow_bottomright.SetY(mainWindow_bottomright.GetY() - diffy);
		mainWindow_topleft.SetY(mainWindow_topleft.GetY() - diffy);
	}
	// Play Window Drag
	if (playWindowOpened &&
		mouseButtonUp == false &&
		m_pPlayWindow->IsDragable(x,y))
	{
		playWindow_topleft.SetX(playWindow_topleft.GetX() + diffx);
		playWindow_bottomright.SetX(playWindow_bottomright.GetX() + diffx);
		playWindow_bottomright.SetY(playWindow_bottomright.GetY() - diffy);
		playWindow_topleft.SetY(playWindow_topleft.GetY() - diffy);
	}

	// Settings Window Drag

	if (settingsWindowOpened &&
		mouseButtonUp == false &&
		m_pSettingsWindow->IsDragable(x,y))
	{
		m_pSettingsWindow->SetBottomRightX(m_pSettingsWindow->GetBottomRightX() + diffx);
		m_pSettingsWindow->SetBottomRightY(m_pSettingsWindow->GetBottomRightY() - diffy);
		m_pSettingsWindow->SetTopLeftX(m_pSettingsWindow->GetTopLeftX() + diffx);
		m_pSettingsWindow->SetTopLeftY(m_pSettingsWindow->GetTopLeftY() - diffy);

		labelColor->Drag(diffx, diffy);
		sliderRed->Drag(diffx, diffy);
		sliderGreen->Drag(diffx, diffy);
		sliderBlue->Drag(diffx, diffy);
		tickBoxInvert->Drag(diffx, diffy);
		labelInvert->Drag(diffx, diffy);
		labelChangeSize->Drag(diffx, diffy);
		labelSize8->Drag(diffx, diffy);
		labelSize10->Drag(diffx, diffy);
		labelSize12->Drag(diffx, diffy);
		radioButtonSize8->Drag(diffx, diffy);
		radioButtonSize10->Drag(diffx, diffy);
		radioButtonSize12->Drag(diffx, diffy);
		comboBox->Drag(diffx, diffy);
		labelComboBox->Drag(diffx, diffy);
	}

	if (settingsWindowOpened &&
		mouseButtonUp == false &&
		sliderRed->IsMouseInside(x, y))			// Red circle drag
	{
		sliderRed->DragCircleX(diffx);
		redColor = sliderRed->GetRatio();
		m_pSettingsWindow->SetFrameRed(redColor);
		m_pImageWindow->SetFrameRed(redColor);
		m_pMainWindow->SetFrameRed(redColor);
		m_pPlayWindow->SetFrameRed(redColor);
	}

	if (settingsWindowOpened &&
		mouseButtonUp == false &&
		sliderGreen->IsMouseInside(x, y))			// Green circle drag
	{
		sliderGreen->DragCircleX(diffx);
		greenColor = sliderGreen->GetRatio();
		m_pSettingsWindow->SetFrameGreen(greenColor);
		m_pImageWindow->SetFrameGreen(greenColor);
		m_pMainWindow->SetFrameGreen(greenColor);
		m_pPlayWindow->SetFrameGreen(greenColor);
	}

	if (settingsWindowOpened &&
		mouseButtonUp == false &&
		sliderBlue->IsMouseInside(x, y))			// Blue circle drag
	{
		sliderBlue->DragCircleX(diffx);
		blueColor = sliderBlue->GetRatio();
		m_pSettingsWindow->SetFrameBlue(blueColor);
		m_pImageWindow->SetFrameBlue(blueColor);
		m_pMainWindow->SetFrameBlue(blueColor);
		m_pPlayWindow->SetFrameBlue(blueColor);
	}

	// Image Window Drag
	if (imageWindowOpened &&
		mouseButtonUp == false &&
		m_pImageWindow->IsDragable(x,y))
	{
		imageWindow_topleft.SetX(imageWindow_topleft.GetX() + diffx);
		imageWindow_bottomright.SetX(imageWindow_bottomright.GetX() + diffx);
		imageWindow_bottomright.SetY(imageWindow_bottomright.GetY() - diffy);
		imageWindow_topleft.SetY(imageWindow_topleft.GetY() - diffy);
	}

	// Resize windows

	// Main Window Resize


	if (mainMenuOpened &&
		mouseButtonUp == false)
	{
		// check left frame
		if (resizeInProgress == false &&
			x >= mainWindow_topleft.GetX() &&
			x <= mainWindow_topleft.GetX() + 5.0f &&
			y >= mainWindow_bottomright.GetY() + 5.0f &&
			y <= mainWindow_bottomright.GetY() + 360.0f)
		{
			mainWindow_topleft.SetX(mainWindow_topleft.GetX() + diffx);
		}


		// check left bottom square
		if (resizeInProgress == false &&
			x >= mainWindow_topleft.GetX() &&
			x <= mainWindow_topleft.GetX() + 5.0f &&
			y >= mainWindow_bottomright.GetY() &&
			y <= mainWindow_bottomright.GetY() + 5.0f)
		{
			mainWindow_topleft.SetX(mainWindow_topleft.GetX() + diffx);
			mainWindow_bottomright.SetY(mainWindow_bottomright.GetY() - diffy);
		}

		// check bottom frame

		if (resizeInProgress == false &&
			x >= mainWindow_topleft.GetX() - 5.0f &&
			x <= mainWindow_bottomright.GetX() + 5.0f &&
			y >= mainWindow_bottomright.GetY() &&
			y <= mainWindow_bottomright.GetY() + 5.0f)
		{
			mainWindow_bottomright.SetY(mainWindow_bottomright.GetY() - diffy);
		}

		// check right bottom square

		if (resizeInProgress == false &&
			x >= mainWindow_bottomright.GetX() - 5.0f &&
			x <= mainWindow_bottomright.GetX() &&
			y >= mainWindow_bottomright.GetY() &&
			y <= mainWindow_bottomright.GetY() + 5.0f)
		{
			mainWindow_bottomright.SetX(mainWindow_bottomright.GetX() + diffx);
			mainWindow_bottomright.SetY(mainWindow_bottomright.GetY() - diffy);
		}

		// check right frame

		if (resizeInProgress == false &&
			x >= mainWindow_bottomright.GetX() - 5.0f &&
			x <= mainWindow_bottomright.GetX() &&
			y >= mainWindow_bottomright.GetY() + 5.0f &&
			y <= mainWindow_bottomright.GetY() + 360.f)
		{
			mainWindow_bottomright.SetX(mainWindow_bottomright.GetX() + diffx);
		}
	}


	// Play Window Resize


	if (playWindowOpened &&
		mouseButtonUp == false)
	{
		// check left frame
		if (resizeInProgress == false &&
			x >= playWindow_topleft.GetX() &&
			x <= playWindow_topleft.GetX() + 5.0f &&
			y >= playWindow_bottomright.GetY() + 5.0f &&
			y <= playWindow_bottomright.GetY() + 360.0f)
		{
			playWindow_topleft.SetX(playWindow_topleft.GetX() + diffx);
		}


		// check left bottom square
		if (resizeInProgress == false &&
			x >= playWindow_topleft.GetX() &&
			x <= playWindow_topleft.GetX() + 5.0f &&
			y >= playWindow_bottomright.GetY() &&
			y <= playWindow_bottomright.GetY() + 5.0f)
		{
			playWindow_topleft.SetX(playWindow_topleft.GetX() + diffx);
			playWindow_bottomright.SetY(playWindow_bottomright.GetY() - diffy);
		}

		// check bottom frame

		if (resizeInProgress == false &&
			x >= playWindow_topleft.GetX() - 5.0f &&
			x <= playWindow_bottomright.GetX() + 5.0f &&
			y >= playWindow_bottomright.GetY() &&
			y <= playWindow_bottomright.GetY() + 5.0f)
		{
			playWindow_bottomright.SetY(playWindow_bottomright.GetY() - diffy);
		}

		// check right bottom square

		if (resizeInProgress == false &&
			x >= playWindow_bottomright.GetX() - 5.0f &&
			x <= playWindow_bottomright.GetX() &&
			y >= playWindow_bottomright.GetY() &&
			y <= playWindow_bottomright.GetY() + 5.0f)
		{
			playWindow_bottomright.SetX(playWindow_bottomright.GetX() + diffx);
			playWindow_bottomright.SetY(playWindow_bottomright.GetY() - diffy);
		}

		// check right frame

		if (resizeInProgress == false &&
			x >= playWindow_bottomright.GetX() - 5.0f &&
			x <= playWindow_bottomright.GetX() &&
			y >= playWindow_bottomright.GetY() + 5.0f &&
			y <= playWindow_bottomright.GetY() + 360.f)
		{
			playWindow_bottomright.SetX(playWindow_bottomright.GetX() + diffx);
		}
	}

	// Settings Window Resize


	if (settingsWindowOpened &&
		mouseButtonUp == false)
	{
		// check left frame
		if (resizeInProgress == false &&
			x >= settingsWindow_topleft.GetX() &&
			x <= settingsWindow_topleft.GetX() + 5.0f &&
			y >= settingsWindow_bottomright.GetY() + 5.0f &&
			y <= settingsWindow_bottomright.GetY() + 360.0f)
		{
			settingsWindow_topleft.SetX(settingsWindow_topleft.GetX() + diffx);
		}


		// check left bottom square
		if (resizeInProgress == false &&
			x >= settingsWindow_topleft.GetX() &&
			x <= settingsWindow_topleft.GetX() + 5.0f &&
			y >= settingsWindow_bottomright.GetY() &&
			y <= settingsWindow_bottomright.GetY() + 5.0f)
		{
			settingsWindow_topleft.SetX(settingsWindow_topleft.GetX() + diffx);
			settingsWindow_bottomright.SetY(settingsWindow_bottomright.GetY() - diffy);
		}

		// check bottom frame

		if (resizeInProgress == false &&
			x >= settingsWindow_topleft.GetX() - 5.0f &&
			x <= settingsWindow_bottomright.GetX() + 5.0f &&
			y >= settingsWindow_bottomright.GetY() &&
			y <= settingsWindow_bottomright.GetY() + 5.0f)
		{
			settingsWindow_bottomright.SetY(settingsWindow_bottomright.GetY() - diffy);
		}

		// check right bottom square

		if (resizeInProgress == false &&
			x >= settingsWindow_bottomright.GetX() - 5.0f &&
			x <= settingsWindow_bottomright.GetX() &&
			y >= settingsWindow_bottomright.GetY() &&
			y <= settingsWindow_bottomright.GetY() + 5.0f)
		{
			settingsWindow_bottomright.SetX(settingsWindow_bottomright.GetX() + diffx);
			settingsWindow_bottomright.SetY(settingsWindow_bottomright.GetY() - diffy);
		}

		// check right frame

		if (resizeInProgress == false &&
			x >= settingsWindow_bottomright.GetX() - 5.0f &&
			x <= settingsWindow_bottomright.GetX() &&
			y >= settingsWindow_bottomright.GetY() + 5.0f &&
			y <= settingsWindow_bottomright.GetY() + 360.f)
		{
			settingsWindow_bottomright.SetX(settingsWindow_bottomright.GetX() + diffx);
		}
	}


	// Image Window Resize


	if (imageWindowOpened &&
		mouseButtonUp == false)
	{
		// check left frame
		if (resizeInProgress == false &&
			x >= imageWindow_topleft.GetX() &&
			x <= imageWindow_topleft.GetX() + 5.0f &&
			y >= imageWindow_bottomright.GetY() + 5.0f &&
			y <= imageWindow_bottomright.GetY() + 360.0f)
		{
			imageWindow_topleft.SetX(imageWindow_topleft.GetX() + diffx);
		}


		// check left bottom square
		if (resizeInProgress == false &&
			x >= imageWindow_topleft.GetX() &&
			x <= imageWindow_topleft.GetX() + 5.0f &&
			y >= imageWindow_bottomright.GetY() &&
			y <= imageWindow_bottomright.GetY() + 5.0f)
		{
			imageWindow_topleft.SetX(imageWindow_topleft.GetX() + diffx);
			imageWindow_bottomright.SetY(imageWindow_bottomright.GetY() - diffy);
		}

		// check bottom frame

		if (resizeInProgress == false &&
			x >= imageWindow_topleft.GetX() - 5.0f &&
			x <= imageWindow_bottomright.GetX() + 5.0f &&
			y >= imageWindow_bottomright.GetY() &&
			y <= imageWindow_bottomright.GetY() + 5.0f)
		{
			imageWindow_bottomright.SetY(imageWindow_bottomright.GetY() - diffy);
		}

		// check right bottom square

		if (resizeInProgress == false &&
			x >= imageWindow_bottomright.GetX() - 5.0f &&
			x <= imageWindow_bottomright.GetX() &&
			y >= imageWindow_bottomright.GetY() &&
			y <= imageWindow_bottomright.GetY() + 5.0f)
		{
			imageWindow_bottomright.SetX(imageWindow_bottomright.GetX() + diffx);
			imageWindow_bottomright.SetY(imageWindow_bottomright.GetY() - diffy);
		}

		// check right frame

		if (resizeInProgress == false &&
			x >= imageWindow_bottomright.GetX() - 5.0f &&
			x <= imageWindow_bottomright.GetX() &&
			y >= imageWindow_bottomright.GetY() + 5.0f &&
			y <= imageWindow_bottomright.GetY() + 360.f)
		{
			imageWindow_bottomright.SetX(imageWindow_bottomright.GetX() + diffx);
		}
	}
	return true;
}

bool OGLRectangle::MouseLBUp( int x, int y )
{
	if (tickBoxInvert->IsTicked())
	{
		y = -y;
	}
	if (tickBoxClicked &&
		tickBoxInvert->IsMouseInside(x,y))
	{
		if (tickBoxInvert->IsTicked())
		{
			tickBoxInvert->SetBoolValue(false);
			tickBoxClicked = false;
		}
		else
		{
			tickBoxInvert->SetBoolValue(true);
			tickBoxClicked = false;
		}
	}
	else
	{
		tickBoxClicked = false;
	}

	//radio buttons 

	if (radioButton8Clicked ||
		radioButton10Clicked ||
		radioButton12Clicked)
	{
		if (radioButton8Clicked &&
			radioButtonSize8->IsMouseInside(x,y))
		{
			radioButtonSize8->SetBoolValue(true);
			radioButtonSize10->SetBoolValue(false);
			radioButtonSize12->SetBoolValue(false);

			m_fontSize = 8;
		}
		if (radioButton10Clicked &&
			radioButtonSize10->IsMouseInside(x, y))
		{
			radioButtonSize8->SetBoolValue(false);
			radioButtonSize10->SetBoolValue(true);
			radioButtonSize12->SetBoolValue(false);

			m_fontSize = 10;
		}
		if (radioButton12Clicked &&
			radioButtonSize12->IsMouseInside(x, y))
		{
			radioButtonSize8->SetBoolValue(false);
			radioButtonSize10->SetBoolValue(false);
			radioButtonSize12->SetBoolValue(true);

			m_fontSize = 12;
		}

		labelColor->SetSize(m_fontSize);
		labelInvert->SetSize(m_fontSize);
		labelChangeSize->SetSize(m_fontSize);
		labelSize8->SetSize(m_fontSize);
		labelSize10->SetSize(m_fontSize);
		labelSize12->SetSize(m_fontSize);
		sliderRed->SetFontSize(m_fontSize);
		sliderGreen->SetFontSize(m_fontSize);
		sliderBlue->SetFontSize(m_fontSize);

		radioButton8Clicked = false;
		radioButton10Clicked = false;
		radioButton12Clicked = false;
	}

	// combo box

	if (comboBox->IsMouseInsideTOP(x,y) &&
		comboBoxClicked)
	{
		comboBox->SetIsClicked(true);
	}
	else
	{
		comboBox->SetIsClicked(false);
	}

	if (comboBoxClicked &&
		smallButtonClicked &&
		comboBox->IsMouseInsideSMALL(x,y))
	{
		mouseSize = 0.0f;
		smallButtonClicked = false;
	}
	if (comboBoxClicked &&
		midButtonClicked &&
		comboBox->IsMouseInsideMID(x,y))
	{
		mouseSize = 10.0f;
		midButtonClicked = false;
	}
	if (comboBoxClicked &&
		bigButtonClicked &&
		comboBox->IsMouseInsideBIG(x,y))
	{
		mouseSize = 20.0f;
		bigButtonClicked = false;
	}

	mouseButtonUp = true;
	resizeInProgress = false;
	return true;
}

bool OGLRectangle::MouseLBDown( int x, int y )
{
	if (tickBoxInvert->IsTicked())
	{
		y = -y;
	}
	if (tickBoxInvert->IsMouseInside(x,y))
	{
		tickBoxClicked = true;
	}

	// radio buttons
	if (radioButtonSize8->IsMouseInside(x,y))
	{
		radioButton8Clicked = true;
	}
	if (radioButtonSize10->IsMouseInside(x, y))
	{
		radioButton10Clicked = true;
	}
	if (radioButtonSize12->IsMouseInside(x, y))
	{
		radioButton12Clicked = true;
	}

	//combo box
	if (comboBox->IsMouseInsideTOP(x,y))
	{
		comboBoxClicked = true;
	}
	if (comboBox->IsMouseInsideSMALL(x, y) &&
		comboBoxClicked)
	{
		smallButtonClicked = true;
	}
	if (comboBox->IsMouseInsideMID(x, y) &&
		comboBoxClicked) 
	{
		midButtonClicked = true;
	}
	if (comboBox->IsMouseInsideBIG(x, y) &&
		comboBoxClicked)
	{
		bigButtonClicked = true;
	}

	mouseButtonUp = false;
	return true;
}