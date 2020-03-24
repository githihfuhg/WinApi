#pragma once
#include <functional>
#include<Windows.h>


 class Form
 {

	 protected:
		HFONT hFontThamoda; // ��������� ����������� ����� ������ � ���� 
		RECT WindowRC;   // ��������� ,����������� ���� 
		MSG Msg; // ��������� ������������ ���������
		HWND Hwnd, MainHwnd; //  ����� �������� ���� � ��������( ���� �������� ���� ����������� � � ������ ���� ���� �������� ��������)
		WNDCLASSEX Wc; /*{sizeof(WNDCLASSEX)};*/
		virtual LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); // ������� ������� �������������� ��������� 
		virtual void CreateForm(); // ������� �������� ���� 
		virtual void �reateFormControls(); // ������� �������� ��������� ( ������, ����������� �.�.�)
		Form(LPCWSTR className, LPCWSTR title, int width, int height, int x = NULL, int y = NULL, bool isStaticWindow = true, HWND mainHwnd = nullptr);// ����������� 
		std::wstring GetText(HWND Hwnd); // ������� ������������ ����� �� ���� 
		 ~Form() = default; // ���������� 
	

	public:
		 int Run(); // �������, ������������ ���� � ��������� ���������

	private:
		int X; // ���������� ���� �� ������ (������ �����)
		int Y; //  ���������� ���� �� ������ (������ ������)
		bool IsStaticWindow; // ���������� ���������� �� �� , ����� �� ���� ������ ������ ��� ��� 
		LPCWSTR ClassName; // ��� ������
		LPCWSTR Title; // ���������
		static LRESULT CALLBACK ApplicationProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); // ����������� ������� �������, ����� ��� ���� , ���� �������� ��������� ������������� ������� 

	
 };

