#pragma once

#include "Renderable.h"
#include "Listener.h"
#include "Vector2D.h"
#include <string.h>
#include "GUIText.h"
#include "GUIButton.h"
#include "GUICircle.h"
#include "GUIWindow.h"
#include "GUISlider.h"
#include "GUITickBox.h"
#include "GUIRadioButton.h"
#include "GUIComboBox.h"

class OGLRectangle : public Renderable, public Listener
{
	private:

		// SETTINGS WINDOW
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

		// other 
		GUIWindow*			m_pImageWindow;
		GUIWindow*			m_pPlayWindow;
		GUIWindow*			m_pMainWindow;
		Vector2D			mainWindow_topleft;
		Vector2D			mainWindow_bottomright;
		Vector2D			imageWindow_topleft;
		Vector2D			imageWindow_bottomright;
		Vector2D			playWindow_topleft;
		Vector2D			playWindow_bottomright;
		Vector2D			mousePosition;
		bool				mouseButtonUp;
		bool				settingsWindowOpened;
		bool				playWindowOpened;
		bool				imageWindowOpened;
		bool				mainMenuOpened;
		bool				resizeInProgress;
		bool				tickBoxClicked;
		float				redColor;
		float				greenColor;
		float				blueColor;
		int					m_fontSize;
		float				mouseSize;

	public:
						OGLRectangle();
						~OGLRectangle();

		void			DrawMouse();
		void			SettingsWindow();
		void			ImageWindow();
		void			PlayWindow();
		void		    MainWindow();
		void			Render();
		bool			MouseMove( int x, int y, int diffx, int diffy );
		bool			MouseLBUp( int x, int y );
		bool			MouseLBDown( int x, int y );
};