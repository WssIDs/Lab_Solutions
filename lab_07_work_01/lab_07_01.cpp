#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <process.h>
#include <windows.h>

/* Ввод строк и сохранение в файл */
void input_string(char*,char*);

/* Чтение строк из файла */
char* get_string(char*);

/* Функция шифрования строк */
char* encrypt(char*);

/* Фунция дешифрования строк*/
char* decode(char*);

void main()
{

	setlocale(LC_CTYPE, "Russian");

	int n;

	main:puts("Меню");
	printf("1 - Записать строку в файл\n");
	printf("2 - Считать строку из файла и распечатать\n");
	printf("3 - Зашифровать строку и записать в файл\n");
	printf("4 - Расшифровать строку и записать в файл\n");
	printf("5 - Выход\n");
	puts("Выберите пункт:");

	fflush(stdin);

	scanf_s("%d", &n);

	if (n > 0 && n <= 5)
	{
		char*mass = new char[80];
				
		switch (n)
		{
		case 1: // Запись строки в файл
			char str[80];
			printf("Введите строку:\n");
			gets_s(str);
			gets_s(str);
			char buf[80];
			OemToChar(str, buf);
			input_string("file.txt",buf);
			break;
		case 2:  // Считываение строки из файла и вывод на экран

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

		case 5: // Выход
			printf("Нажмите любую клавишу для выхода...\n");
			goto exit;
			break;
		}
	}

	else
	{
		printf("\nВыберите правильный вариант. Возврат в меню\n\n");
	}

	goto main;

	exit:_getch();

}


void input_string(char* filename,char* str)
{
	FILE *file;
	int n = 0;

	// Поток записи в тектовом режиме

	fopen_s(&file, filename, "w");

	// Пишем символы в файл

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

	for (int i = 0; i < len; i++)       // посимвольно
	{
		if ((*(mass + i) >= 'а' && *(mass + i) < 'я') || (*(mass + i) >= 'А' && *(mass + i) < 'Я')) 
		{
			*(mass + i) = *(mass + i) + 1;      // вместо буквы - следующая по алфавиту буква
		}

		else if (*(mass + i) == 'я')   // замена я на а
		{
			*(mass + i) = 'а';
		}
		
		else if (*(mass + i) == 'Я')  // замена Я на А
		{
			*(mass + i) = 'А';
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

	for (int i = 0; i < len; i++)       // посимвольно
	{
		if ((*(mass + i) > 'а' && *(mass + i) <= 'я') || (*(mass + i) > 'А' && *(mass + i) <= 'Я')) 
		{
			*(mass + i) = *(mass + i) - 1;      // вместо буквы - следующая по алфавиту буква
		}

		else if (*(mass + i) == 'а')   // замена а на я
		{
			*(mass + i) = 'я';
			//printf("%s", mass + i);
		}
		else if (*(mass + i) == 'А')   // замена а на я
		{
			*(mass + i) = 'Я';
			//printf("%s", mass + i);
		}
	}

	input_string(filename, mass);

	return mass;
}