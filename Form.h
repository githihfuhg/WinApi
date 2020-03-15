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
		Form(bool IsMainWindow);
		~Form() = default;
	
	public:
		
		int Run();

	private:
		static LRESULT CALLBACK ApplicationProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	
};

