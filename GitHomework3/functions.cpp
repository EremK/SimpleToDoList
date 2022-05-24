#include "header.h"
#include "funcs.h"

void showData(ToDoItem* Obj, const int index)
{
	cout << "--------------------------\n";
	cout << "0. To do item ID: " << Obj[index].id << endl;
	cout << "1. Name: " << Obj[index].name << endl;
	cout << "2. Due date: " << Obj[index].due_date << endl;
	cout << "3. Desription: " << Obj[index].description << endl;
	cout << "--------------------------\n";
}