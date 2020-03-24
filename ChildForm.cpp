#include "ChildForm.h"

ChildForm :: ChildForm(LPCWSTR className, LPCWSTR title,int x, int y, HWND mainHwnd) :
Form(className, title,600,600, x, y,true, mainHwnd)
{
	
}
LRESULT ChildForm::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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
			/*PostQuitMessage(EXIT_SUCCESS);  */    // закарытие окна 
			return 0;
		}
	}
	
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
	
}

void ChildForm::CreateForm()
{
	Form::CreateForm();
}

void ChildForm::СreateFormControls()
{
	Form::СreateFormControls();
}


ChildForm::~ChildForm()
{

	
}
