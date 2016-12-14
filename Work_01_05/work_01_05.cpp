#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <process.h>
#include <windows.h>
#include <string.h>
#include <malloc.h>

/* �������� ��� ������ �� ����� */
void get_strings(char*);

/* ������� �� ����� */
void print_text(char*);

/* �������� � ������� �� ����� �����, � ������� ������ ������ ����� ���������� */
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
		puts("����� ������ ������ 1000 ��������");
	}


	puts("\n\n������� ����� ������� ��� ������...");
	_getch();
}

void get_strings(char * InText)
{

	FILE* file;
	fopen_s(&file, "file.txt", "r");
	if (!file)
	{
		puts("���������� ������� ����");
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
			printf("����� ������ %d ������ 70 ������ - ������ �� ����� ������� � ���������\n", i + 1);
		}

		i++;
	}

	fclose(file);
}

void print_text(char * InText)
{
	puts("\n\n�������� ����� ��� �����, ����� ������� ������ 70 ��������\n");
	puts("--------------------------------------------------------------");

	printf("%s\n", InText);
}

void get_words_and_print(char* InText)
{
	puts("\n\n����� � ������� ������ � ��������� ����� ���������");
	puts("--------------------------------------------------");

	char * pch = strtok(InText, " ,.-\n\t\"?��...:;�*+");

	while (pch != NULL)                         // ���� ���� �������
	{
		if (strlen(pch) > 2) // ���� � ����� ������ 3-� ����
		{

			int n_pch = strlen(pch);

			if (*pch == *(pch + strlen(pch) - 1)) // ���� ������ ������ ����� ���������� �������
			{
				printf("%s\n", pch);
			}
		}

		pch = strtok(NULL, " ,.-\n\t\"?��...;:�*+");
	}

}
