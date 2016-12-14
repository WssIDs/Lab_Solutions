#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <process.h>
#include <windows.h>
#include <string.h>
#include <malloc.h>

/* получить все строки из файла */
void get_strings(char*);

/* вывести на экран */
void print_text(char*);

/* получить и вывести на экран слова, у которых первый символ равен последнему */
void get_words_and_print(char*);

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	char* Text = (char*)calloc(1000,sizeof(char));
	
	get_strings(Text);

	int count = strlen(Text);

	if (count <= 1000)
	{

		print_text(Text);

		get_words_and_print(Text);
	}

	else
	{
		puts("ƒлина текста больше 1000 символов");
	}


	puts("\n\nЌажмите любую клавишу дл€ выхода...");
	_getch();
}

void get_strings(char * InText)
{

	FILE* file;
	fopen_s(&file, "file.txt", "r");
	if (!file)
	{
		puts("Ќевозможно создать файл");
		return;
	}

	int i = 0;

	char* str = (char*)calloc(200, sizeof(char));;

	while (!feof(file))
	{
		fgets(str, 300, file);
		if (strlen(str) <= 70)
		{
			strcat(InText, str);
		}

		else
		{
			printf("ƒлина строки %d больше 70 знаков - строка не будет прин€та в обработку\n", i + 1);
		}

		i++;
	}

	fclose(file);
}

void print_text(char * InText)
{
	puts("\n\n»сходный текст без строк, длина которых больше 70 символов\n");
	puts("--------------------------------------------------------------");

	printf("%s\n", InText);
}

void get_words_and_print(char* InText)
{
	puts("\n\n—лова в которых перва€ и последн€€ буква совпадают");
	puts("--------------------------------------------------");

	char * pch = strtok(InText, " ,.-\n\t\"?Ђї...:;Ч*+");

	while (pch != NULL)                         // пока есть лексемы
	{
		if (strlen(pch) > 2) // если в слове больше 3-х букв
		{

			int n_pch = strlen(pch);

			if (*pch == *(pch + strlen(pch) - 1)) // если первый символ равен последнему символу
			{
				printf("%s\n", pch);
			}
		}

		pch = strtok(NULL, " ,.-\n\t\"?Ђї...;:Ч*+");
	}

}
