#pragma once
#include "Form.h"

class Lab1Form final : public Form
{
	
private:
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	void CreateForm() override;
	void ÑreateFormControls() override;
	enum class CTL_ID { } override;
public:
	Lab1Form(bool IsMainWindow);


	/* : Form(IsMainWindow);*/
};
 