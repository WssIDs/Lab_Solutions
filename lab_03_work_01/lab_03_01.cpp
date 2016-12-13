#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <process.h>

/* Функция нахождения факториала через переменные */
int getfact(int);
/* Функция нахождения факториала через указатели */
void getfact(int*,int);
/* Функция нахождения факториала через ссылки */
void getfact(int&, int);

void main()
{
	setlocale(LC_CTYPE, "Russian");

	double a, b, h;
	int n, method;
	double x;


	system("cls");

	main:puts("Введите данные a b h n (Ввод следующего значения через Space или Enter)");

	fflush(stdin);

	scanf_s("%lf %lf %lf %d", &a,&b,&h,&n);

	x = a;

	puts("\n Произвести расчет используя переменные = 1, указатели = 2, ссылки = 3 :");
	scanf_s("%d", &method);

	printf_s("\n|  X   |   Y  |   S  ||Y-S| |\n");
	printf_s("_____________________________\n");

	switch (method)
	{
		case 1: // Расчет через переменные
		{
			while (x <= b)
			{
				double s = 0;

				for (int k = 0; k <= n; k++)
				{
					int fact = getfact(2 * k + 1);
					s += pow(-1., k)*pow(x, (2 * k + 1)) / fact;
				}

				double y = sin(x);
				double delta = fabs(y - s);

				printf_s("| %.2lf | %.2lf | %.2lf | %.2lf |\n", x, y, s, delta);
				x += h;
			}

			break;
		}

		case 2: // Расчет через указатели
		{
			double *p_x = &x; 

			while (*p_x <= b)
			{
				double s =0;
				double *summ = &s;

				for (int k = 0; k <= n; k++)
				{
					int fact = 1;
					
					int* m_fact;
					
					m_fact = &fact;
					
					getfact(m_fact, 2 * k + 1);
					
					(*summ) += pow(-1., k)*pow(*p_x, (2 * k + 1)) / *m_fact;
				}

				double y = sin(*p_x);
				
				double *p_y = &y;

				double delta = 0;
				
				double *p_delta = &delta;

				*p_delta = fabs(*p_y - *summ);

				printf_s("| %.2lf | %.2lf | %.2lf | %.2lf |\n", x, y, s, delta);
				*p_x += h;
			}

			break;
		}

		case 3: //Решение через ссылки
		{
			double &ref_x = x;

			while (ref_x <= b)
			{
				double s = 0;
				double &summ = s;

				for (int k = 0; k <= n; k++)
				{
					int fact = 1;
					int &m_fact = fact;

					getfact(m_fact, 2 * k + 1);
					summ += pow(-1., k)*pow(ref_x, (2 * k + 1)) / m_fact;
				}

				double y = sin(ref_x);
				double delta = 0;
				double &ref_y = y;
				double &ref_delta = delta;

				ref_delta = fabs(ref_y - summ);

				printf_s("| %.2lf | %.2lf | %.2lf | %.2lf |\n", x, y, s, delta);
				ref_x += h;
			}

			break;
		}
	}

	printf_s("____________________________\n");

	goto main;
}


int getfact(int n)
{
	int fact = 1;

	for (int i = 1; i <= n; i++)
	{
		fact *= i;
	}
	
	return fact;
}


void getfact(int *fact,int n)
{
	*fact = 1;

	for (int i = 1; i <= n; i++)
	{
		(*fact)*= i;
	}
}


void getfact(int &fact, int n)
{
	fact = 1;

	for (int i = 1; i <= n; i++)
	{
		fact *= i;
	}
}