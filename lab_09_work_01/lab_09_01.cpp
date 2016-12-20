#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <process.h>
#include <windows.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>


struct Stack {
	int info;
	Stack *Next;
};


int random(int, int);
Stack* Create(Stack*);
Stack* CreateInt(Stack*, int);
void View(Stack*);
void Delete_Stack(Stack**);


void Spilt_Stack(Stack*,Stack*,Stack*);

void main()
{
	setlocale(LC_CTYPE, "Russian");

	Stack *begin = NULL;
	Stack *plus_begin = NULL;
	Stack *minus_begin = NULL;

	bool bmenu = true;

	while (bmenu) // пока true
	{
		int input_number = 0;

		puts("Главное меню:");
		puts("___________________________________________________________");
		puts("1 - Записать данные в стек");
		puts("2 - Просмотр стека");
		puts("3 - Разделить список на положительные и отрицательные");
		puts("0 - Выход");

		puts("\nВыберите пункт меню:");

		scanf_s("%d", &input_number);

		if (input_number == 1)
		{
			int repeat;

			printf("Количество элементов списка:\n");
			scanf_s("%d", &repeat);

			for (int i = 0; i < repeat; i++)
			{
				begin = Create(begin);
			}
		}

		if (input_number == 2)
		{
			View(begin);
		}

		if (input_number == 3)
		{
			Spilt_Stack(begin, plus_begin, minus_begin);

			printf("\nСписок положительных чисел\n");
			View(plus_begin);

			printf("\nСписок отрицательных чисел\n");
			View(minus_begin);
		}

		else if (input_number == 0)
		{
			Delete_Stack(&begin);
			if (begin == NULL)	puts(" Free!");

			bmenu = false;
		}

	}

	puts("Для выхода нажмите любую клавишу...");
	_getch();
}


Stack* Create(Stack *begin) 
{
	Stack *t = (Stack*)malloc(sizeof(Stack));
	//printf("\n Input Info  ");

	t->info = random(-50, 50);
	t->Next = begin;
	return t;
}

Stack* CreateInt(Stack *begin, int info) 
{
	Stack *t = (Stack*)malloc(sizeof(Stack));
	//printf("\n Input Info  ");

	t->info = info;
	t->Next = begin;
	return t;
}


void View(Stack *begin)
{
	Stack *t = begin;
	if (begin == NULL) {
		puts(" Стек пуст!");
		return;
	}
	while (t != NULL) {
		printf(" %d \n", t->info);
		t = t->Next;
	}
}

void Delete_Stack(Stack **begin) 
{
	Stack *t;

	while (*begin != NULL) 
	{
		t = *begin;
		*begin = (*begin)->Next;
		free(t);
	}
}

void Spilt_Stack(Stack *begin, Stack *plus_begin, Stack *minus_begin)
{
	Stack *t = begin;
	Stack *t1 = plus_begin;
	Stack *t2 = minus_begin;
	if (begin == NULL) {
		puts(" Стек пуст!");
		return;
	}
	while (t != NULL) 
	{
		printf("\n Input Info  ");

		if (t->info >= 0)
		{
			plus_begin = CreateInt(t, t->info);

			printf(">=0 | %d \n", plus_begin->info);
		}
		else if(t->info < 0)
		{
			minus_begin = CreateInt(t, t->info);

			printf("<0 | %d \n", t->info);
		}

		//printf(" %d \n", t->info);
		t = t->Next;
	}
}


int random(int min, int max)
{
	return -50 + rand() % 100;
}
