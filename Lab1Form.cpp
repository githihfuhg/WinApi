#include "Lab1Form.h"

LRESULT Lab1Form::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
	{
		// обработка событий контроллов

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

void Lab1Form::CreateForm()
{
	base:CreateForm();
}

void Lab1Form::СreateFormControls()
{
	base:СreateFormControls();
}

Lab1Form::Lab1Form(bool IsMainWindow) : Form(IsMainWindow)
{

	
}
