#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <process.h>
#include <malloc.h>

/* Ввод массива new*/
int* insert_mass(int);
/* Ввод массива malloc*/
int* insert_mass_malloc(int);
/* Ввод массива calloc*/
int* insert_mass_calloc(int);
/* Вывод массива*/
void get_mass(int*,int);
/* Cумма элементов*/
int summ(int*, int);

void main()
{
	setlocale(LC_CTYPE, "Russian");
	
	system("cls");

	int *a, *b;
	int summ1, summ2;
	int n,m;
	int method;

	main:puts("Укажите размерность массива A и B:");

	fflush(stdin);

	scanf_s("%d %d",&n,&m);

	puts("Укажите метод создания массива new=1 malloc=2 calloc=3 :");
	scanf_s("%d", &method);

	if (n > 1 || m > 1)
	{

		switch (method)
		{
			case 1: // new
				puts("Ввод массива А");
				a = insert_mass(n);

				summ1 = summ(a, n);
				printf_s("\n сумма элементов массива А = %d\n", summ1);

				puts("Ввод массива B");
				b = insert_mass(m);

				summ2 = summ(b, n);
				printf_s("\nсумма элементов массива B = %d\n", summ2);

				if (summ1 < summ2)
				{

					puts("\n сумма элементов массива А < суммы элементов массива B.");

					puts("\nВывод массива А");
					get_mass(a, n);

					puts("\nВывод массива B");
					get_mass(b, m);
				}

				else
				{
					puts("\n сумма элементов массива А > суммы элементов массива B.");

					puts("\nВывод массива B");
					get_mass(b, m);

					puts("\nВывод массива А");
					get_mass(a, n);
				}


				delete[]a;
				delete[]b;

				break;				

			case 2: // malloc
				puts("Ввод массива А");
				a = insert_mass_malloc(n);

				summ1 = summ(a, n);
				printf_s("\n сумма элементов массива А = %d\n", summ1);

				puts("Ввод массива B");
				b = insert_mass_malloc(m);

				summ2 = summ(b, n);
				printf_s("\nсумма элементов массива B = %d\n", summ2);

				if (summ1 < summ2)
				{

					puts("\n сумма элементов массива А < суммы элементов массива B.");

					puts("\nВывод массива А");
					get_mass(a, n);

					puts("\nВывод массива B");
					get_mass(b, m);
				}

				else
				{
					puts("\n сумма элементов массива А > суммы элементов массива B.");

					puts("\nВывод массива B");
					get_mass(b, m);

					puts("\nВывод массива А");
					get_mass(a, n);
				}


				free(a);
				free(b);

				break;

			case 3: // calloc 
				puts("Ввод массива А");
				a = insert_mass_calloc(n);

				summ1 = summ(a, n);
				printf_s("\n сумма элементов массива А = %d\n", summ1);

				puts("Ввод массива B");
				b = insert_mass_calloc(m);

				summ2 = summ(b, n);
				printf_s("\nсумма элементов массива B = %d\n", summ2);

				if (summ1 < summ2)
				{

					puts("\n сумма элементов массива А < суммы элементов массива B.");

					puts("\nВывод массива А");
					get_mass(a, n);

					puts("\nВывод массива B");
					get_mass(b, m);
				}

				else
				{
					puts("\n сумма элементов массива А > суммы элементов массива B.");

					puts("\nВывод массива B");
					get_mass(b, m);

					puts("\nВывод массива А");
					get_mass(a, n);
				}


				free(a);
				free(b);

				break;
		}

		goto main;

	}

	else
	{
		printf_s("укажите n>1 или m>1 \n\n");
		goto main;
	}
}

int* insert_mass(int mass_size)
{
	int *mass = new int[mass_size];

	if (mass == NULL)
	{
		printf_s("Ошибка выделения памяти под массив\n");
	}

	else 
	{
		for (int i = 0; i < mass_size; i++)
		{
			printf_s("Укажите значение строки [%d]=:", i + 1);
			scanf_s("%d", mass + i);
		}
	}
	
	return mass;
}


int* insert_mass_malloc(int mass_size)
{
	int* mass = (int*)malloc(mass_size*sizeof(int));


	if (mass == NULL)
	{
		printf_s("Ошибка выделения памяти под массив\n");
	}

	else
	{
		for (int i = 0; i < mass_size; i++)
		{
			printf_s("Укажите значение строки [%d]=:", i + 1);
			scanf_s("%d", mass + i);
		}
	}

	return mass;
}

int* insert_mass_calloc(int mass_size)
{
	int* mass = (int*)calloc(mass_size,sizeof(int));


	if (mass == NULL)
	{
		printf_s("Ошибка выделения памяти под массив\n");
	}

	else
	{
		for (int i = 0; i < mass_size; i++)
		{
			printf_s("Укажите значение строки [%d]=:", i + 1);
			scanf_s("%d", mass + i);
		}
	}

	return mass;
}


void get_mass(int* mass,int size_mass)
{
	for (int i = 0; i < size_mass; i++)
	{
		printf_s("%d\n",*(mass + i));
	}
}

int summ(int* mass, int size_mass)
{
	int summ = 0;

	for (int i = 0; i < size_mass; i++)
	{
		summ += *(mass + i);
	}

	return summ;
}

