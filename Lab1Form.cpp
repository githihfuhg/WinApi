#include "Lab1Form.h"
#include <stdexcept>


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
	Form::CreateForm();
}
void Lab1Form::СreateFormControls()
{

	this->HwndButton = CreateWindow(L"BUTTON", L"Вариант 1", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 70, 91, 150, 50, this->Hwnd, reinterpret_cast<HMENU>(CTL_ID::BUTTON_CLICK), nullptr, nullptr);
	this->HwndButton2 = CreateWindow(L"BUTTON", L"Вариант 2", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 300, 91, 150, 50, this->Hwnd, reinterpret_cast<HMENU>(CTL_ID::BUTTON_CLICK2), nullptr, nullptr);
	if (!this->HwndButton || !this->HwndButton2)
		throw std::runtime_error("Error can't register window class");

}

Lab1Form::Lab1Form(bool IsMainWindow) : Form(IsMainWindow)
{

	
}
