#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")// ��������������� �������( ������ ��������) ��������� ��������� ���������
#include<Windows.h>
#include <ppl.h>
#include "MainForm.h"


int CALLBACK wWinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPWSTR lpCmdLine,_In_ int nShowCmd){ /*HINSTANCE hInstance,HINSTANCE,PWSTR,int nCmdShow*/
 MainForm  lab1(L"Form");
 return lab1.Run();
}
