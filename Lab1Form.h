#pragma once
#include "Form.h"

class Lab1Form/* final*/ : public Form
{
	enum class CTL_ID
	{
		BUTTON_CLICK,
		BUTTON_CLICK2,
		BUTTON_CLICK3
	};
	
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	void CreateForm() override;
	void ÑreateFormControls() override;
	HWND HwndButton, HwndButton2;
public:
	Lab1Form(bool IsMainWindow);
};
 