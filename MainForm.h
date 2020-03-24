#pragma once
#include "Form.h"
#include "ChildForm.h"


class MainForm final : public Form
{
	enum class CTL_ID  // перечисление, содержащее id контролов
	{
		Button,
		Button2,
		NewFormButton
	};
	
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	void CreateForm() override;
	void СreateFormControls() override;
	HWND HwndButton, HwndButton2,HwndNewFormButton;
	void ButtonClick();
	void Button2Click();
	void NewFormButtonClick();
	std::vector<ChildForm>childforms;
	
public:
	MainForm();
	~MainForm();
};
 