#include "Lab1Form2.h"

LRESULT Lab1Form2::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg)
	{
		case WM_COMMAND:
		{

			//switch (static_cast<CTL_ID>LOWORD(wParam))   // обработка событий контроллов
			//{
			//	
			//}
			//break;

			return 0;
		}

		case WM_DESTROY:
		{
			PostQuitMessage(EXIT_SUCCESS);      // закарытие окна 
			return 0;
		}
	}
	
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
	
}

void Lab1Form2::CreateForm()
{
	Form::CreateForm();
}

void Lab1Form2::СreateFormControls()
{
	Form::СreateFormControls();
}

Lab1Form2::Lab1Form2(LPCWSTR className, LPCWSTR title, HWND mainHwnd):Form(className,title,mainHwnd)
{

	
}
Lab1Form2::~Lab1Form2()
{

	
}
