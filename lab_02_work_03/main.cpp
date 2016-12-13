#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <process.h>

void main()
{
	setlocale(LC_CTYPE, "Russian");

	double k, z;
	double x;
	double y;

	system("cls");

	puts("Введите данные k и z (Ввод следующего значения через Space или Enter)");

	fflush(stdin); //очистка памяти

	scanf_s("%lf %lf", &k, &z);

	if (k < 1)
	{
		x = k*pow(z, 3);
		printf_s("Вычисление по ветке 1: k<1 \n");
	}
	else
	{
		x = z*(z + 1);
		printf_s("Вычисление по ветке 2: k>=1 \n");
	}

		y = pow((log(1 + pow(x, 2))) + cos(x + 1), exp(k*x));
		printf_s("Значение y = %.2lf \n", y);
}