#include "header.h"
#include "funcs.h"

ToDoItem* ClearStructArr(ToDoItem* obj)
{
	ToDoItem* tempObj = new ToDoItem[0];
	delete[] obj;
	obj = tempObj;
	return obj;
}