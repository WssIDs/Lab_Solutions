#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <process.h>

#define PI 3.14159 // объявление Пи

void main()
{
	setlocale(LC_CTYPE, "Russian");

	double x, y, z;
	double t;

	system("cls"); // очистка экрана

	puts("Введите данные x y z (Ввод следующего значения через Space или Enter)");

	fflush(stdin); //очистка памяти

	/* Значения по умолчанию */
	x = 14.26;
	y = -1.22;
	z = 3.5e-2;

	if (!scanf_s("%lf %lf %lf", &x, &y, &z))
	{
		printf_s("Введены некорректные данные. Программа будет использовать значения по умолчанию x = %.2lf | y = %.2lf | z = %.2lf \n\n", x, y, z);
	}

	t = 2 * cos(x - PI / 6) / (0.5 + pow(sin(y), 2))*(1 + (pow(z, 2) / (3 - pow(z, 2) / 5)));

	printf_s("\tt= %.3lf \n\n", t);
}