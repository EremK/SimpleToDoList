#include "header.h"
#include "funcs.h"

ToDoItem* EditStruct(ToDoItem* obj, const int amount)
{
	int index, choice;
	string newInfo;

	cout << "---------------------------\n"
		<< "| 0 - back to main menu,  |\n"
		<< "| (ID) - edit to do item. |\n"
		<< "---------------------------\n";
	cout << "| ---> ";
	cin >> index;
	if (index == 0 || index > amount) return obj;
	--index;
	system("cls");
	showData(obj, index);
	cout << "-----------------------------\n"
		<< "| 0 - back to main menu,    |\n"
		<< "| (Line number 1-3) - edit. |\n"
		<< "-----------------------------\n";
	cout << "| ---> ";
	cin >> choice;
	if (choice == 0 || choice > 3) return obj;
	cout << "---------------------------\n"
		<< "| (Your new info) - edit. |\n"
		<< "---------------------------\n";
	cout << "| ---> ";
	cin.ignore();
	getline(cin, newInfo);

	switch (choice)
	{
	case 1:
		obj[index].name = newInfo;
		break;
	case 2:
		obj[index].due_date = newInfo;
		break;
	case 3:
		obj[index].description = newInfo;
		break;
	}

	return obj;
}
