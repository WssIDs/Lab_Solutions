#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <process.h>
#include <malloc.h>
#include <stdlib.h>  // позволяет использовать rand()

/* Ввод массива new*/
int** insert_mass(int, int);
/* Вывод массива*/
void get_mass(int**, int, int);
/* Поиск нулей в строке*/
int get_count_zero(int**, int, int);

void main()
{
	setlocale(LC_CTYPE, "Russian");

	system("cls");

	int **a;
	int n, m;

	main:puts("Укажите размерность двумерного масмассива A n*m:");

	fflush(stdin);

	scanf_s("%d %d", &n, &m);

	if (n > 1 && m > 1)
	{
			puts("Ввод массива");
			a = insert_mass(n, m);

			puts("\nВывод массива\n");
			get_mass(a, n, m);

			if (n-get_count_zero(a, n, m) != 0)
			{
				printf_s("Количество строк не содержащих 0 :%d \n\n", n - get_count_zero(a, n, m));
			}
			else
			{
				printf_s("Во всех строках присутвует ноль \n");
			}

			free(a);

	}
	else
	{
		printf_s("Задача не имеет решения.");
		goto main;
	}

}

int** insert_mass(int n_mass_size, int m_mass_size)
{
	int **mass;

	if (!(mass = (int**)malloc(sizeof(int*)*n_mass_size)))
	{
		printf_s("Ошибка выделения памяти под массив\n");
		exit(0);
	}
	
	for (int i = 0; i < n_mass_size; i++)
	{
		if (!(*(mass + i) = (int*)malloc(sizeof(int)*m_mass_size)))
		{
			printf_s("Ошибка выделения памяти под массив\n");
			mass = NULL;
			exit(0);
		}
	}
		//if (!(mass = new int*[n_mass_size]))
		//{
		//	printf_s("Ошибка выделения памяти под массив\n");
		//	exit(0);
		//}

		//for (int i = 0; i < n_mass_size; i++)
		//{
		//	if (!(*(mass + i) = new int[m_mass_size]))
		//	{
		//		printf_s("Ошибка выделения памяти под массив\n");
		//		mass = NULL;
		//		exit(0);
		//	}
		//}

	for (int i = 0; i < n_mass_size; i++)
	{
		for (int j = 0; j < m_mass_size; j++)
		{
			printf_s("Укажите значение строки [%d][%d]=:", i, j);
			scanf_s("%d", *(mass + i) + j);
			
			//*(*(mass + i) + j) = rand() % 10 + 1; //генерация случайного числа
		}
	}

	return mass;
}

void get_mass(int** mass, int n_mass_size, int m_mass_size)
{
	printf_s("\n____________________________\n");

	for (int i = 0; i < n_mass_size; i++)
	{
		for (int j = 0; j < m_mass_size; j++)
		{
			printf_s("|% d ", *(*(mass + i) + j));
		}

		printf_s("\n____________________________\n");
	}
}


int get_count_zero(int** mass, int n_mass_size, int m_mass_size)
{
	int count = 0;

	for (int i = 0; i < n_mass_size; i++)
	{
		for (int j = 0; j < m_mass_size; j++)
		{
			if (*(*(mass + i) + j) == 0)
			{
				count++;
				break;
			}
			
		}
	}

	return count;
}