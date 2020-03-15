#include <stdexcept>
#include "MainForm.h"
#include "Lab1Form2.h"

MainForm::MainForm(LPCWSTR title) : Form(title)
{


}

MainForm::~MainForm()
{
}

LRESULT MainForm::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_COMMAND:
		{
																									
			switch (static_cast<CTL_ID>LOWORD(wParam))                                       // ��������� ������� ����������
			{
				case CTL_ID::Button:
				{
					ButtonClick();
					break;
				}
				case CTL_ID::Button2:
				{
					Button2Click();
					break;
				}
				case CTL_ID::NewFormButton:
				{
					NewFormButtonClick();
					break;
				}
			}

			return 0;
		}

		case WM_DESTROY:
		{
			PostQuitMessage(EXIT_SUCCESS);      // ��������� ���� 
			return 0;
		}

	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void MainForm::CreateForm()
{
	Form::CreateForm();
}
void MainForm::�reateFormControls()
{

	HwndButton = CreateWindow(L"BUTTON", L"������� 1", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 25, 91, 150, 50, Hwnd, reinterpret_cast<HMENU>(CTL_ID::Button), nullptr, nullptr);
	HwndButton2 = CreateWindow(L"BUTTON", L"������� 2", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 220, 91, 150, 50, Hwnd, reinterpret_cast<HMENU>(CTL_ID::Button2), nullptr, nullptr);
	HwndNewFormButton = CreateWindow(L"BUTTON", L"����� �����", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 420, 91, 150, 50, Hwnd, reinterpret_cast<HMENU>(CTL_ID::NewFormButton), nullptr, nullptr);
	if (!HwndButton || !HwndButton2 || !HwndNewFormButton)
		throw std::runtime_error("Error can't register window class");

}

void MainForm::ButtonClick()
{
	MessageBox(nullptr, TEXT("�� �������� �� ������ 1!"), TEXT("�����������!"), MB_ICONINFORMATION);
}

void MainForm::Button2Click()
{
	MessageBox(nullptr, TEXT("�� �������� �� ������ 2!"), TEXT("�����������!"), MB_ICONINFORMATION);
}

void MainForm::NewFormButtonClick()
{
	Lab1Form2 form2(L"NewForm",L"Form2",this->Hwnd);
	form2.Run();
}


