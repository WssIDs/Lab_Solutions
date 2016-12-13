#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <process.h>
#include <malloc.h>
#include <stdlib.h>

/* Ввод массива new*/
int** insert_mass(int,int);
/* Вывод массива*/
void get_mass(int**, int,int);
/* Cортировка массива по главной диагонали*/
void sort_mass(int**, int, int);

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
		if (n == m)
		{
			puts("Ввод массива А");
			a = insert_mass(n, m);

			puts("\nВывод массива\n");
			get_mass(a, n, m);


			sort_mass(a, n, m);
			puts("\nВывод массива\n");
			get_mass(a, n, m);

			for (int i = 0; i < n; i++)
			{
				delete[] *(a+i);
			}

			delete[] a;
		}
		else
		{
			printf_s("Задача не имеет решения.");
			goto main;
		}

	}
	else
	{
		printf_s("Задача не имеет решения.");
		goto main;
	}

}


int** insert_mass(int n_mass_size,int m_mass_size)
{
	int **mass;

	if (!(mass = new int*[n_mass_size])) 
	{
		printf_s("Ошибка выделения памяти под массив\n");
		exit(0);
	}
		
	for (int i = 0; i < n_mass_size; i++)
	{
		if (!(*(mass + i) = new int[m_mass_size]))
		{
			printf_s("Ошибка выделения памяти под массив\n");
			mass = NULL;
			exit(0);
		}		
	}

	for (int i = 0; i < n_mass_size; i++)
	{
		for (int j = 0; j < m_mass_size; j++)
		{
			printf_s("Укажите значение строки [%d][%d]=:", i, j);

			//scanf_s("%d", *(mass + i) + j);

			*(*(mass + i) + j) = rand() % 10 +1;
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
			printf_s("|% d ", *(*(mass + i)+j));
		}

		printf_s("\n____________________________\n");
	}
}


void sort_mass(int** mass, int n_mass_size, int m_mass_size)
{
	for (int i = 0; i < n_mass_size/2; i++)
	{
		int temp = *(*(mass+i)+i);

		*(*(mass + i) + i) = *(*(mass + n_mass_size - 1 - i) + n_mass_size - 1 - i);

		*(*(mass + n_mass_size -1 - i)+n_mass_size - 1 - i) = temp;
	}
}