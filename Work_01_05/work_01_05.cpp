#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <process.h>
#include <windows.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

void main()
{
	char* Text = (char*)calloc(1000,sizeof(char));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

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
		fgets(str,300, file);
		if (strlen(str) <= 70)
		{
			strcat(Text, str);
		}

		else
		{
			printf("����� ������ %d ������ 70 ������ - ������ �� ����� ������� � ���������\n",i+1);
		}

		i++;
	}
	
	fclose(file);

	int count = strlen(Text);
	printf("size - %d", count);


	if (count <= 1000)
	{

		printf("\n\n------------------------\n\n");

		printf("%s\n", Text);

		char * pch = strtok(Text, " ,.-\n\t\"?��...:;�");

		while (pch != NULL)                         // ���� ���� �������
		{
			if (strlen(pch) > 2) // ���� � ����� ���� �����
			{

				int n_pch = strlen(pch);

				if (*pch == *(pch + strlen(pch) - 1))
				{
					printf("%s\n", pch);
				}
			}

			pch = strtok(NULL, " ,.-\n\t\"?��...;:�");
		}
	}

	else
	{
		puts("����� ������ ������ 1000 ��������");
	}


	puts("\n\n������� ����� ������� ��� ������...");
	_getch();
}

