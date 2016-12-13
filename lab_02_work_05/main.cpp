#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <process.h>


void main()
{
	setlocale(LC_CTYPE, "Russian");

	double k, m;
	double t2;

	system("cls");

	puts("Введите данные k m (Ввод следующего значения через Space или Enter)");

	fflush(stdin);

	scanf_s("%lf %lf", &k, &m);

	if (k >= 0 && k < m)
	{
		printf_s(" 0<=k<m Решение по ветке 1. \n");
		t2 = pow(sin(5*k+3*m*log(fabs(k))), 2);
		printf_s("t2 = %lf \n", t2);

	}

	else if (k >= m)
	{
		printf_s("k >= m Решение по ветке 2. \n");
		t2 = pow(cos(5*k+3*m*log(fabs(k))), 2);
		printf_s("t2 = %lf \n", t2);
	}
	else
	{
		printf_s("k = 0. Ветка 3. Решений нет. \n");
	}
}