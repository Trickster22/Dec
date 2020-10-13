// kursach.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#define OTSTUP printf("\n")


void clrscr()//функция отчистки экрана
{
	system("@cls||clear");
}

typedef struct Queue { //структурный тип обозначающий элемент очереди
	int value; //элемент очереди типа int
	struct Queue* next; //указатель на следующий элемент
}Queue; //определение нового типа для struct


void push(Queue** head, int data) {//Функция добавление элемента в начало очереди
	Queue* tmp = (Queue*)malloc(sizeof(Queue));//создаем новый узел очереди
	tmp->value = data;//присваиваем узлы значение 
	tmp->next = (*head);//Присваиваем указателю tmp адрес предыдущего узла
	(*head) = tmp;//присваиваем указателю head адрес нового узла
}


Queue* getFirst(Queue* head, int n) {//функция получения первого элемента очереди
	int counter = 0;//Объявляем счетчик
	while (counter < n && head) {//пока счетчик не дойдет до первого 
		head = head->next;
		counter++;
	}
	return head;
}

int pop(Queue** head) {//функция удаления первого элемента очереди

	Queue* prev = NULL;//Создаем локальную переменную которая будет хранить адрес первого элемента
	int val;//переменная котрая будет возвращать значение удаленного элемента
	if (head == NULL) {//проверка головы на NULL
		exit(-1);
	}
	prev = (*head);//присваиваем prev указатель на первый элемент
	val = prev->value;//в перемнную val кидаем значение первого элемента
	(*head) = (*head)->next;//присваеиваем указателю head адрес следующего элмента
	free(prev);//prev уадляем, высвобождаем память
	return val;
}

Queue* getLast(Queue* head) {//функция поиска последнего элемента
	if (head == NULL) {//проверка головы на NULL
		return NULL;
	}
	while (head->next) {//пока указатель на след элемент не станет нуль двигаемся вперед
		head = head->next;
	}
	return head;//возвращаем указатель на последний элемент
}

int getSize(Queue* head) {//функция поиска последнего элемента
	int Size=0;
	if (head == NULL) {//проверка головы на NULL
		return NULL;
	}
	while (head->next) {//пока указатель на след элемент не станет нуль двигаемся вперед
		head = head->next;
		Size++;
	}
	return Size;//возвращаем указатель на последний элемент
}

void pushBack(Queue* head, int value) {//функция встваки в конец очереди нового элемента
	Queue* last = getLast(head);//получаем указатель на последний элемент
	Queue* tmp = (Queue*)malloc(sizeof(Queue));//создаем новый элемент
	tmp->value = value;//присваиваем новому элементу значение
	tmp->next = NULL;//указатель на следующий элемент нового элемента NULL
	last->next = tmp;//указатель старого элемента на следующий элемент указывает теперь на новый элемент 
}


Queue* getLastButOne(Queue* head) {//функция возвращает указатель на предпоследний элемент
	if (head == NULL) {	//проверка голову на NULL
		exit(-2);
	}
	if (head->next == NULL) {//проверка указаетля на следующий элемент на NULL
		return NULL;
	}
	while (head->next->next) {//пока у следующего элемента есть указатель на следующий элемент двигаемся вперед
		head = head->next;
	}
	return head;//возвращаем указатель на предпоследний элемент
}

void popBack(Queue** head) {//функция удаления последнего элемента очереди
	Queue* lastbn = NULL;//создали пустой узел очереди
	
	if (!head) { //проверка на наличие головы
		exit(-1);
	}

	lastbn = getLastButOne(*head);//присвоили укзателю указатель на предполоседний элемент

	if (lastbn == NULL) {//если в очереди один элемент
		free(*head);
		*head = NULL;
	}
	else {
		free(lastbn->next);//удаляем укзатель на следующий элемент предпоследнего элемента
		lastbn->next = NULL;//указтель на следующий элемент препоследнего элемента равен NULL
	}
}

void printLinkedList(const Queue* head) {//функция печати очереди
	while (head) { //пока есть указатель указатель на голову
		printf("%d ", head->value);
		head = head->next; //указетлю присвоить адрем след элемента
	}
	printf("\n");
}
//----------------------------Главенствующая структура и ее функции------------------------------------------

typedef struct Deque {  //структурный тип обозначающий элемент дека
	struct Queue* value; //элемент дека типа очередь
	struct Deque* next; //укахатель на следующий элемент
} Deque; //определение нового типа для struct

void pushD(Deque** head, Queue* data) { //функция добавление элемета в начало дека
	Deque* tmp = (Deque*)malloc(sizeof(Deque)); //создаем временную переменную
	tmp->value = data; //присваиваем врем переменной значение
	tmp->next = (*head); //присваем указателю адрем предыдущего узла
	(*head) = tmp; //присваиваем указателю на голову адрес нового узла
}

Queue* popD(Deque** head) { //функция удаления первого элемента дека
	Deque* prev = NULL; //создаем переменную, хранящую адрес первого элемента
	Queue* val; //переменная храняща значение первого элемента
	if (head == NULL) { //проверка на голову
		exit(-1);
	}
	prev = (*head); //присваиваем указателю адрес головы
	val = prev->value; //присваиваем переменной значение головы
	(*head) = (*head)->next; //указателю на голову присваиваем адрес след элемента
	free(prev); //освобождаем перменную
	return val; //возвращаем значение головы
}

Deque* getLastD(Deque* head) { //функция получения послднего элемента
	if (head == NULL) { //проверка на голову
		return NULL;
	}
	while (head->next) { // пока указатель на след элемент головы существует
		head = head->next; //присваиваем указателю на голову адрес след элемента
	}
	return head; //возвращаем указатель на голову
}

int getSizeD(Deque* head) { //функция получения размера дека
	int SizeD=0; 
	if (head == NULL) { //проверка на голову
		return NULL;
	}
	while (head->next) { //пока у головы есть адрес на след элесент
		head = head->next;//присваиваем указателю адрес след элемета
		SizeD++; //увеличиваем размер на 1
	}
	return SizeD; //возвращаем полученный размер
}

void pushBackD(Deque* head, Queue* value) { //функция добавления в конец дека
	Deque* last = getLastD(head); //переменная хранящая указатель на полседний элемент
	Deque* tmp = (Deque*)malloc(sizeof(Deque)); //временная переменная
	tmp->value = value; //присваиваем переменой значение
	tmp->next = NULL; //указатель ырем перемнной на след элемент равен NULL
	last->next = tmp; //указателю последнего элемента на следующий присваиваем адрес нового элемента
}

Deque* getLastButOneD(Deque* head) { //функция получения предпоследнего элемента
	if (head == NULL) { //если список пуст
		exit(-2);
	}
	if (head->next == NULL) { //если указатель на след элемент указывает на NULL
		return NULL;
	}
	while (head->next->next) { //пока у следующего элемента есть не NULL указатель на след элемент
		head = head->next; //присваиваем указателю адрес на следующий элемент
	}
	return head; //возвращает указтель
}


void popBackD(Deque** head) { //удаление последнего элемента
	Deque* lastbn = NULL; //уазатель типа дек
	if (!head) { //если список пуст
		exit(-1);
	}

	lastbn = getLastButOneD(*head); //присваиваем указтелю адрес предпоследнего элемнта
	if (lastbn == NULL) { //если в деке один элемент
		free(*head); // удаляем голову
		*head = NULL;
	}
	else {
		free(lastbn->next); // удаляем казатель на след элемент
		lastbn->next = NULL; //указатель на след элемент прирваниваем NULL
	}
}

void printLinkedListD(const Deque* head) { //функция печати дека
	while (head) { // пока есть голова 
		if (head->value) //если есть значение элемента
			printLinkedList(head->value); //вызываем функцию печати очереди
		else
			printf("Пустой элемент\n"); //выводим сообщение
		head = head->next; //присваиваем указателю адрес на след элемент
	}
	printf("\n");
}
//------------------------------------------переменные-------------------------------------------------------------------------------
Queue* HeadQ = NULL; //указатель на голову очереди
Deque* head = NULL; //указатель на голову дека
Queue* perem = NULL; //вспомогательный указатель
int ForSwitch, i, N, element, ForSwitchQ, peremQ = 0; //вспомогательные интовые перемнные 
bool FlagWork = false, FlagStart = false; //флаги работы  и начала работы дека
bool FlagWorkQ = false, FlagStartq = false; //флаги работы и начала работы очереди
//------------------------------------------функции паботы с деком------------------------------------------------------------------

void startWork() //функцмя начала работы с деком
{
	clrscr(); //очищение экрана
	if (FlagStart) //если флаг начала работы true
		printf("Работа уже начата :/\n");
	else
	{
		printf("Работа начата.\n");
		FlagStart = true;
	}
}

void ClearDeque() //функция очищение дека
{
	clrscr();
	if (!FlagStart) //если флаг начала работы true
		printf("Сначала нужно начать работу!\n");
	else
	{
		if (head) { // если список не пуст
			N = getSizeD(head); //получаем размер дека
			for (i = 0; i <= N; i++) //пока не дойдем до i равного размеру дека
			{
				popBackD(&head); //вызов функции удаления последнего элемента

			}
		}
		else
			printf("Дек и так пуст.\n");
	}
}

void VoidTest() //функция проверки дека на пустоту
{
	clrscr();
	if (!FlagStart) //если флаг начала работы true
		printf("Сначала нужно начать работу!\n");
	else
		if (head == NULL) //если список пуст
			printf("Дек пуст\n");
		else {
			printf("В деке что-то есть\n");
			printLinkedListD(head); //вызов функции печати дека
		}
}

void Show(Deque* headF) //функция показания первого элемента дека
{
	clrscr();
	if (!FlagStart) //если флаг начала работы true
		printf("Сначала нужно начать работу!\n");
	else
	{
		if (head) // если список не пуст
		{
			printLinkedListD(head);  //вызов функции печати дека
			printf("Первый элемент дека: \n");
			printLinkedList(headF->value); //вызов функции печати 
		}
		else
			printf("Дек пуст.\n");
	}
}

void DeleteFirst() //функция удаления первого элемента дека
{
	clrscr();
	if (!FlagStart) //если флаг начала работы true
		printf("Сначала нужно начать работу!\n");
	else
	{
		if (head) // если список не пуст
		{
			popD(&head);
			printLinkedListD(head); //вызов функции печати дека
		}
		else
			printf("Удалять нечего :(\n");
	}
}

void DeleteLast() //функция удаления полсднего элемента дека
{
	clrscr();
	if (!FlagStart) //если флаг начала работы true
		printf("Сначала нужно начать работу!\n");
	else
	{
		if (head) // если список не пуст
		{
			popBackD(&head);
			printLinkedListD(head); //вызов функции печати дека
		}
		else
			printf("Удалять то нечего :/\n");
	}
}

void TakeFirst() //функция взятия первого элемента дека
{
	clrscr();
	if (!FlagStart) //если флаг начала работы true
		printf("Сначала нужно начать работу!\n");
	else
	{
		if (head) { // если список не пуст
			if (!head->value) {
				printf("Взят пустой элемент\n");
				popD(&head);
				printLinkedListD(head); //вызов функции печати дека
			}
			else {
				printLinkedListD(head); //вызов функции печати дека
				printf("Первый элемент дека: ");
				printLinkedList(head->value); //вызов функции печати очереди
				printf(" взят!\n");
				popD(&head); //удаление первого элемента дека
				printLinkedListD(head); //вызов функции печати дека
			}
		}
		else
			printf("Брать нечего.\n");
	}
}

void TakeLast() //функция взятия послденего элемента дека
{
	clrscr();
	if (!FlagStart) //если флаг начала работы true
		printf("Сначала нужно начать работу!\n");
	else
	{
		if (head) { // если список не пуст
			if (!getLastD(head)->value) { //если элемент дека пуст
				printf("Взят пустой элемент\n");
				popBackD(&head); //удаление последнего элмента дека
				printLinkedListD(head); //вызов функции печати дека
			}
			else {
				printLinkedListD(head); //вызов функции печати дека
				perem = getLastD(head)->value; //присваем переменной последний элмент дека
				popBackD(&head); //удаление последнего элемента дека 
				printf("последний элемент дека: \n");
				printLinkedList(perem); //печать очереди
				printf("взят!\n");
				printLinkedListD(head); //вызов функции печати дека
			}
		}
		else
			printf("Брать нечего.\n");

	}
}

void StartWorkQ() //функция начала работы с очередью
{
	clrscr();
	if (FlagStartq) //если флаг начала работы true
		printf("Работа уже начата!\n");
	else {
		FlagStartq = true;
		printf("Работа начата.\n");
	}
}

void deleteQ(Deque* headF) //функция удаления очереди
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		if (headF->value) {  // если список не пуст
			N = getSize(headF->value); //получаем размер очереди
			for (int i = 0; i <= N; i++) //пока i не станет равным размеру очереди
			{
				popBack(&(headF->value));//удаление последнего элемнта очереди
			}
			printf("Очередь опустошена >:(\n");
		}
		else
			printf("Очередь и так пуста.\n");
	}
}

void isEmptyQ(Deque* headF) //функция проверки очереди на пустоту
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		if (headF->value == NULL)  // если список пуст
			printf("Очередь пуста :(\n");
		else
		{
			printf("В очереди что-то есть!\n");
			printLinkedList(headF->value); //печать очереди
		}
	}
}

void ShowFirstQ(Deque* headF) //функция показания первого элемента очереди
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		if (headF->value) { // если список не пуст
			printLinkedList(headF->value); //печать очереди
			printf("Элемент в начале очереди : %d", headF->value->value);
			OTSTUP; //печать отступа
		}
		else
			printf("Очередь пуста\n");
	}
}

void DeleteFirstQ(Deque* headF) //функция удаления первого элемента очереди
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		if (headF->value) { // если список не пуст
			pop(&(headF->value)); //удаление первого элемента очереди
			printf("Где первый элемент очереди?\n");
			printf("Уничтожил. Низвел до атомов.\n");
			printLinkedList(headF->value); //печать очереди
		}
		else
			printf("Удалять нечего\n");
	}
}

void TakeFirstQ(Deque* headF) //функция взятия первого элемента очереди
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		if (headF->value) { // если список не пуст
			peremQ = pop(&(headF->value)); //присваиваем перемнной значение первого элемента очереди
			printf("Переменная "); printf("%d", peremQ); printf(" взята.\n"); //вывод первого элемета на экран
			printLinkedList(headF->value); //печать очереди
		}
		else
			printf("Брать нечего\n");
	}
}

void ChangeFirstQ(Deque* headF) //функция изменения первого элемента очереди
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		if (headF->value) { // если список не пуст
			printf("На какое число заменить?\n");
			scanf_s("%d", &peremQ); //получаем число, ввденное пользователем
			pop(&(headF->value)); //удаление первого элемента очереди
			push(&(headF->value), peremQ); //внедрение элемента в начало очереди
			printf("Его теперь родная мама не узнает!\n");
			printLinkedList(headF->value); //печать очереди
		}
		else
			printf("Заменить нечего.\n");
	}
}

void AddLastQ(Deque* headF) //функция добавдения элемента в конец очереди
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		printf("Введите элемент, который нужно добавить.\n");
		scanf_s("%d", &peremQ); //получаем число, ввденное пользователем
		if ((headF->value) != NULL) { // если список не пуст
			pushBack((headF->value), peremQ); //удаляем последний элемент очереди
			printf("Объект внедрен.\n");
			printLinkedList(headF->value); //печать очереди
		}
		else {
			push(&(headF->value), peremQ); //добавление элемента в начало очереди
			printf("Объект внедрен.\n");
			printLinkedList(headF->value); //печать очереди
		}
	}
}

void PrintQ(Deque* headF) //функция печати очереди
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		if (headF->value == NULL) // если список пуст
			printf("Список пуст, печатать нечего :(\n");
		else
		{
			printf("Очередь: \n");
			printLinkedList(headF->value); //печать очереди
		}
	}
}

void EndWorkQ() //функция окончания работы
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		FlagWorkQ = true;
		printf("Возвращаемся к деку.\n");

	}
}

void menuChange(Deque* headF) //функция вызова меню для очереди при изменении очереди
{
	clrscr();
	if (!FlagStart) //если флаг начала работы true
		printf("Сначала нужно начать работу!\n");
	else
	{
		if (!head)  // если список пуст
			printf("Изменять нечего\n");
		else {
			do { //делаем пока флаг работы false

				printf("Выберите пункт.\n");
				printf("1. Начать работу с очередью.\n");
				printf("2. Сделать очередь пустой.\n");
				printf("3. Проверка: очередь пуста/не пуста.\n");
				printf("4. Показать значение в начале очереди.\n");
				printf("5. Удалить начало очереди.\n");
				printf("6. Взять элемент из начала очереди.\n");
				printf("7. Изменить значение элемента в начале очереди.\n");
				printf("8. Добавить элемент в конец очереди.\n");
				printf("9. Распечатать структуру данных.\n");
				printf("10. Закончить работу с очередью.\n");
				scanf_s("%d", &ForSwitchQ);

				switch (ForSwitchQ)
				{
				case 1:
					StartWorkQ(); //начало работы с очередью
					break;

				case 2:
					deleteQ(headF); //удаление очереди
					break;

				case 3:
					isEmptyQ(headF); //проверка очереди на пустоту
					break;

				case 4:
					ShowFirstQ(headF); //показать первый элемент очереди
					break;

				case 5:
					DeleteFirstQ(headF); //удалить первый элемент очереди
					break;

				case 6:
					TakeFirstQ(headF); //взять первый элемент очереди
					break;

				case 7:
					ChangeFirstQ(headF); //изменить первый элемент очереди
					break;

				case 8:
					AddLastQ(headF); //добавить элемент в конец очереди
					break;

				case 9:
					PrintQ(headF); //печать очереди
					break;

				case 10:
					EndWorkQ(); //закончить работу с очередью
					break;

				default:
					clrscr();
					printf("Неизвестная команда.\n");
					break;
				}
			} while (FlagWorkQ == false);
			FlagWorkQ = false;
			FlagStartq = false;
			printf("Элемент в начале дека заменен!\n");
			printLinkedListD(head); //вызов функции печати дека
		}
	}
}

void ClearQ2() //функция очищения новой очереди
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		if (HeadQ) { // если список не пуст
			N = getSize(HeadQ); //получение размера очереди
			for (int i = 0; i <= N; i++)// пока i не равно размеру очереди
			{
				popBack(&(HeadQ)); //удаление последнего элемента очереди
			}
			printf("Очередь опустошена >:(\n");
		}
		else
			printf("Очередь и так пуста.\n");
	}
}

void TestClearQ2() //функция проверки новой очереди на пустоту
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		if (!HeadQ) // если список не пуст
			printf("Очередь пуста :(\n");
		else
		{
			printf("В очереди что-то есть!\n");
			printLinkedList(HeadQ); //печать очереди
		}
	}
}

void ShowfirstQ2() //функция показания первого элемента новой очереди
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		if (HeadQ) { // если список не пуст
			printLinkedList(HeadQ); //печать очереди
			printf("Элемент в начале очереди : %d", HeadQ->value);
			OTSTUP;//печать отступа
		}
		else
			printf("Очередь пуста.\n");

	}
}

void DelFirstQ2() //функция удаления первого элемента новой очереди
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		if (HeadQ) // если список не пуст
		{
			pop(&(HeadQ)); //удаление первого элемента очереди
			printf("Где первый элемент очереди?\n");
			printf("Уничтожил. Низвел до атомов.\n");
			printLinkedList(HeadQ); //печать очереди
		}
		else
			printf("Удалять нечего.\n");
	}
}

void TakeFirstQ2() //функция взятия первого элемента новой очереди
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		if (HeadQ) { // если список не пуст
			peremQ = pop(&(HeadQ)); //присваивание перменной значние первого элемента и удаление первого элемента
			printf("Переменная "); printf("%d", peremQ); printf(" взята.\n");
			printLinkedList(HeadQ); //печать очереди
		}
		else
			printf("Брать нечего.\n");

	}
}

void ChangeFirstQ2() //функция изменнения первого элемента новой очереди 
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		if (HeadQ) { // если список не пуст
			printf("На какое число заменить?\n");
			scanf_s("%d", &peremQ); //получаем значение от пользователя
			pop(&(HeadQ)); //удаляем первый элемент очереди
			push(&(HeadQ), peremQ); //добавляем в начало очереди элемент
			printf("Его теперь родная мама не узнает!\n");
			printLinkedList(HeadQ); //печать очереди
		}
		else
			printf("Изменять нечего.\n");
	}
}

void AddLastQ2() //функция добавления в конец новго элемента новой очереди
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		printf("Введите элемент, который нужно добавить.\n");
		scanf_s("%d", &peremQ); //получение заначения от пользователя
		if ((HeadQ) != NULL) { // если список не пуст
			pushBack(HeadQ, peremQ); //добавление элемента в конец очереди
			printf("Объект внедрен.\n");
			printLinkedList(HeadQ); //печать очередь
		}
		else {
			push(&(HeadQ), peremQ); //добавление в начало очереди
			printf("Объект внедрен.\n");
			printLinkedList(HeadQ); //печать очереди
		}
	}
}

void PrintQ2() //функция печати новой очереди
{
	clrscr();
	if (!FlagStartq) //если флаг начала работы true
		printf("Сначала необходимо начать работу!\n");
	else
	{
		if (HeadQ == NULL) // если список пуст
			printf("Список пуст, печатать нечего :(\n");
		else
		{
			printf("Очередь: \n");
			printLinkedList(HeadQ);//печать очереди
		}
	}
}

void menuAdd() //функция вызова меню для очереди при добвалении очереди
{
	clrscr();
	if (!FlagStart) //если флаг начала работы true
		printf("Сначала нужно начать работу!\n");
	else
	{
		HeadQ = NULL;
		do { //делаем пока флаг работы с очередью false

			printf("Выберите пункт.\n");
			printf("1. Начать работу с очередью.\n");
			printf("2. Сделать очередь пустой.\n");
			printf("3. Проверка: очередь пуста/не пуста.\n");
			printf("4. Показать значение в начале очереди.\n");
			printf("5. Удалить начало очереди.\n");
			printf("6. Взять элемент из начала очереди.\n");
			printf("7. Изменить значение элемента в начале очереди.\n");
			printf("8. Добавить элемент в конец очереди.\n");
			printf("9. Распечатать структуру данных.\n");
			printf("10. Закончить работу с очередью.\n");
			scanf_s("%d", &ForSwitchQ);

			switch (ForSwitchQ)
			{
			case 1:
				StartWorkQ(); //начало работы
				break;

			case 2:
				ClearQ2(); //очищение очереди
				break;

			case 3:
				TestClearQ2(); //проверка очереди на пустоту
				break;

			case 4:
				ShowfirstQ2(); //показать первый элемент очереди
				break;

			case 5:
				DelFirstQ2(); //удалить первый элемент очереди
				break;

			case 6:
				TakeFirstQ2(); //взять первый элемент очердь
				break;

			case 7:
				ChangeFirstQ2(); //изменить первый элемент очереди
				break;

			case 8:
				AddLastQ2(); //добавить элемент в конец очереди
				break;

			case 9:
				PrintQ2(); //печать очереди
				break;

			case 10:
				EndWorkQ(); //закончить работу с очередью
				break;

			default:
				clrscr();
				printf("Неизвестная команда.\n");
				break;
			}
		} while (FlagWorkQ == false);
		FlagWorkQ = false;
		FlagStartq = false;
	}
}

void AddFirst() //добавление первого элемента в начало дека
{
	pushD(&head, HeadQ); //добавление элемента в начало дека
	printf("Очередь добавлена в начало дека.\n");
	printLinkedListD(head); //вызов функции печати дека
}

void AddLast() //добавление элемента в окнец дека
{
	pushBackD(head, HeadQ); //добавление элемента в конец дека
	printf("Очередь добавлена в конец дека!\n");
	printLinkedListD(head); //вызов функции печати дека
}

void AddelFirst() //добавлние новой очереди в начало дека
{
	menuAdd(); //меню очереди при добавлении
	AddFirst(); //добавление в начало дека
}

void AddElLast()//добавление новой очереди в конец дека
{
	menuAdd();
	if (head != NULL) // если список не пуст
		AddLast(); //добавление в конец
	else
		AddFirst(); //добавление в начало
}

void printDeque() //распечатать дек
{
	clrscr();
	if (!FlagStart)
		printf("Сначала нужно начать работу!\n");
	else
		if (head == NULL) // если список пуст
			printf("Cписок пуст, печатать нечего :(\n");
		else {
			printf("Вот ваш дек очередей: \n");
			printLinkedListD(head); //вызов функции печати дека
		}
}

void EndWork() //окончить работу 
{
	clrscr();
	if (!FlagStart)
		printf("Сначала нужно начать работу!\n");
	else
	{
		for (i = 0; i < getSizeD(head); i++) //пока i не равно размеру дека
		{
			popBackD(&head); //удаление последнего элемента дека

		}
		FlagStart = false;
		printf("Работа завершена. До свидания ;)\n");
	}
}

void Exit() //выйти из программы
{
	clrscr();
	printf("Ну теперь уж точно пока.\n");
	FlagWork = true;
}

void menu() //вызов меню для дека
{
	do //делаем пока флаг работы с деком false
	{
		printf("Выберите пункт.\n");
		printf("1. Начать работу с деком.\n");
		printf("2. Сделать дек пустым.\n");
		printf("3. Проверка: дек пуст/не пуст.\n");
		printf("4. Показать значение в начале дека.\n");
		printf("5. Показать значение в конце дека.\n");
		printf("6. Удалить начало дека.\n");
		printf("7. Удалить конец дека.\n");
		printf("8. Взять элемент из начала дека.\n");
		printf("9. Взять элемент из конца дека.\n");
		printf("10. Изменить значение элемента в начале дека.\n");
		printf("11. Изменить значение элемента в конце дека.\n");
		printf("12. Добавить элемент в начало дека.\n");
		printf("13. Добавить элемент в конец дека.\n");
		printf("14. Распечатать структуру данных.\n");
		printf("15. Закончить работу с деком.\n");
		printf("16. Выход.\n");
		scanf_s("%d", &ForSwitch);

		switch (ForSwitch)
		{
		case 1:
			startWork(); //начало работы
			break;

		case 2:
			ClearDeque(); //очистить дек
			break;

		case 3:
			VoidTest(); //проверка на пустоту 
			break;

		case 4:
			Show(head); //показать первый элемент дека
			break;

		case 5:
			Show(getLastD(head)); //показать последний элемент дека
			break;

		case 6:
			DeleteFirst(); //удалить первый элемент дека
			break;

		case 7:
			DeleteLast(); //удалить последний элемент дека
			break;

		case 8:
			TakeFirst(); //взять первый элемент дека
			break;

		case 9:
			TakeLast(); //взять последний элемент дека
			break;

		case 10:
			menuChange(head); //меню для работы с очередью при изменении первого элемента
			break;

		case 11:
			menuChange(getLastD(head));//меню для работы с очередью при изменении последнего элемента
			break;

		case 12:
			AddelFirst(); //добавление элемента в начало дека
			break;

		case 13:
			AddElLast(); //добавление элемента в конец дека
			break;

		case 14:
			printDeque(); //печать дека
			break;

		case 15:
			EndWork(); //закончить работу с деком
			break;

		case 16: 
			Exit(); //выход из программы
			break;

		default:
			clrscr();
			printf("Неизвестная команда!\n");
			break;
		}

	} while (FlagWork == false);
}
//------------------------------------------Начало основного блока программы---------------------------------------------------
int main()
{
	
	setlocale(LC_ALL, "Rus"); //возможность вывода кирилицы
	menu(); //вызов меню для работы с деком

}

/*void ShowLast()
{
	clrscr();
	if (!FlagStart)
		printf("Сначала нужно начать работу!\n");
	else
	{
		if (head) {
			printLinkedListD(head);
			perem = getLastD(head)->value;
			printf("Последний элемент дека: \n");
			printLinkedList(perem);
		}
		else
			printf("Дек пуст.\n");

	}
}

			clrscr();
			if (!FlagStart)
				printf("Сначала нужно начать работу!\n");
			else
			{
				if (!head)
					printf("Изменять нечего\n");
				else {
					do {

						printf("Выберите пункт.\n");
						printf("1. Начать работу с очередью.\n");
						printf("2. Сделать очередь пустой.\n");
						printf("3. Проверка: очередь пуста/не пуста.\n");
						printf("4. Показать значение в начале очереди.\n");
						printf("5. Удалить начало очереди.\n");
						printf("6. Взять элемент из начала очереди.\n");
						printf("7. Изменить значение элемента в начале очереди.\n");
						printf("8. Добавить элемент в конец очереди.\n");
						printf("9. Распечатать структуру данных.\n");
						printf("10. Закончить работу с очередью.\n");
						scanf_s("%d", &ForSwitchQ);

						switch (ForSwitchQ)
						{
						case 1:
							clrscr();
							if (FlagStartq)
								printf("Работа уже начата!\n");
							else {
								FlagStartq = true;
								printf("Работа начата!\n");
							}
							break;

						case 2:
							clrscr();
							if (!FlagStartq)
								printf("Сначала необходимо начать работу!\n");
							else
							{
								if (getLastD(head)->value) {
									N = getSize(getLastD(head)->value);
									for (int i = 0; i <= N; i++)
									{
										popBack(&(getLastD(head)->value));
									}
									printf("Очередь опустошена >:(\n");
								}
								else
									printf("Очередь и так пуста.\n");
							}
							break;

						case 3:
							clrscr();
							if (!FlagStartq)
								printf("Сначала необходимо начать работу!\n");
							else
							{
								if (getLastD(head)->value == NULL)
									printf("Очередь пуста :(\n");
								else
								{
									printf("В очереди что-то есть!\n");
									printLinkedList(getLastD(head)->value);
								}
							}
							break;

						case 4:
							clrscr();
							if (!FlagStartq)
								printf("Сначала необходимо начать работу!\n");
							else
							{
								if (getLastD(head)->value) {
									printLinkedList(getLastD(head)->value);
									printf("Элемент в начале очереди: %d", getLastD(head)->value->value);
									OTSTUP;
								}
								else
									printf("Очередь пуста.\n");
							}
							break;

						case 5:
							clrscr();
							if (!FlagStartq)
								printf("Сначала необходимо начать работу!\n");
							else
							{
								if (getLastD(head)->value) {
									pop(&(getLastD(head)->value));
									printf("Где первый элемент очереди?\n");
									printf("Уничтожил. Низвел до атомов.\n");
									printLinkedList(getLastD(head)->value);
								}
								else
									printf("Удалять нечего.\n");
							}
							break;

						case 6:
							clrscr();
							if (!FlagStartq)
								printf("Сначала необходимо начать работу\n");
							else
							{
								if (getLastD(head)->value) {
									peremQ = pop(&(getLastD(head)->value));
									printf("Переменная "); printf("%d", peremQ); printf(" взята.\n");
									printLinkedList(getLastD(head)->value);
								}
								else
									printf("Брать нечего.\n");
							}
							break;

						case 7:
							clrscr();
							if (!FlagStartq)
								printf("Сначала необходимо начать работу\n");
							else
							{
								if (getLastD(head)->value) {
									printf("На какое число заменить?\n");
									scanf_s("%d", &peremQ);
									pop(&(getLastD(head)->value));
									push(&(getLastD(head)->value), peremQ);
									printf("Его теперь родная мама не узнает!\n");
									printLinkedList(getLastD(head)->value);
								}
								else
									printf("Нечего изменять.\n");
							}
							break;

						case 8:
							clrscr();
							if (!FlagStartq)
								printf("Сначала необходимо начать работу\n");
							else
							{
								printf("Введите элемент, которй нужно добавить.\n");
								scanf_s("%d", &peremQ);
								pushBack((getLastD(head)->value), peremQ);
								printf("Объект внедрен.\n");
								printLinkedList(getLastD(head)->value);

							}
							break;

						case 9:
							clrscr();
							if (!FlagStartq)
								printf("Сначала необходимо начать работу\n");
							else
							{
								if (getLastD(head)->value == NULL)
									printf("Список пуст, печатать нечего :(");
								else {
									printf("Очередь: \n");
									printLinkedList(getLastD(head)->value);
								}
							}
							break;

						case 10:
							clrscr();
							if (!FlagStartq)
								printf("Сначала необходимо начать работу\n");
							else
							{
								FlagWorkQ = true;
								printf("Возвращаемся к деку.\n");
							}
							break;

						default:
							clrscr();
							printf("Неизвестная команда.\n");
							break;
						}
					} while (FlagWorkQ == false);

					FlagWorkQ = false;
					FlagStartq = false;
					printf("Элемент в конце дека заменен!\n");
					printLinkedListD(head);
				}
			}

			clrscr();
			if (!FlagStart)
				printf("Сначала нужно начать работу!\n");
			else
			{

				HeadQ = NULL;
				do {

					printf("Выберите пункт.\n");
					printf("1. Начать работу с очередью.\n");
					printf("2. Сделать очередь пустой.\n");
					printf("3. Проверка: очередь пуста/не пуста.\n");
					printf("4. Показать значение в начале очереди.\n");
					printf("5. Удалить начало очереди.\n");
					printf("6. Взять элемент из начала очереди.\n");
					printf("7. Изменить значение элемента в начале очереди.\n");
					printf("8. Добавить элемент в конец очереди.\n");
					printf("9. Распечатать структуру данных.\n");
					printf("10. Закончить работу с очередью.\n");
					scanf_s("%d", &ForSwitchQ);

					switch (ForSwitchQ)
					{
					case 1:
						clrscr();
						if (FlagStartq)
							printf("Работа уже начата!\n");
						else {
							FlagStartq = true;
							printf("Работа начата.\n");
						}
						break;

					case 2:
						clrscr();
						if (!FlagStartq)
							printf("Сначала необходимо начать работу!\n");
						else
						{
							if (HeadQ) {
								N = getSize(HeadQ);
								for (int i = 0; i <= N; i++)
								{
									popBack(&(HeadQ));
								}
								printf("Очередь опустошена >:(\n");
							}
							else
								printf("Очередь и так пуста.\n");
						}
						break;

					case 3:
						clrscr();
						if (!FlagStartq)
							printf("Сначала необходимо начать работу!\n");
						else
						{
							if (!HeadQ)
								printf("Очередь пуста :(\n");
							else
							{
								printf("В очереди что-то есть!\n");
								printLinkedList(HeadQ);
							}
						}
						break;

					case 4:
						clrscr();
						if (!FlagStartq)
							printf("Сначала необходимо начать работу!\n");
						else
						{
							if (HeadQ)
							{
								printLinkedList(HeadQ);
								printf("Элемент в начале очереди : %d", HeadQ->value);
								OTSTUP;
							}
							else
								printf("Элементов нет.\n");

						}
						break;

					case 5:
						clrscr();
						if (!FlagStartq)
							printf("Сначала необходимо начать работу!\n");
						else
						{
							if (HeadQ) {
								pop(&(HeadQ));
								printf("Где первый элемент очереди?\n");
								printf("Уничтожил. Низвел до атомов.\n");
								printLinkedList(HeadQ);
							}
							else
								printf("Удалять нечего.\n");
						}
						break;

					case 6:
						clrscr();
						if (!FlagStartq)
							printf("Сначала необходимо начать работу!\n");
						else
						{
							if (HeadQ) {
								peremQ = pop(&(HeadQ));
								printf("Переменная "); printf("%d", peremQ); printf(" взята.\n");
								printLinkedList(HeadQ);
							}
							else
								printf("Брать нечегою\n");
						}
						break;

					case 7:
						clrscr();
						if (!FlagStartq)
							printf("Сначала необходимо начать работу!\n");
						else
						{
							if (HeadQ) {
								printf("На какое число заменить?\n");
								scanf_s("%d", &peremQ);
								pop(&(HeadQ));
								push(&(HeadQ), peremQ);
								printf("Его теперь родная мама не узнает!\n");
								printLinkedList(HeadQ);
							}
							else
								printf("Изменять нечего.\n");
						}
						break;

					case 8:
						clrscr();
						if (!FlagStartq)
							printf("Сначала необходимо начать работу!\n");
						else
						{
							printf("Введите элемент, который нужно добавить.\n");
							scanf_s("%d", &peremQ);
							if ((HeadQ) != NULL) {
								pushBack(HeadQ, peremQ);
								printf("Объект внедрен.\n");
								printLinkedList(HeadQ);
							}
							else {
								push(&(HeadQ), peremQ);
								printf("Объект внедрен.\n");
								printLinkedList(HeadQ);
							}
						}
						break;

					case 9:
						clrscr();
						if (!FlagStartq)
							printf("Сначала необходимо начать работу!\n");
						else
						{
							if (HeadQ == NULL)
								printf("Список пуст, печатать нечего :(\n");
							else
							{
								printf("Очередь: \n");
								printLinkedList(HeadQ);
							}
						}
						break;

					case 10:
						clrscr();
						if (!FlagStartq)
							printf("Сначала необходимо начать работу!\n");
						else
						{
							FlagWorkQ = true;
							printf("Возвращаемся к деку.\n");

						}
						break;

					default:
						clrscr();
						printf("Неизвестная команда.\n");
						break;
					}
				} while (FlagWorkQ == false);
				FlagWorkQ = false;
				FlagStartq = false;
*/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
