#pragma once
#include <functional>
#include<Windows.h>


 class Form
 {

	 protected:
		HFONT hFontThamoda; // структуры описывающей шрифт текста в окне 
		RECT WindowRC;   // структура ,описывающ€€ окно 
		MSG Msg; // структура описывающа€€ сообщени€
		HWND Hwnd, MainHwnd; //  хендл текущего окна и главного( хенл шлавного окна заполн€етс€ в в случае если окно €вл€етс€ дочерним)
		WNDCLASSEX Wc; /*{sizeof(WNDCLASSEX)};*/
		virtual LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); // коллбек функци€ обрабатыыающа€ сообщени€ 
		virtual void CreateForm(); // функци€ создани€ окна 
		virtual void —reateFormControls(); // функци€ создани€ контролов ( кнопок, текстбоксов и.т.д)
		Form(LPCWSTR className, LPCWSTR title, int width, int height, int x = NULL, int y = NULL, bool isStaticWindow = true, HWND mainHwnd = nullptr);// конструктор 
		std::wstring GetText(HWND Hwnd); // функци€ возвращающа€ текст из окна 
		 ~Form() = default; // деструктор 
	

	public:
		 int Run(); // функци€, запускающа€€ окно и обработку сообщений

	private:
		int X; // координаты окна на экране (отступ слева)
		int Y; //  координаты окна на экране (отступ сверху)
		bool IsStaticWindow; // переменна€ отвечающа€ за то , будет ли окно мен€ть размер или нет 
		LPCWSTR ClassName; // им€ класса
		LPCWSTR Title; // заголовок
		static LRESULT CALLBACK ApplicationProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); // статическа€ коллбек функци€, нужна дл€ того , чтоб передать сообзение нестатической функции 

	
 };

