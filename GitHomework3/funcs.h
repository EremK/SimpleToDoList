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

void showData(ToDoItem* Obj, const int index);