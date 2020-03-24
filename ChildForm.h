#pragma once
#include "Form.h"


class ChildForm final : public Form {
private:
	enum class CTL_ID
	{

	};

	LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	void CreateForm() override;
	void ÑreateFormControls() override;

	
	
public:
	ChildForm(LPCWSTR className, LPCWSTR title, int x,int y, HWND mainHwnd);
	~ChildForm();
	
};
