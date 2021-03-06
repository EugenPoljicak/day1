// appp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include"..\lib\public.h"
#include "..\dll2\public.h"

#include <Windows.h>

typedef double(*importFunction)(int);

int main()
{
	int a = 5;


	std::cout << "Static_lib, value is: " << static_lib::get_value(a) << '\n';


	HINSTANCE dll_ID = LoadLibrary(TEXT("..\\dll1\\x64\\Debug\\dynamic_library.dll"));
	if (dll_ID == NULL)
	{
		printf("Can't load the DLL!\n");
	}
	importFunction dllFunc;
	dllFunc = (importFunction)GetProcAddress(dll_ID, "get_value");
	if (dllFunc == NULL)
	{
		printf("Can't load the function within DLL!\n");
	}
		std::cout << "Dynamic lbrary dll_1 value is: " << dllFunc(a) << '\n';
	FreeLibrary(dll_ID);



	std::cout << "Dynamic library dll_2 with implib value is: " << get_value(a) << '\n';
	
}

