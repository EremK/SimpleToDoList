#include "header.h"
#include "funcs.h"

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
ToDoItem* AddStruct(ToDoItem* obj, const int amount)
{
	if (amount == 0)
	{
		obj = new ToDoItem[amount + 1];
	}
	else
	{
		ToDoItem* tempObj = new ToDoItem[amount + 1];

		for (int i = 0; i < amount; i++)
		{
			tempObj[i] = obj[i];
=======
ToDoItem* DelStruct(ToDoItem* obj, const int index, const int amount)
{
	if (amount == 0 || index > amount || index < 0)
	{
		return obj;
	}
	else
	{
		ToDoItem* tempObj = new ToDoItem[amount - 1];
		int p = 0;

		for (int i = 0; i < amount; i++)
		{
			if (i == index) continue;
			tempObj[p] = obj[i];
			p++;
>>>>>>> features/2-DelStruct
		}
		delete[] obj;
		obj = tempObj;
=======
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
>>>>>>> features/4-EditStruct
	}

	return obj;
}
<<<<<<< HEAD
=======
void showData(ToDoItem* Obj, const int index)
{
	cout << "--------------------------\n";
	cout << "0. To do item ID: " << Obj[index].id << endl;
	cout << "1. Name: " << Obj[index].name << endl;
	cout << "2. Due date: " << Obj[index].due_date << endl;
	cout << "3. Desription: " << Obj[index].description << endl;
	cout << "--------------------------\n";
}
>>>>>>> features/3-ShowData
=======
>>>>>>> features/4-EditStruct
