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

<<<<<<< HEAD
<<<<<<< HEAD
ToDoItem* AddStruct(ToDoItem* obj, const int amount);
=======
ToDoItem* DelStruct(ToDoItem* obj, const int index, const int amount);
>>>>>>> features/2-DelStruct

=======
void showData(ToDoItem* Obj, const int index);
>>>>>>> features/3-ShowData
