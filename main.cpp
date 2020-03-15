#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")// предпроцесорная команда( макрос маниеста) позволяет украситть программу
#include<Windows.h>
#include <ppl.h>
#include "Lab1Form.h"


int CALLBACK wWinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPWSTR lpCmdLine,_In_ int nShowCmd){ /*HINSTANCE hInstance,HINSTANCE,PWSTR,int nCmdShow*/
 Lab1Form  lab1 /*= new*/ /*Lab1Form*/(true);
 return lab1.Run();

}
