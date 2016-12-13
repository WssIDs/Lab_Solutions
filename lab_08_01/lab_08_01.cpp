#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <process.h>
#include <windows.h>
#include <string.h>
#include <malloc.h>


#define MIN_ZP 230.00 // Минимальная заработная плата

/* текущее имя файла */
char currentfilename[10] = "studs.dat";

struct StudData 
{
	char FIO[100];
	char GroupNumber[6];
	double GPA;
	double IncomePerFamMember;
};


/* Получение количества записей в файле */
int get_records_num();

/* Добавление записи в файл */
void addrecord(StudData);

/* Получение данных из файла */
StudData* get_data();

/* Запись данных в файл */
void save_data(StudData*,int);

/* Удаление записи из файла */
void deleterecord(int);

/* Изменение данных */
void change_record(int);

/* Сортировка массива по убыванию */
void sort_data(StudData*,int);

/* Объединение 2-ух массивов */
void combine_data(StudData*,StudData*, StudData*, int,int);

/* Выполнение расчета */
void exec();

/* Вывод на экран */
void print_data(StudData*,int);

void main()
{
	int n;

	//setlocale(LC_CTYPE, "Russian");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	main:puts("\n---------------------");
	puts("Главное Меню:");
	puts("---------------------");
	printf("1 - Создать новый файл \n");
	printf("2 - Проссмотр файла \n");
	printf("3 - Корректировка файлов \n");
	printf("4 - Расчет \n");
	printf("5 - Выход\n");
	puts("Выберите пункт:");

	fflush(stdin);

	scanf_s("%d", &n);

	if (n > 0 && n <= 5)
	{
		switch (n)
		{
		case 1:
		{
			printf("Выбран пункт меню: Создать новый файл \n");

			FILE* file;
			fopen_s(&file, currentfilename, "wb");
			if (!file)
			{
				puts("Невозможно создать файл");
				return;
			}

			fclose(file);

			break;
		}
		case 2:
		{
			printf("Выбран пункт меню: Просмотр файла \n");

			int num = get_records_num();

			StudData* St = new StudData[num];
			St = get_data();

			print_data(St, num);

			delete[] St;

			break;
		}
		case 3:
		{
			int m;

			correct:puts("\n---------------------");
			puts("Меню редактирования:");
			puts("---------------------");

			int num = get_records_num();

			StudData* St = new StudData[num];
			St = get_data();

			print_data(St, num);

			delete[] St;

			printf("\n1 - Добавить запись\n");
			printf("2 - Изменить запись\n");
			printf("3 - Удалить запись\n");
			printf("4 - Назад\n");
			puts("Выберите пункт:");

			fflush(stdin);

			scanf_s("%d", &m);

			if (m > 0 && m <= 4)
			{
				switch (m)
				{
				case 1:
				{
					printf("Выбран пункт меню: Добавить запись \n");

					StudData Student;

					puts("Введите данные студента:");
					
					printf("Фамилия Имя Отчество (через пробел):\n");
					gets_s(Student.FIO);
					gets_s(Student.FIO);
					
					printf("Номер группы (первая буква остальные 4 цифры):\n");
					gets_s(Student.GroupNumber);
					
					printf("Средний балл:\n");
					scanf_s("%lf", &Student.GPA);
					
					printf("Доход на одного члена семьи:\n");
					scanf_s("%lf", &Student.IncomePerFamMember);

					addrecord(Student);

					break;
				}
				case 2:
				{
					printf("Выбран пункт меню: Редактировать запись \n");

					int index;

					printf("Выберите номер редактируемого элемента:\n");

					scanf_s("%d", &index);

					change_record(index);

					break;
				}
				case 3:
				{
					printf("Выбран пункт меню: Удалить запись \n");

					int index;

					printf("Выберите номер удаляемого элемента:\n");

					scanf_s("%d", &index);

					deleterecord(index);

					break;
				}
				case 4:
				{
					printf("Выбран пункт меню: Назад \n");

					goto main;

					break;
				}
				}
			}
			else
			{
				printf("Введите корректное значение\n");
			}

			goto correct;

			break;
		}
		case 4:
		{
			printf("Выбран пункт меню: Расчет \n");

			exec();

			break;
		}
		case 5:

			printf("Для выхода нажмите любую клавишу...\n");
			goto exit;
			break;
		}
	}
	else
	{
		printf("Введите корректное значение\n");
	}

	goto main;
	exit:_getch();
}


void addrecord(StudData Student)
{
	FILE* file;
	fopen_s(&file, currentfilename, "ab");
	if (!file)
	{
		puts("Невозможно создать файл");
		return;
	}

	fwrite(&Student, sizeof(StudData), 1, file);
	fclose(file);
}

void save_data(StudData* Student,int count)
{
	FILE* file;
	fopen_s(&file, currentfilename, "wb");
	if (!file)
	{
		puts("Невозможно создать файл");
		return;
	}

	fwrite(Student, sizeof(StudData), count, file);

	fclose(file);
}

int get_records_num()
{
	FILE   *in;
	fopen_s(&in, currentfilename, "rb");
	if (!in)
	{
		printf("Ошибка открытия файла\n");
	}

	fseek(in, 0, SEEK_END);

	int n = ftell(in) / sizeof(StudData);

	fclose(in);

	return n;
}

StudData* get_data()
{
	StudData Student;

	StudData* St = new StudData[get_records_num()];

	FILE   *in;
	fopen_s(&in, currentfilename, "rb");
	if (!in)
	{
		printf("Ошибка открытия файла\n");
	}

	int num = 0;
	while (fread(&Student, sizeof(StudData), 1, in))
	{
		if (feof(in)) printf("Ошибка чтения");
		
		St[num] = Student;
		num++;
	}

	fclose(in);

	return St;
}

void deleterecord(int number)
{
	StudData* St = get_data();

	int n = get_records_num();

	StudData* NewSt = new StudData[n-1];

	for (int i = 0; i < n-1; i++) //цикл для удаления заданной записи, начинаем
	{

		 //замещаем текущую запись следующей за ней
		if (i >= number-1)
		{
			*(NewSt+i) = *(St+i + 1);
		}

		else
		{
			*(NewSt + i) = *(St + i);
		}
	}


	save_data(NewSt, n - 1);

	delete[] St;
	delete[] NewSt;
}


void change_record(int index)
{
	StudData Student;
	StudData* St = get_data();
	int n = get_records_num();

	puts("Измените данные студента - (если изменять не требуется, то оставьте поле пустым):");
	printf("Фамилия Имя Отчество (через пробел):\n");
	gets_s(Student.FIO);
	gets_s(Student.FIO);
	printf("Номер группы (первая буква остальные 4 цифры):\n");
	gets_s(Student.GroupNumber);
	printf("Средний балл:\n");
	scanf_s("%lf", &Student.GPA);
	printf("Доход на одного члена семьи:\n");
	scanf_s("%lf", &Student.IncomePerFamMember);

	*(St + index - 1) = Student;

	save_data(St, n);

	delete[] St;
}


void exec()
{

	StudData* St = get_data();

	int n = get_records_num();

	StudData* Minzp = new StudData[n];
	StudData* Averange = new StudData[n];

	int j = 0;
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		if ((St + i)->IncomePerFamMember < MIN_ZP * 2)
		{
			///printf("%d | меньше чем 2 минималки \n", i + 1);

			*(Minzp + j) = *(St + i);
			j++;
		}

		else
		{
			//printf("%d | больше чем 2 минималки \n", i + 1);

			*(Averange + k) = *(St + i);
			k++;
		}
	}

	delete[] St;

	sort_data(Averange, k);




	printf("Лица с доходами на одного человека меньше 2-х минималок\n");
	print_data(Minzp,j);
	printf("Лица с доходами на одного человека больше или равно 2-ум минималкам\n");
	print_data(Averange, k);

	StudData* combined_mass = new StudData[j + k];

	combine_data(combined_mass, Minzp, Averange, j, k);


	//memcpy(Temp, Minzp, sizeof(StudData));
	//memcpy(Temp, Averange, sizeof(StudData));


	print_data(combined_mass, j+k);

	save_data(combined_mass, j + k);

	delete[] combined_mass;
	delete[] Minzp;
	delete[] Averange;
}

void sort_data(StudData* InData,int count)
{
	StudData temp;

	// Сортировка массива пузырьком
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if ((InData + j)->IncomePerFamMember < (InData + j + 1)->IncomePerFamMember)
			{
				// меняем элементы местами
				temp = *(InData + j);
				*(InData + j) = *(InData + j + 1);
				*(InData + j + 1) = temp;
			}
		}
	}
}

void combine_data(StudData* DestMass, StudData* FistMass, StudData* SecondMass, int first_count,int second_count)
{
	for (int i = 0; i < first_count; i++)
	{
		*(DestMass + i) = *(FistMass + i);
	}

	for (int i = 0; i < second_count; i++)
	{
		*(DestMass + i + first_count) = *(SecondMass + i);
	}
}


void print_data(StudData* InPrint,int count)
{
	printf("\n | num | ФИО | Номер группы | Средний балл | Доход на члена семьи |");
	printf("\n________________________________________________________________________________________");

	for (int i = 0; i < count; i++)
	{
		printf("\n | %5d | %25s | %7s | %.2lf | %.2lf", i + 1, (InPrint + i)->FIO, (InPrint + i)->GroupNumber, (InPrint + i)->GPA, (InPrint + i)->IncomePerFamMember);
	}
}
