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

	main:puts("������� ������ x y z (���� ���������� �������� ����� Space ��� Enter)");
	
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
			printf_s("\n������������ �� x,y,z = %.2lf \n����������� �������� �� x,y = %.2lf \n�������� m = %.3lf  \n\n", max, min, m);
		}

		else
		{
			printf_s("������� �� 0 ����������.\n��������� �� ����� ������� \n\n");

			goto main; // ������� �� ����� main
		}
	}
	else
	{
		printf_s("��������� ��� ��� ���������� �����. ����� ������������� ��� ������������ �������� ����������. �������� �� ����� ������� \n\n");

		goto main; // ������� �� ����� main
	}
}