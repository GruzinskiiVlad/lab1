// ConsoleApplication6.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

struct book {
	int udk, year, kol;
	char author[20], name[20];
	void input(book &books);
	book *next;
};
class list {
	book *head;
public:
	list() :head(NULL) {};
	~list();
	void add(book &books);
	void show();
	void ret();
	void get();
};
void book::input(book &books) {
	cout << endl; 
	cout << "Введите УДК: "; cin >> udk;
	cin.ignore();
	cout << "Введите автора: "; cin.getline(author, 20); 
	cout << "Введите название: "; cin.getline(name, 20);  
	cout << "Введите год: "; cin >> year;
	cin.ignore();
	cout << "Введите количество: "; cin >> kol;
	cin.ignore();
}
list::~list() {
	while (head != NULL) //Пока по адресу есть хоть что-то
	{
		book *temp = head->next; //Сразу запоминаем указатель на адрес следующего элемента структуры
		delete head; //Освобождаем память по месту начала списка
		head = temp; //Меняем адрес начала списка
	}
}
void list::add(book &books) {
	book *temp = new book; //Выделение памяти под новую структуру
	temp->next = head; //Указываем, что адрес следующего элемента это начало списка

					   //Копирование содержимого параметра в только что созданную переменную
	strcpy(temp->name, books.name);
	strcpy(temp->author, books.author);
	temp->year = books.year;
	temp->udk = books.udk;
	temp->kol = books.kol;
	head = temp;
}
void list::show() {
	book *temp = head; //Объявляем указатель и изначально он указывает на начало

	while (temp != NULL) //Пока по адресу на начало хоть что-то есть
	{
		//Выводим все элементы структуры
		cout << "Номер УДК: " << temp->udk << " | " << "Кол-во: " << temp->kol << " | " << temp->author << " " << temp->name << " | Год:" << temp->year<<endl;

		temp = temp->next; //Указываем на следующий адрес из списка
	}
	cout << endl;
}
void list::ret() {
	int g;
	cout << "Введите УДК книги которую возвращаете: ";
	cin >> g;
	book *temp = head; //Объявляем указатель и изначально он указывает на начало

	for (book* t = temp; t != NULL; t = t->next) //Пока по адресу на начало хоть что-то есть
	{
		if (g==t->udk) {
			t->kol = t->kol + 1;
			
		}break;
	}
	cout << endl;
}
void list::get() {
	int h;
	cout << "Введите УДК книги которую берете: ";
	cin >> h;
	book *temp = head; //Объявляем указатель и изначально он указывает на начало

	for (book* t = temp; t != NULL; t = t->next) //Пока по адресу на начало хоть что-то есть
	{
		if (h == t->udk) {
			if (t->kol != 0) { t->kol = t->kol - 1; }
			else{ cout << "Книги в наличии нет "; }
			
		}break;
	}
	cout << endl;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	book books;
	list lst;
	int count;
	int infinity = 1;
	while (infinity == 1){
		cout << "Добро пожаловать в базу, выберете действие:\n1.Взять книгу\n2.Вернуть книгу\n3.Получить сведения о наличии книг\n4.Внести новую книгу в базу\n5.Выход\n";
		cin >> count;
		switch (count)
		{
		case 1:
		{
			lst.get();
			break;
		}
		case 2:
		{
			lst.ret();
			break;
		}
		case 3:
		{
			cout << "База книг в наличии:" << endl;
			lst.show();
			break;
		}
		case 4:
		{
			books.input(books); //Передаем в функцию заполнения переменную
			lst.add(books); //Добавляем заполненную структуру в список
			break;
		}
		case 5:
		{
			exit(0);
		}
		default:
			cout << "Неправильный ввод,повторите" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}

