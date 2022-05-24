#include "header.h"
#include "funcs.h"

void setData(ToDoItem* Obj, const int amount)
{
	string str;

	Obj[amount].id = amount + 1;
	cout << "To do item " << Obj[amount].id << " ...\n"
		<< "Name: ";
	cin.ignore();
	getline(cin, str);
	Obj[amount].name = str;
	cout << "Due date: ";
	getline(cin, str);
	Obj[amount].due_date = str;
	cout << "Description: ";
	getline(cin, str);
	Obj[amount].description = str;
}