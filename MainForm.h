#pragma once
#include "Form.h"


class MainForm final : public Form
{
	enum class CTL_ID
	{
		Button,
		Button2,
		NewFormButton
	};
	
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	void CreateForm() override;
	void ÑreateFormControls() override;
	HWND HwndButton, HwndButton2,HwndNewFormButton;
	void ButtonClick();
	void Button2Click();
	void NewFormButtonClick();
	
public:
	MainForm(LPCWSTR title);
	~MainForm();
};
 