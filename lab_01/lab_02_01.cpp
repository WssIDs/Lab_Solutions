#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <process.h>

#define PI 3.14159 // ���������� ��

void main()
{
	setlocale(LC_CTYPE,"Russian"); // ��������� ���������
	
	double a; // ���� �����
	double z1, z2;

	system("cls");

	puts("������� ���� a:");
	
	fflush(stdin); //������� ������

	scanf_s("%lf", &a);

	z1 = 2 * pow(sin(3 * PI - 2 * a), 2)*pow(cos(5 * PI + 2 * a), 2);
	z2 = 1. / 4 - 1. / 4 * sin(5. / 2 * PI - 8 * a);

	printf_s("\tz1= %.3lf \n\tz2= %.3lf \n\n",z1,z2);
}