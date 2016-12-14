#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <process.h>
#include <windows.h>
#include <string.h>
#include <malloc.h>
#include <fcntl.h>

struct Notebook_size // ���������� �������
{
	double �;
	double y;
	double z;
};


struct NOTEBOOK
{
	char model[21]; // ������������ 
	Notebook_size size;
	double w;	// ���
	int price;  // ���� 
};

/* ��� ���������� ����� */
char* infilename = "note.txt";

/* ��� ��������� ����� */
char* outfilename = "note.dat";

/*	�������� ������ � �������� ���� */
void addrecord(NOTEBOOK);

/*	������� ���� � �������� �������� 0 � ������ 2 ����� ��������� ����� ���� �� ������ �������� ��������*/
void create_file(char*);

/*	��������� ������ � �������� ���� */
void save_data(NOTEBOOK*, short);

/*	������ ������ �� ���������� ����� � ���������� � �������� ���� */
void get_data();

/*	������ ������ �� ��������� ����� */
void get_data_binary(NOTEBOOK*,short*);

/*����� �� ����� ������*/
void print_data(NOTEBOOK*,short);

/* ���������� ���� �� �������� */
void sort_data(NOTEBOOK*, short);

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool bmenu = true;

	while (bmenu) // ���� true
	{
		int input_number = 0;

		puts("������� ����:");
		puts("___________________________________________________________");
		puts("1 - ������� ������ �� ���������� ����� � �������� � ��������\n � ������� �� �����");
		puts("2 - ���������� ��� �� �������� � ������ � �������� ����");
		puts("3 - ������� ������ �� ��������� ����� � ������� �� �����");
		puts("0 - �����");

		puts("\n�������� ����� ����:");

		scanf_s("%d", &input_number);

		if (input_number == 1)
		{
			get_data();
		}

		else if (input_number == 2)
		{
			NOTEBOOK* notebooks = (NOTEBOOK*)calloc(100, sizeof(NOTEBOOK));

			short int number = 0;

			get_data_binary(notebooks, &number);

			sort_data(notebooks, number);

			save_data(notebooks, number);


		}

		else if (input_number == 3)
		{

			NOTEBOOK* notebooks = (NOTEBOOK*)calloc(100, sizeof(NOTEBOOK));

			short int number = 0;

			get_data_binary(notebooks, &number);

			print_data(notebooks,number);
		}

		else if (input_number == 0)
		{
			bmenu = false;
		}

	}

	puts("������� ����� ������� ��� ������...");
	_getch();
}


void create_file(char* filename)
{
	FILE* bfile;
	short count = 0;
	
	fopen_s(&bfile,filename, "rb"); // ��������� ��� ������ �������� ����
	if (bfile == NULL)
	{
		//printf("���� �� ������. ������� �������� �����...\n");
		
		fopen_s(&bfile,filename, "wb");
		if (bfile == NULL) 
		{
			printf("������ �������� �����\n");
		}

		else if (bfile != NULL)
		{
			fwrite(&count, sizeof(short), 1, bfile);
		}
	}

	fclose(bfile);
}

void save_data(NOTEBOOK* notebooks, short count)
{
	FILE* file;

	fopen_s(&file, outfilename, "w+b");
	if (!file)
	{
		puts("���������� ������� ����");
		return;
	}

	fwrite(&count, sizeof(short), 1, file);

	fseek(file, 2, SEEK_SET);

	fwrite(notebooks, sizeof(NOTEBOOK), count, file);

	fclose(file);
}


void addrecord(NOTEBOOK Notebook)
{
	FILE* file;

	fopen_s(&file, outfilename, "r+b");
	if (!file)
	{
		puts("���������� ������� ����");
		return;
	}
	
	short int count = 0;

	fread(&count, sizeof(short int), 1, file);
	
	fclose(file);	
	
	//printf("count = %d\n", count);

	fopen_s(&file, outfilename, "a+b");
	if (!file)
	{
		puts("���������� ������� ����");
		return;
	}
	
	fwrite(&Notebook, sizeof(NOTEBOOK), 1, file);

	fclose(file);

	fopen_s(&file, outfilename, "rb+");
	if (!file)
	{
		puts("���������� ������� ����");
		return;
	}

	count++;

	fwrite(&count, sizeof(short int), 1, file);

	fclose(file);
}

void get_data()
{
	FILE* file;

	fopen_s(&file, infilename, "r");
	if (!file)
	{
		puts("���������� ��������� ����");
		return;
	}

	char* Mainstr = (char*)calloc(100, sizeof(char));

	NOTEBOOK notebok;

	NOTEBOOK* notebooks = (NOTEBOOK*)calloc(100, sizeof(NOTEBOOK));

	short int notebook_counts = 0;

	while (fgets(Mainstr, 100, file))
	{

		char* frequency_m = (char*)calloc(4, sizeof(char));

		for (int i = 0; i < 3; i++)
		{
			*(frequency_m + i) = *(Mainstr + 43 + i);
		}

		// ������� ��������
		int frequency = atoi(frequency_m);

		if (frequency > 120) // ��������� ���� ������� ������ 120
		{

			// ������ �������
			
			char* model_m = (char*)calloc(30, sizeof(char));

			for (int i = 0; i < 19; i++)
			{
				*(model_m + i) = *(Mainstr + i);
			}


			strcpy_s(notebok.model, model_m);


			// ������� �������

			char* size_m = (char*)calloc(50, sizeof(char));

			for (int i = 0; i < 14; i++)
			{
				*(size_m + i) = *(Mainstr + 29 + i);
			}

			char* contex1;
			
			double* size_notebook = (double*)calloc(3, sizeof(double));
			
			char * pch = strtok_s(size_m, "x", &contex1);
			
			int count_size = 0;

			while (pch != NULL)   // ���� ���� �������
			{
				*(size_notebook + count_size) = atof(pch);
				pch = strtok_s(NULL, "x", &contex1);
				count_size++;
			}

			// ������ X
			notebok.size.� = *(size_notebook);
			// ������ Y
			notebok.size.y = *(size_notebook + 1);
			// ������ Z
			notebok.size.z = *(size_notebook + 2);


			// ���� ��������

			char* price_m = (char*)calloc(5, sizeof(char));

			for (int i = 0; i < 4; i++)
			{
				*(price_m + i) = *(Mainstr + 20 + i);
			}

			notebok.price = atoi(price_m);

			// ��� ��������

			char* weight_m = (char*)calloc(5, sizeof(char));

			for (int i = 0; i < 3; i++)
			{
				*(weight_m + i) = *(Mainstr + 25 + i);
			}

			notebok.w = atof(weight_m);

			
			*(notebooks + notebook_counts) = notebok; // ��������� � ������ ���������

			notebook_counts++; // �������� ������� ���������
		}
	}

	fclose(file);


	create_file(outfilename); 

	for (int i = 0; i < notebook_counts; i++)
	{
		addrecord(*(notebooks + i)); // ��������� ������ � �������� ����
	}
}

void sort_data(NOTEBOOK* notebooks, short count)
{
	NOTEBOOK temp;

	// ���������� ������� ���������
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if ((notebooks + j)->price < (notebooks + j + 1)->price)
			{
				// ������ �������� �������
				temp = *(notebooks + j);
				*(notebooks + j) = *(notebooks + j + 1);
				*(notebooks + j + 1) = temp;
			}
		}
	}
}



void get_data_binary(NOTEBOOK* notebooks, short* count)
{
	NOTEBOOK notebook;

	FILE   *in;
	fopen_s(&in, outfilename, "rb+");
	if (!in)
	{
		printf("������ �������� �����\n");
	}
	
	// ������ ������ 2-� ������

	fread(count, sizeof(short int), 1, in);

	//printf("%d", *count);

	// ������ �������� ������
	
	int num = 0;
	
	while (fread(&notebook, sizeof(NOTEBOOK), 1, in))
	{
		if (feof(in)) printf("������ ������");

		notebooks[num] = notebook;
		num++; // ������� ���������� �������
	}

	fclose(in);
}


void print_data(NOTEBOOK* notebooks, short count)
{
	printf("\n");

	printf("| � |	������ ��������		|	�������	  | ��� | ���� |\n");
	printf("________________________________________________________________\n");

	for (int i = 0; i < count; i++)
	{
		printf("|%3d|%20s	|%5.1lfx%5.1lfx%5.1lf|%5.1lf|%6d|\n", i + 1, (notebooks + i)->model, notebooks[i].size.�, notebooks[i].size.y, notebooks[i].size.z, notebooks[i].w, notebooks[i].price);
	}

	printf("________________________________________________________________\n");
	printf("\n");
}