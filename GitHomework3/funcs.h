struct ToDoItem
{
	int id;
	string name;
	string due_date;
	string description;
};

struct ToDoList
{
	int id;
	string name;
	ToDoItem* ToDoItems;
};

ToDoItem* AddStruct(ToDoItem* obj, const int amount);

ToDoItem* DelStruct(ToDoItem* obj, const int index, const int amount);

void showData(ToDoItem* Obj, const int index);

ToDoItem* EditStruct(ToDoItem* obj, const int amount);

ToDoItem* ClearStructArr(ToDoItem* obj);

void setData(ToDoItem* Obj, const int amount);

void synchronizeAndShowList(ToDoList list, ToDoItem* obj, const int amount);

void menu(ToDoItem* obj, ToDoList list, int& amount);