#include "header.h"
#include "funcs.h"

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
	}

	return obj;
}
