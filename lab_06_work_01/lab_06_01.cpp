#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <process.h>
#include <string.h>
#include <malloc.h>

/* Удаление 2-х первых и 2 последних символов */
char* cut_string(char*,int);

void main()
{

	setlocale(LC_CTYPE, "Russian");

	int n;

	system("cls");

	main:printf_s("Введите длину строки:");
	scanf_s("%d", &n);

	if (n > 1)
	{
		char* c_name = new char[n];

		puts("Введите строку (Окончить ввод клавишей Enter):");

		fflush(stdin);

		gets_s(c_name, n);
		gets_s(c_name, n);

		char* c_temp = cut_string(c_name, n);

		if (!c_temp)
		{
			printf_s("исходная строка: %s\n\nВывод нового массива невозможен\n", c_name);
		}
		else
		{
			printf_s("исходная строка: %s\nколичество символов исходной строки= %d\nНовая строка: %s\nколичество символов новой строки= %d\n", c_name, strlen(c_name), c_temp, strlen(c_temp));
		}

		delete[] c_temp;
		delete[] c_name;

		goto main;
	}

	else
	{
		printf_s("Решений нет\n");

		goto main;
	}
}

char* cut_string(char* instring,int n)
{
	char* outstring = new char[n-4];

	int count = strlen(instring);

	if (count % 2) // 1
	{		
		printf_s("Длина строки нечетная\n");

		return NULL;
	}

	else // 0
	{
		for (int i = 0; i <= count; i++)
		{
			*(outstring + i) = *(instring + i + 2);
		}

		*(outstring + strlen(outstring) - 2) = '\0';

		return outstring;
	}
}