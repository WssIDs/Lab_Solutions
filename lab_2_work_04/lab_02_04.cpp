#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <process.h>


void main()
{
	setlocale(LC_CTYPE, "Russian");

	double x, y, z;
	double min, max;
	double m;

	system("cls");

	main:puts("Введите данные x y z (Ввод следующего значения через Space или Enter)");
	
	fflush(stdin);	
	
	scanf_s("%lf %lf %lf", &x, &y, &z);

	max = x;
	min = x;

	if (x!= y && y!=z && x!=z)
	{
		(y > max) ? max = y : min = y;

		if (min != 0)
		{

			if (z > max)
			{
				max = z;
			}

			m = max / min + 5;
			printf_s("\nМаксимальное из x,y,z = %.2lf \nМинимальное значение из x,y = %.2lf \nЗначение m = %.3lf  \n\n", max, min, m);
		}

		else
		{
			printf_s("Деление на 0 невозможно.\nПрограмма не имеет решения \n\n");

			goto main; // переход по метке main
		}
	}
	else
	{
		printf_s("Несколько или все переменные равны. Поиск максимального или минимального значения невозможен. Програма не имеет решения \n\n");

		goto main; // переход по метке main
	}
}