#include "header.h"
#include "funcs.h"

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