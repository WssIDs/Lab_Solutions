#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <process.h>
#include <malloc.h>

/* ���� ������� new*/
int* insert_mass(int);
/* ���� ������� malloc*/
int* insert_mass_malloc(int);
/* ���� ������� calloc*/
int* insert_mass_calloc(int);
/* ����� �������*/
void get_mass(int*,int);
/* C���� ���������*/
int summ(int*, int);

void main()
{
	setlocale(LC_CTYPE, "Russian");
	
	system("cls");

	int *a, *b;
	int summ1, summ2;
	int n,m;
	int method;

	main:puts("������� ����������� ������� A � B:");

	fflush(stdin);

	scanf_s("%d %d",&n,&m);

	puts("������� ����� �������� ������� new=1 malloc=2 calloc=3 :");
	scanf_s("%d", &method);

	if (n > 1 || m > 1)
	{

		switch (method)
		{
			case 1: // new
				puts("���� ������� �");
				a = insert_mass(n);

				summ1 = summ(a, n);
				printf_s("\n ����� ��������� ������� � = %d\n", summ1);

				puts("���� ������� B");
				b = insert_mass(m);

				summ2 = summ(b, n);
				printf_s("\n����� ��������� ������� B = %d\n", summ2);

				if (summ1 < summ2)
				{

					puts("\n ����� ��������� ������� � < ����� ��������� ������� B.");

					puts("\n����� ������� �");
					get_mass(a, n);

					puts("\n����� ������� B");
					get_mass(b, m);
				}

				else
				{
					puts("\n ����� ��������� ������� � > ����� ��������� ������� B.");

					puts("\n����� ������� B");
					get_mass(b, m);

					puts("\n����� ������� �");
					get_mass(a, n);
				}


				delete[]a;
				delete[]b;

				break;				

			case 2: // malloc
				puts("���� ������� �");
				a = insert_mass_malloc(n);

				summ1 = summ(a, n);
				printf_s("\n ����� ��������� ������� � = %d\n", summ1);

				puts("���� ������� B");
				b = insert_mass_malloc(m);

				summ2 = summ(b, n);
				printf_s("\n����� ��������� ������� B = %d\n", summ2);

				if (summ1 < summ2)
				{

					puts("\n ����� ��������� ������� � < ����� ��������� ������� B.");

					puts("\n����� ������� �");
					get_mass(a, n);

					puts("\n����� ������� B");
					get_mass(b, m);
				}

				else
				{
					puts("\n ����� ��������� ������� � > ����� ��������� ������� B.");

					puts("\n����� ������� B");
					get_mass(b, m);

					puts("\n����� ������� �");
					get_mass(a, n);
				}


				free(a);
				free(b);

				break;

			case 3: // calloc 
				puts("���� ������� �");
				a = insert_mass_calloc(n);

				summ1 = summ(a, n);
				printf_s("\n ����� ��������� ������� � = %d\n", summ1);

				puts("���� ������� B");
				b = insert_mass_calloc(m);

				summ2 = summ(b, n);
				printf_s("\n����� ��������� ������� B = %d\n", summ2);

				if (summ1 < summ2)
				{

					puts("\n ����� ��������� ������� � < ����� ��������� ������� B.");

					puts("\n����� ������� �");
					get_mass(a, n);

					puts("\n����� ������� B");
					get_mass(b, m);
				}

				else
				{
					puts("\n ����� ��������� ������� � > ����� ��������� ������� B.");

					puts("\n����� ������� B");
					get_mass(b, m);

					puts("\n����� ������� �");
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
		printf_s("������� n>1 ��� m>1 \n\n");
		goto main;
	}
}

int* insert_mass(int mass_size)
{
	int *mass = new int[mass_size];

	if (mass == NULL)
	{
		printf_s("������ ��������� ������ ��� ������\n");
	}

	else 
	{
		for (int i = 0; i < mass_size; i++)
		{
			printf_s("������� �������� ������ [%d]=:", i + 1);
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
		printf_s("������ ��������� ������ ��� ������\n");
	}

	else
	{
		for (int i = 0; i < mass_size; i++)
		{
			printf_s("������� �������� ������ [%d]=:", i + 1);
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
		printf_s("������ ��������� ������ ��� ������\n");
	}

	else
	{
		for (int i = 0; i < mass_size; i++)
		{
			printf_s("������� �������� ������ [%d]=:", i + 1);
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

