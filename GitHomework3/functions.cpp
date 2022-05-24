#include "header.h"
#include "funcs.h"

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
		}
		delete[] obj;
		obj = tempObj;
	}

	return obj;
}

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
		}
		delete[] obj;
		obj = tempObj;
	}

	return obj;
}

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

void showData(ToDoItem* Obj, const int index)
{
	cout << "--------------------------\n";
	cout << "0. To do item ID: " << Obj[index].id << endl;
	cout << "1. Name: " << Obj[index].name << endl;
	cout << "2. Due date: " << Obj[index].due_date << endl;
	cout << "3. Desription: " << Obj[index].description << endl;
	cout << "--------------------------\n";
}

ToDoItem* ClearStructArr(ToDoItem* obj)
{
	ToDoItem* tempObj = new ToDoItem[0];
	delete[] obj;
	obj = tempObj;
	return obj;
}

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

void menu(ToDoItem* obj, ToDoList list, int& amount)
{
	int choice;
	bool yesOrNo;

	while (true)
	{
		cout << "-----------MENU-----------\n"
			<< "| 0 - show the list      |\n"
			<< "| 1 - add to do item,    |\n"
			<< "| 2 - delete to do item, |\n"
			<< "| 3 - edit to do item,   |\n"
			<< "| 4 - clear to do list.  |\n"
			<< "--------------------------\n";
		cout << "| ---> ";
		cin >> choice;

		switch (choice)
		{
		case 0:
		{
			int conOrBack;

			while (true)
			{
				synchronizeAndShowList(list, obj, amount);
				cout << "---------------------------\n"
					<< "| 0 - back to main menu,  |\n"
					<< "| (ID) - show more info.  |\n"
					<< "---------------------------\n";
				cout << "| ---> ";
				cin >> conOrBack;

				if (conOrBack <= 0 || conOrBack > amount)
				{
					system("cls");
					break;
				}

				--conOrBack;
				showData(obj, conOrBack);
				system("pause");
			}
			break;
		}
		case 1:
		{
			do
			{
				obj = AddStruct(obj, amount);
				setData(obj, amount);

				amount++;

				cout << "Continue entering data (1 - yes, 0 - no): ";
				cin >> yesOrNo;
			} while (yesOrNo != 0);
			system("cls");
			break;
		}
		case 2:
		{
			int delOrBack;

			while (true)
			{
				synchronizeAndShowList(list, obj, amount);
				cout << "---------------------------\n"
					<< "| 0 - back to main menu,  |\n"
					<< "| (ID) - del to do item.  |\n"
					<< "---------------------------\n";
				cout << "| ---> ";
				cin >> delOrBack;

				if (delOrBack <= 0 || delOrBack > amount)
				{
					system("cls");
					break;
				}

				--delOrBack;
				obj = DelStruct(obj, delOrBack, amount);
				--amount;
				synchronizeAndShowList(list, obj, amount);
				system("pause");
			}
			break;
		}
		case 3:
		{
			bool cho = 1;

			while (cho)
			{
				synchronizeAndShowList(list, obj, amount);
				obj = EditStruct(obj, amount);

				cout << "-----Continue editing?---------\n"
					<< "| 0 - no, back to main menu,  |\n"
					<< "| 1 - yes.                    |\n"
					<< "-------------------------------\n";
				cout << "| ---> ";
				cin >> cho;
			}
			system("cls");
			break;
		}
		case 4:
		{
			ClearStructArr(obj);
			amount = 0;
			system("cls");
			break;
		}
		default:
			exit(0);
		}
	}
}
