#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <process.h>
#include <windows.h>

/* ���� ����� � ���������� � ���� */
void input_string(char*,char*);

/* ������ ����� �� ����� */
char* get_string(char*);

/* ������� ���������� ����� */
char* encrypt(char*);

/* ������ ������������ �����*/
char* decode(char*);

void main()
{

	setlocale(LC_CTYPE, "Russian");

	int n;

	main:puts("����");
	printf("1 - �������� ������ � ����\n");
	printf("2 - ������� ������ �� ����� � �����������\n");
	printf("3 - ����������� ������ � �������� � ����\n");
	printf("4 - ������������ ������ � �������� � ����\n");
	printf("5 - �����\n");
	puts("�������� �����:");

	fflush(stdin);

	scanf_s("%d", &n);

	if (n > 0 && n <= 5)
	{
		char*mass = new char[80];
				
		switch (n)
		{
		case 1: // ������ ������ � ����
			char str[80];
			printf("������� ������:\n");
			gets_s(str);
			gets_s(str);
			char buf[80];
			OemToChar(str, buf);
			input_string("file.txt",buf);
			break;
		case 2:  // ����������� ������ �� ����� � ����� �� �����

			mass=get_string("file.txt");
			printf("%s\n", mass);
			break;
		case 3:
			mass = encrypt("file.txt");
			printf("%s\n", mass);
			break;
		case 4:
			mass = decode("file.txt");
			printf("%s\n", mass);
			break;

		case 5: // �����
			printf("������� ����� ������� ��� ������...\n");
			goto exit;
			break;
		}
	}

	else
	{
		printf("\n�������� ���������� �������. ������� � ����\n\n");
	}

	goto main;

	exit:_getch();

}


void input_string(char* filename,char* str)
{
	FILE *file;
	int n = 0;

	// ����� ������ � �������� ������

	fopen_s(&file, filename, "w");

	// ����� ������� � ����

	while (str[n])
	{
		fputc(str[n++], file);
	}

	fclose(file);
}

char* get_string(char* filename)
{
	FILE* in;

	fflush(stdin);

	fopen_s(&in, filename, "r");

	char* mass = new char[80];

	while (fgets(mass,80, in));

	fclose(in);

	return mass;
}

char* encrypt(char* filename)
{
	char* mass = get_string(filename);

	int len = strlen(mass);

	//printf("\n %d", len);

	for (int i = 0; i < len; i++)       // �����������
	{
		if ((*(mass + i) >= '�' && *(mass + i) < '�') || (*(mass + i) >= '�' && *(mass + i) < '�')) 
		{
			*(mass + i) = *(mass + i) + 1;      // ������ ����� - ��������� �� �������� �����
		}

		else if (*(mass + i) == '�')   // ������ � �� �
		{
			*(mass + i) = '�';
		}
		
		else if (*(mass + i) == '�')  // ������ � �� �
		{
			*(mass + i) = '�';
		}
	}

	input_string(filename, mass);

	return mass;
}


char* decode(char* filename)
{
	char* mass = get_string(filename);

	int len = strlen(mass);

	//printf("\n %d", len);

	for (int i = 0; i < len; i++)       // �����������
	{
		if ((*(mass + i) > '�' && *(mass + i) <= '�') || (*(mass + i) > '�' && *(mass + i) <= '�')) 
		{
			*(mass + i) = *(mass + i) - 1;      // ������ ����� - ��������� �� �������� �����
		}

		else if (*(mass + i) == '�')   // ������ � �� �
		{
			*(mass + i) = '�';
			//printf("%s", mass + i);
		}
		else if (*(mass + i) == '�')   // ������ � �� �
		{
			*(mass + i) = '�';
			//printf("%s", mass + i);
		}
	}

	input_string(filename, mass);

	return mass;
}