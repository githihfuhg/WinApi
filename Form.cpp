#include "Form.h"
#include <stdexcept>


Form::Form(bool IsMainWindow)
{
	using std::wstring;
	using std::string;
	/*try 
	{*/
		this->Form::CreateForm();
		this->Form::СreateFormControls();
	//}
	//catch (const std::exception e)
	//
	//{
	//	MessageBoxA(nullptr, e.what(), e.what(), MB_ICONINFORMATION);
		/*ExitProcess(EXIT_FAILURE);*/
	//}
	//
}

int Form::Run()
{
	ShowWindow(this->Hwnd, SW_SHOWDEFAULT);
	UpdateWindow(this->Hwnd);
	while(GetMessage(&Msg,nullptr,0,0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return static_cast<int>(Msg.wParam);
}



void Form::CreateForm()
{
	Wc.cbSize = sizeof(WNDCLASSEX);
	Wc.cbClsExtra = 0; //выделение памяти в классе окна
	Wc.cbWndExtra = 0; //выделение памяти в классе окна
	Wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH)); // окрашивает окно(белый)
	Wc.hCursor = LoadCursor(nullptr, IDI_APPLICATION);
	Wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	Wc.hInstance = GetModuleHandle(nullptr);
	Wc.lpfnWndProc = ApplicationProc;
	Wc.lpszClassName = L"MyApp";
	Wc.lpszMenuName = nullptr;
	Wc.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassEx(&Wc))
		throw std::runtime_error("Error can't register window class");



	RECT windowRC{ 0, 0, 600, 600 };
	AdjustWindowRect(&windowRC, WS_OVERLAPPEDWINDOW, false);
	
	/*Hwnd = CreateWindow(Wc.lpszClassName, 
		L"Graphics",
		WS_OVERLAPPEDWINDOW xor WS_THICKFRAME, 
		350, 100, 600, 600, nullptr, nullptr,
		Wc.hInstance, nullptr);*/ // регистрация класса  окна

	Hwnd = CreateWindowEx(
		0,
		Wc.lpszClassName,
		L"App",
		WS_SYSMENU | WS_MINIMIZEBOX,
		GetSystemMetrics(SM_CXSCREEN) - windowRC.right / 2,
		GetSystemMetrics(SM_CYSCREEN) - windowRC.bottom / 2,
		windowRC.right,
		windowRC.bottom,
		nullptr,
		nullptr,
		nullptr,
		this);
	
	if (/*Hwnd == INVALID_HANDLE_VALUE*/!this->Hwnd)
			throw std::runtime_error("Error can't create window!!");

	




	
	//ShowWindow(Hwnd, /*nCmdShow*/nShowCmd); // отрисовка окна 
	//UpdateWindow(Hwnd);  // обновление окна 
	//while (GetMessage(&Msg, nullptr, 0, 0)) { // цикл обработки сообщений параметры ураказтель на структуру, номер окна, фильтры

	//	TranslateMessage(&Msg);  // расшифровка сообщения 
	//	DispatchMessage(&Msg); // передача собщения 

	//}
	
}


void Form::СreateFormControls()
{
	/*this->HwndButton = CreateWindowEx(0,L"BUTTON",L"Кнопка",WS_CHILD | BS_PUSHBUTTON|WSF_VISIBLE,56,100,238,37,this->Hwnd,reinterpret_cast<HMENU>(Form::CTL_ID::BUTTON_CLICK),nullptr,nullptr);
	if(!this->HwndButton)
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
	if(uMsg == WM_NCCREATE)
	{
		pForm = static_cast<Form*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
		SetLastError(0);
		if (!SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pForm)))
		{
			if(GetLastError() != 0)
			{
				return false;
			}
		};
	}
	else
	{
		pForm = reinterpret_cast<Form*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	}
	if (pForm)
	{
		pForm->Hwnd = hWnd;
		return pForm->WindowProc(hWnd, uMsg, wParam, lParam);
	}
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}


