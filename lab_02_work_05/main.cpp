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

	puts("������� ������ k m (���� ���������� �������� ����� Space ��� Enter)");

	fflush(stdin);

	scanf_s("%lf %lf", &k, &m);

	if (k >= 0 && k < m)
	{
		printf_s(" 0<=k<m ������� �� ����� 1. \n");
		t2 = pow(sin(5*k+3*m*log(fabs(k))), 2);
		printf_s("t2 = %lf \n", t2);

	}

	else if (k >= m)
	{
		printf_s("k >= m ������� �� ����� 2. \n");
		t2 = pow(cos(5*k+3*m*log(fabs(k))), 2);
		printf_s("t2 = %lf \n", t2);
	}
	else
	{
		printf_s("k = 0. ����� 3. ������� ���. \n");
	}
}