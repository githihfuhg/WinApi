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
		virtual void �reateFormControls();
		Form(LPCWSTR title);
		Form(LPCWSTR className, LPCWSTR title,HWND mainHwnd);
		~Form() = default;
	
	public:
		
		int Run();

	private:
 	    
		HWND MainHwnd;
		LPCWSTR ClassName;
		LPCWSTR Title;
		static LRESULT CALLBACK ApplicationProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	
};

