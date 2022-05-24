#include "header.h"
#include "funcs.h"

void synchronizeAndShowList(ToDoList list, ToDoItem* obj, const int amount)
{
	system("cls");

	for (int i = 0; i < amount; i++)
	{
		obj[i].id = i + 1;
	}

	list.ToDoItems = obj;

	cout << "----------------------\n"
		<< "|      TO DO LIST    |\n"
		<< "----------------------\n";

	for (int i = 0; i < amount; i++)
	{
		list.id = obj[i].id;
		list.name = obj[i].name;

		cout << " ~ ~ ~\n"
			<< "| ID: " << list.id << endl
			<< "| Name: " << list.name << endl
			<< "| Enter ID to see more...\n"
			<< " ~ ~ ~\n";
	}
}
