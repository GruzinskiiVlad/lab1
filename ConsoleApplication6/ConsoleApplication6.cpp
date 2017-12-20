// ConsoleApplication6.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	cout << "������� ���: "; cin >> udk;
	cin.ignore();
	cout << "������� ������: "; cin.getline(author, 20); 
	cout << "������� ��������: "; cin.getline(name, 20);  
	cout << "������� ���: "; cin >> year;
	cin.ignore();
	cout << "������� ����������: "; cin >> kol;
	cin.ignore();
}
list::~list() {
	while (head != NULL) //���� �� ������ ���� ���� ���-��
	{
		book *temp = head->next; //����� ���������� ��������� �� ����� ���������� �������� ���������
		delete head; //����������� ������ �� ����� ������ ������
		head = temp; //������ ����� ������ ������
	}
}
void list::add(book &books) {
	book *temp = new book; //��������� ������ ��� ����� ���������
	temp->next = head; //���������, ��� ����� ���������� �������� ��� ������ ������

					   //����������� ����������� ��������� � ������ ��� ��������� ����������
	strcpy(temp->name, books.name);
	strcpy(temp->author, books.author);
	temp->year = books.year;
	temp->udk = books.udk;
	temp->kol = books.kol;
	head = temp;
}
void list::show() {
	book *temp = head; //��������� ��������� � ���������� �� ��������� �� ������

	while (temp != NULL) //���� �� ������ �� ������ ���� ���-�� ����
	{
		//������� ��� �������� ���������
		cout << "����� ���: " << temp->udk << " | " << "���-��: " << temp->kol << " | " << temp->author << " " << temp->name << " | ���:" << temp->year<<endl;

		temp = temp->next; //��������� �� ��������� ����� �� ������
	}
	cout << endl;
}
void list::ret() {
	int g;
	cout << "������� ��� ����� ������� �����������: ";
	cin >> g;
	book *temp = head; //��������� ��������� � ���������� �� ��������� �� ������

	for (book* t = temp; t != NULL; t = t->next) //���� �� ������ �� ������ ���� ���-�� ����
	{
		if (g==t->udk) {
			t->kol = t->kol + 1;
			
		}break;
	}
	cout << endl;
}
void list::get() {
	int h;
	cout << "������� ��� ����� ������� ������: ";
	cin >> h;
	book *temp = head; //��������� ��������� � ���������� �� ��������� �� ������

	for (book* t = temp; t != NULL; t = t->next) //���� �� ������ �� ������ ���� ���-�� ����
	{
		if (h == t->udk) {
			if (t->kol != 0) { t->kol = t->kol - 1; }
			else{ cout << "����� � ������� ��� "; }
			
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
		cout << "����� ���������� � ����, �������� ��������:\n1.����� �����\n2.������� �����\n3.�������� �������� � ������� ����\n4.������ ����� ����� � ����\n5.�����\n";
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
			cout << "���� ���� � �������:" << endl;
			lst.show();
			break;
		}
		case 4:
		{
			books.input(books); //�������� � ������� ���������� ����������
			lst.add(books); //��������� ����������� ��������� � ������
			break;
		}
		case 5:
		{
			exit(0);
		}
		default:
			cout << "������������ ����,���������" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}

