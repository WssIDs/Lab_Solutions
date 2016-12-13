#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <process.h>
#include <windows.h>
#include <string.h>
#include <malloc.h>


#define MIN_ZP 230.00 // ����������� ���������� �����

/* ������� ��� ����� */
char currentfilename[10] = "studs.dat";

struct StudData 
{
	char FIO[100];
	char GroupNumber[6];
	double GPA;
	double IncomePerFamMember;
};


/* ��������� ���������� ������� � ����� */
int get_records_num();

/* ���������� ������ � ���� */
void addrecord(StudData);

/* ��������� ������ �� ����� */
StudData* get_data();

/* ������ ������ � ���� */
void save_data(StudData*,int);

/* �������� ������ �� ����� */
void deleterecord(int);

/* ��������� ������ */
void change_record(int);

/* ���������� ������� �� �������� */
void sort_data(StudData*,int);

/* ����������� 2-�� �������� */
void combine_data(StudData*,StudData*, StudData*, int,int);

/* ���������� ������� */
void exec();

/* ����� �� ����� */
void print_data(StudData*,int);

void main()
{
	int n;

	//setlocale(LC_CTYPE, "Russian");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	main:puts("\n---------------------");
	puts("������� ����:");
	puts("---------------------");
	printf("1 - ������� ����� ���� \n");
	printf("2 - ��������� ����� \n");
	printf("3 - ������������� ������ \n");
	printf("4 - ������ \n");
	printf("5 - �����\n");
	puts("�������� �����:");

	fflush(stdin);

	scanf_s("%d", &n);

	if (n > 0 && n <= 5)
	{
		switch (n)
		{
		case 1:
		{
			printf("������ ����� ����: ������� ����� ���� \n");

			FILE* file;
			fopen_s(&file, currentfilename, "wb");
			if (!file)
			{
				puts("���������� ������� ����");
				return;
			}

			fclose(file);

			break;
		}
		case 2:
		{
			printf("������ ����� ����: �������� ����� \n");

			int num = get_records_num();

			StudData* St = new StudData[num];
			St = get_data();

			print_data(St, num);

			delete[] St;

			break;
		}
		case 3:
		{
			int m;

			correct:puts("\n---------------------");
			puts("���� ��������������:");
			puts("---------------------");

			int num = get_records_num();

			StudData* St = new StudData[num];
			St = get_data();

			print_data(St, num);

			delete[] St;

			printf("\n1 - �������� ������\n");
			printf("2 - �������� ������\n");
			printf("3 - ������� ������\n");
			printf("4 - �����\n");
			puts("�������� �����:");

			fflush(stdin);

			scanf_s("%d", &m);

			if (m > 0 && m <= 4)
			{
				switch (m)
				{
				case 1:
				{
					printf("������ ����� ����: �������� ������ \n");

					StudData Student;

					puts("������� ������ ��������:");
					
					printf("������� ��� �������� (����� ������):\n");
					gets_s(Student.FIO);
					gets_s(Student.FIO);
					
					printf("����� ������ (������ ����� ��������� 4 �����):\n");
					gets_s(Student.GroupNumber);
					
					printf("������� ����:\n");
					scanf_s("%lf", &Student.GPA);
					
					printf("����� �� ������ ����� �����:\n");
					scanf_s("%lf", &Student.IncomePerFamMember);

					addrecord(Student);

					break;
				}
				case 2:
				{
					printf("������ ����� ����: ������������� ������ \n");

					int index;

					printf("�������� ����� �������������� ��������:\n");

					scanf_s("%d", &index);

					change_record(index);

					break;
				}
				case 3:
				{
					printf("������ ����� ����: ������� ������ \n");

					int index;

					printf("�������� ����� ���������� ��������:\n");

					scanf_s("%d", &index);

					deleterecord(index);

					break;
				}
				case 4:
				{
					printf("������ ����� ����: ����� \n");

					goto main;

					break;
				}
				}
			}
			else
			{
				printf("������� ���������� ��������\n");
			}

			goto correct;

			break;
		}
		case 4:
		{
			printf("������ ����� ����: ������ \n");

			exec();

			break;
		}
		case 5:

			printf("��� ������ ������� ����� �������...\n");
			goto exit;
			break;
		}
	}
	else
	{
		printf("������� ���������� ��������\n");
	}

	goto main;
	exit:_getch();
}


void addrecord(StudData Student)
{
	FILE* file;
	fopen_s(&file, currentfilename, "ab");
	if (!file)
	{
		puts("���������� ������� ����");
		return;
	}

	fwrite(&Student, sizeof(StudData), 1, file);
	fclose(file);
}

void save_data(StudData* Student,int count)
{
	FILE* file;
	fopen_s(&file, currentfilename, "wb");
	if (!file)
	{
		puts("���������� ������� ����");
		return;
	}

	fwrite(Student, sizeof(StudData), count, file);

	fclose(file);
}

int get_records_num()
{
	FILE   *in;
	fopen_s(&in, currentfilename, "rb");
	if (!in)
	{
		printf("������ �������� �����\n");
	}

	fseek(in, 0, SEEK_END);

	int n = ftell(in) / sizeof(StudData);

	fclose(in);

	return n;
}

StudData* get_data()
{
	StudData Student;

	StudData* St = new StudData[get_records_num()];

	FILE   *in;
	fopen_s(&in, currentfilename, "rb");
	if (!in)
	{
		printf("������ �������� �����\n");
	}

	int num = 0;
	while (fread(&Student, sizeof(StudData), 1, in))
	{
		if (feof(in)) printf("������ ������");
		
		St[num] = Student;
		num++;
	}

	fclose(in);

	return St;
}

void deleterecord(int number)
{
	StudData* St = get_data();

	int n = get_records_num();

	StudData* NewSt = new StudData[n-1];

	for (int i = 0; i < n-1; i++) //���� ��� �������� �������� ������, ��������
	{

		 //�������� ������� ������ ��������� �� ���
		if (i >= number-1)
		{
			*(NewSt+i) = *(St+i + 1);
		}

		else
		{
			*(NewSt + i) = *(St + i);
		}
	}


	save_data(NewSt, n - 1);

	delete[] St;
	delete[] NewSt;
}


void change_record(int index)
{
	StudData Student;
	StudData* St = get_data();
	int n = get_records_num();

	puts("�������� ������ �������� - (���� �������� �� ���������, �� �������� ���� ������):");
	printf("������� ��� �������� (����� ������):\n");
	gets_s(Student.FIO);
	gets_s(Student.FIO);
	printf("����� ������ (������ ����� ��������� 4 �����):\n");
	gets_s(Student.GroupNumber);
	printf("������� ����:\n");
	scanf_s("%lf", &Student.GPA);
	printf("����� �� ������ ����� �����:\n");
	scanf_s("%lf", &Student.IncomePerFamMember);

	*(St + index - 1) = Student;

	save_data(St, n);

	delete[] St;
}


void exec()
{

	StudData* St = get_data();

	int n = get_records_num();

	StudData* Minzp = new StudData[n];
	StudData* Averange = new StudData[n];

	int j = 0;
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		if ((St + i)->IncomePerFamMember < MIN_ZP * 2)
		{
			///printf("%d | ������ ��� 2 ��������� \n", i + 1);

			*(Minzp + j) = *(St + i);
			j++;
		}

		else
		{
			//printf("%d | ������ ��� 2 ��������� \n", i + 1);

			*(Averange + k) = *(St + i);
			k++;
		}
	}

	delete[] St;

	sort_data(Averange, k);




	printf("���� � �������� �� ������ �������� ������ 2-� ���������\n");
	print_data(Minzp,j);
	printf("���� � �������� �� ������ �������� ������ ��� ����� 2-�� ����������\n");
	print_data(Averange, k);

	StudData* combined_mass = new StudData[j + k];

	combine_data(combined_mass, Minzp, Averange, j, k);


	//memcpy(Temp, Minzp, sizeof(StudData));
	//memcpy(Temp, Averange, sizeof(StudData));


	print_data(combined_mass, j+k);

	save_data(combined_mass, j + k);

	delete[] combined_mass;
	delete[] Minzp;
	delete[] Averange;
}

void sort_data(StudData* InData,int count)
{
	StudData temp;

	// ���������� ������� ���������
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if ((InData + j)->IncomePerFamMember < (InData + j + 1)->IncomePerFamMember)
			{
				// ������ �������� �������
				temp = *(InData + j);
				*(InData + j) = *(InData + j + 1);
				*(InData + j + 1) = temp;
			}
		}
	}
}

void combine_data(StudData* DestMass, StudData* FistMass, StudData* SecondMass, int first_count,int second_count)
{
	for (int i = 0; i < first_count; i++)
	{
		*(DestMass + i) = *(FistMass + i);
	}

	for (int i = 0; i < second_count; i++)
	{
		*(DestMass + i + first_count) = *(SecondMass + i);
	}
}


void print_data(StudData* InPrint,int count)
{
	printf("\n | num | ��� | ����� ������ | ������� ���� | ����� �� ����� ����� |");
	printf("\n________________________________________________________________________________________");

	for (int i = 0; i < count; i++)
	{
		printf("\n | %5d | %25s | %7s | %.2lf | %.2lf", i + 1, (InPrint + i)->FIO, (InPrint + i)->GroupNumber, (InPrint + i)->GPA, (InPrint + i)->IncomePerFamMember);
	}
}
