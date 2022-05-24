#include "header.h"
#include "funcs.h"

int main() {
	ToDoList todolist;
	ToDoItem* todoitems = 0;
	int amount = 0;

	menu(todoitems, todolist, amount);

	delete[] todoitems;

	return 0;
}