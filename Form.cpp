#include "Form.h"
#include <stdexcept>

Form::Form(LPCWSTR className, LPCWSTR title, int width, int height, int x, int y, bool isStaticWindow, HWND mainHwnd)
{
	this->ClassName = className;
	this->Title = title;
	this->MainHwnd = mainHwnd;
	this->WindowRC.left = 0;
	this->WindowRC.top = 0;
	this->WindowRC.right = width;
	this->WindowRC.bottom = height;
	this->X = x;
	this->Y = y;
	this->IsStaticWindow = isStaticWindow;
}

int Form::Run()
{
	if (!FindWindow(ClassName, Title))
	{
		try
		{
			CreateForm();
			СreateFormControls();
			ShowWindow(this->Hwnd, SW_SHOWDEFAULT);
			UpdateWindow(this->Hwnd);


			while (GetMessage(&Msg, nullptr, 0, 0))
			{
				TranslateMessage(&Msg);
				DispatchMessage(&Msg);
			}

			return static_cast<int>(Msg.wParam);
		}
		catch (const std::exception* e)
		{
			std::string buff = e->what();
			std::wstring ext(buff.begin(), buff.end());
			MessageBox(nullptr, ext.c_str(), ext.c_str(), MB_ICONERROR);
			ExitProcess(EXIT_FAILURE);
		}
	}
}



void Form::CreateForm()
{
	UnregisterClass(ClassName, GetModuleHandle(nullptr));
	Wc.cbSize = sizeof(WNDCLASSEX);
	Wc.cbClsExtra = 0; //выделение памяти в классе окна
	Wc.cbWndExtra = 0; //выделение памяти в классе окна
	Wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH)); // окрашивает окно(белый)
	Wc.hCursor = LoadCursor(nullptr, IDI_APPLICATION);
	Wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	Wc.hInstance = GetModuleHandle(nullptr);
	Wc.lpfnWndProc = ApplicationProc;
	Wc.lpszClassName = ClassName;
	Wc.lpszMenuName = nullptr;
	Wc.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassEx(&Wc))
		throw std::runtime_error("Error can't register window class");

	AdjustWindowRect(&WindowRC, WS_OVERLAPPEDWINDOW, false);

	Hwnd = CreateWindowEx(
		0,
		Wc.lpszClassName,
		Title,
		(IsStaticWindow) ? WS_SYSMENU | WS_MINIMIZEBOX | DS_CENTER : WS_SYSMENU | WS_OVERLAPPEDWINDOW | DS_CENTER,
		(X == NULL) ? (GetSystemMetrics(SM_CXSCREEN) >> 1) - (WindowRC.right >> 1) : X,
		(Y == NULL) ? (GetSystemMetrics(SM_CYSCREEN) >> 1) - (WindowRC.bottom >> 1) : Y,
		WindowRC.right,
		WindowRC.bottom,
		MainHwnd,/////
		nullptr,
		nullptr,
		this);

	hFontThamoda = CreateFont(
		17,
		0,
		0,
		0,
		FW_NORMAL,
		0,
		0,
		0,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		L"Thamoda");

	if (/*!this->Hwnd &&!this->hFontThamodaThamoda     */   !(this->Hwnd || this->hFontThamoda))
		throw std::runtime_error("Error can't create window!!");

}


void Form::СreateFormControls()
{

	/*this->HwndButton = CreateWindow(L"BUTTON", L"Вариант 1", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 70, 91, 150, 50, this->Hwnd, reinterpret_cast<HMENU>(CTL_ID::BUTTON_CLICK), nullptr, nullptr);
	this->HwndButton2 = CreateWindow(L"BUTTON", L"Вариант 2", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 300, 91, 150, 50, this->Hwnd, reinterpret_cast<HMENU>(CTL_ID::BUTTON_CLICK2), nullptr, nullptr);
	if (!this->HwndButton || !this->HwndButton2)
		throw std::runtime_error("Error can't register window class");*/

}



LRESULT Form::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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

LRESULT Form::ApplicationProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

		Form* pForm;
		if (uMsg == WM_NCCREATE)
		{
			pForm = static_cast<Form*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
			SetLastError(0);
			if (!SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pForm)))
			{
				if (GetLastError() != 0)
				{
					return false;
				}
			}
		}
		else
		{
			pForm = reinterpret_cast<Form*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
		}
		if (pForm != nullptr)
		{
			try
			{
				pForm->Hwnd = hWnd;
				return pForm->WindowProc(hWnd, uMsg, wParam, lParam);

			}
			catch (/*std::exception ex*/...)
			{
				return false;
			}

		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);

}

std::wstring Form::GetText(HWND hTextBox)
{
	int lenght = GetWindowTextLength(hTextBox);
	std::wstring buffer(lenght, '\0');
	GetWindowText(hTextBox, &buffer[0], lenght + 1);
	return buffer;
}


