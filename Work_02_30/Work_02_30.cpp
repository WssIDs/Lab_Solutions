#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <process.h>
#include <windows.h>
#include <string.h>
#include <malloc.h>
#include <fcntl.h>

struct Notebook_size // габаритные размеры
{
	double х;
	double y;
	double z;
};


struct NOTEBOOK
{
	char model[21]; // наименование 
	Notebook_size size;
	double w;	// вес
	int price;  // цена 
};

/* имя текстового файла */
char* infilename = "note.txt";

/* имя бинарного файла */
char* outfilename = "note.dat";

/*	Добавить запись в бинарный файл */
void addrecord(NOTEBOOK);

/*	Создать файл и записать значение 0 в первые 2 байта бинарного файла если не прошло успешное открытие*/
void create_file(char*);

/*	Сохранить данные в бинарный файл */
void save_data(NOTEBOOK*, short);

/*	Чтение данных из текстового файла и сохранение в бинарный файл */
void get_data();

/*	Чтение данных из бинарного файла */
void get_data_binary(NOTEBOOK*,short*);

/*Вывод на экран данных*/
void print_data(NOTEBOOK*,short);

/* Сортировка цены по убыванию */
void sort_data(NOTEBOOK*, short);

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool bmenu = true;

	while (bmenu) // пока true
	{
		int input_number = 0;

		puts("Главное меню:");
		puts("___________________________________________________________");
		puts("1 - Считать данные из текстового файла и записать в бинарный\n с выводом на экран");
		puts("2 - Сортировка цен по убыванию и запись в бинарный файл");
		puts("3 - Считать данные из бинарного файла и вывести на экран");
		puts("0 - Выход");

		puts("\nВыберите пункт меню:");

		scanf_s("%d", &input_number);

		if (input_number == 1)
		{
			get_data();
		}

		else if (input_number == 2)
		{
			NOTEBOOK* notebooks = (NOTEBOOK*)calloc(100, sizeof(NOTEBOOK));

			short int number = 0;

			get_data_binary(notebooks, &number);

			sort_data(notebooks, number);

			save_data(notebooks, number);


		}

		else if (input_number == 3)
		{

			NOTEBOOK* notebooks = (NOTEBOOK*)calloc(100, sizeof(NOTEBOOK));

			short int number = 0;

			get_data_binary(notebooks, &number);

			print_data(notebooks,number);
		}

		else if (input_number == 0)
		{
			bmenu = false;
		}

	}

	puts("Нажмите любую клавишу для выхода...");
	_getch();
}


void create_file(char* filename)
{
	FILE* bfile;
	short count = 0;
	
	fopen_s(&bfile,filename, "rb"); // открываем для чтения бинарный файл
	if (bfile == NULL)
	{
		//printf("Файл не найден. Попытка создания файла...\n");
		
		fopen_s(&bfile,filename, "wb");
		if (bfile == NULL) 
		{
			printf("Ошибка создания файла\n");
		}

		else if (bfile != NULL)
		{
			fwrite(&count, sizeof(short), 1, bfile);
		}
	}

	fclose(bfile);
}

void save_data(NOTEBOOK* notebooks, short count)
{
	FILE* file;

	fopen_s(&file, outfilename, "w+b");
	if (!file)
	{
		puts("Невозможно создать файл");
		return;
	}

	fwrite(&count, sizeof(short), 1, file);

	fseek(file, 2, SEEK_SET);

	fwrite(notebooks, sizeof(NOTEBOOK), count, file);

	fclose(file);
}


void addrecord(NOTEBOOK Notebook)
{
	FILE* file;

	fopen_s(&file, outfilename, "r+b");
	if (!file)
	{
		puts("Невозможно открыть файл");
		return;
	}
	
	short int count = 0;

	fread(&count, sizeof(short int), 1, file);
	
	fclose(file);	
	
	//printf("count = %d\n", count);

	fopen_s(&file, outfilename, "a+b");
	if (!file)
	{
		puts("Невозможно создать файл");
		return;
	}
	
	fwrite(&Notebook, sizeof(NOTEBOOK), 1, file);

	fclose(file);

	fopen_s(&file, outfilename, "rb+");
	if (!file)
	{
		puts("Невозможно создать файл");
		return;
	}

	count++;

	fwrite(&count, sizeof(short int), 1, file);

	fclose(file);
}

void get_data()
{
	FILE* file;

	fopen_s(&file, infilename, "r");
	if (!file)
	{
		puts("Невозможно прочитать файл");
		return;
	}

	char* Mainstr = (char*)calloc(100, sizeof(char));

	NOTEBOOK notebok;

	NOTEBOOK* notebooks = (NOTEBOOK*)calloc(100, sizeof(NOTEBOOK));

	short int notebook_counts = 0;

	while (fgets(Mainstr, 100, file))
	{

		char* frequency_m = (char*)calloc(4, sizeof(char));

		for (int i = 0; i < 3; i++)
		{
			*(frequency_m + i) = *(Mainstr + 43 + i);
		}

		// Частота ноутбука
		int frequency = atoi(frequency_m);

		if (frequency > 120) // Выполняем если частота больше 120
		{

			// Модель ноубука
			
			char* model_m = (char*)calloc(30, sizeof(char));

			for (int i = 0; i < 19; i++)
			{
				*(model_m + i) = *(Mainstr + i);
			}


			strcpy_s(notebok.model, model_m);


			// Размеры ноубука

			char* size_m = (char*)calloc(50, sizeof(char));

			for (int i = 0; i < 14; i++)
			{
				*(size_m + i) = *(Mainstr + 29 + i);
			}

			char* contex1;
			
			double* size_notebook = (double*)calloc(3, sizeof(double));
			
			char * pch = strtok_s(size_m, "x", &contex1);
			
			int count_size = 0;

			while (pch != NULL)   // пока есть лексемы
			{
				*(size_notebook + count_size) = atof(pch);
				pch = strtok_s(NULL, "x", &contex1);
				count_size++;
			}

			// Размер X
			notebok.size.х = *(size_notebook);
			// Размер Y
			notebok.size.y = *(size_notebook + 1);
			// Размер Z
			notebok.size.z = *(size_notebook + 2);


			// Цена ноутбука

			char* price_m = (char*)calloc(5, sizeof(char));

			for (int i = 0; i < 4; i++)
			{
				*(price_m + i) = *(Mainstr + 20 + i);
			}

			notebok.price = atoi(price_m);

			// Вес ноутбука

			char* weight_m = (char*)calloc(5, sizeof(char));

			for (int i = 0; i < 3; i++)
			{
				*(weight_m + i) = *(Mainstr + 25 + i);
			}

			notebok.w = atof(weight_m);

			
			*(notebooks + notebook_counts) = notebok; // добавляем в массив структуру

			notebook_counts++; // добавлем счетчик ноутбуков
		}
	}

	fclose(file);


	create_file(outfilename); 

	for (int i = 0; i < notebook_counts; i++)
	{
		addrecord(*(notebooks + i)); // Добавляем данные в бинарный файл
	}
}

void sort_data(NOTEBOOK* notebooks, short count)
{
	NOTEBOOK temp;

	// Сортировка массива пузырьком
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if ((notebooks + j)->price < (notebooks + j + 1)->price)
			{
				// меняем элементы местами
				temp = *(notebooks + j);
				*(notebooks + j) = *(notebooks + j + 1);
				*(notebooks + j + 1) = temp;
			}
		}
	}
}



void get_data_binary(NOTEBOOK* notebooks, short* count)
{
	NOTEBOOK notebook;

	FILE   *in;
	fopen_s(&in, outfilename, "rb+");
	if (!in)
	{
		printf("Ошибка открытия файла\n");
	}
	
	// Чтение первых 2-х байтов

	fread(count, sizeof(short int), 1, in);

	//printf("%d", *count);

	// Чтение структур данных
	
	int num = 0;
	
	while (fread(&notebook, sizeof(NOTEBOOK), 1, in))
	{
		if (feof(in)) printf("Ошибка чтения");

		notebooks[num] = notebook;
		num++; // счетчик количества записей
	}

	fclose(in);
}


void print_data(NOTEBOOK* notebooks, short count)
{
	printf("\n");

	printf("| № |	Модель ноутбука		|	Размеры	  | Вес | Цена |\n");
	printf("________________________________________________________________\n");

	for (int i = 0; i < count; i++)
	{
		printf("|%3d|%20s	|%5.1lfx%5.1lfx%5.1lf|%5.1lf|%6d|\n", i + 1, (notebooks + i)->model, notebooks[i].size.х, notebooks[i].size.y, notebooks[i].size.z, notebooks[i].w, notebooks[i].price);
	}

	printf("________________________________________________________________\n");
	printf("\n");
}