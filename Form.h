#pragma once
#include <functional>
#include<Windows.h>


class Form
{

	protected:
	
		MSG Msg;
		HWND Hwnd;
		WNDCLASSEX Wc; /*{sizeof(WNDCLASSEX)};*/
		virtual LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual void CreateForm();
		virtual void ÑreateFormControls();
		virtual enum class CTL_ID{ BUTTON_CLICK };
		
	
	public:
		virtual ~Form() = default;
		Form(bool IsMainWindow);
		int Run();

	private:
		static LRESULT CALLBACK ApplicationProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	
};

