#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <process.h>
#include <malloc.h>

/* Ввод массива new*/
int* insert_mass(int);
/* Вывод массива*/
void get_mass(int*, int);
/* Произведение элементов м/у максимальным и минимальным значением */
int contenporary(int*,int);


void main()
{
	setlocale(LC_CTYPE, "Russian");

	system("cls");

	int *a;
	int n;

	main:puts("Укажите размерность массива:");

	fflush(stdin);

	scanf_s("%d", &n);

	if (n > 2)
	{
		puts("Ввод массива");
		a = insert_mass(n);

		printf_s("произведение: %d\n", contenporary(a,n));

		goto main;
	}
	else
	{
		printf_s("укажите n>2 Задача не имеет решения \n\n");
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

void get_mass(int* mass, int size_mass)
{
	for (int i = 0; i < size_mass; i++)
	{
		printf_s("%d\n", *(mass + i));
	}
}


int contenporary(int* mass,int size_mass)
{
	int max, min;
	int maxID, minID;
	int cont; // произведение

	max = *(mass);
	min = *(mass);

	fflush(stdin);

	minID = 0;
	maxID = 0;

	for (int i = 0; i < size_mass; i++)
	{
		if (max < *(mass + i))
		{
			max = *(mass + i);
			maxID = i;
		}

		else if (max > *(mass + i))
		{
			min = *(mass + i);
			minID = i;
		}
	}
	cont = 1;

	if (minID > maxID)
	{
		int b = maxID;
		maxID = minID;
		minID = b;
	}

	printf_s("minID = %d\n", minID);
	printf_s("maxID = %d\n", maxID);

	int i = 0;

	minID += 1;

	for (minID; minID < maxID; minID++)
	{
		printf_s("значение: %d\n", *(mass + minID));
		cont*=*(mass + minID);
	}

	return cont;
}