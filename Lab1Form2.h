#pragma once
#include "Form.h"


class Lab1Form2 final : public Form {
private:
	enum class CTL_ID
	{

	};

	LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	void CreateForm() override;
	void ÑreateFormControls() override;

	
	
public:
	Lab1Form2(LPCWSTR className, LPCWSTR title, HWND mainHwnd);
	~Lab1Form2();
	
};
