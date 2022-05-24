#include <iostream>
#include "windows.h"
#include <string>
#include <cstring>

// My Git: https://github.com/EremK

//	Реализовать список дел :
//	-> Добавить
//	-> Удалить
//	-> Изменить
//	-> Очистить весь список дел
// 
//	Использовать:
//	-> Структура TodoItem : id, name, description, due_date, что - то еще...
//	-> Структура TodoList : id, name, todoItems[]
// 
//	GIT:
//	-> Создать ветку develop
//	-> Для каждой отдельной функции реализовать отдельную ветку features / номер - задачи - название - задачи
//	-> После имплементации в ветках - merge в develop веток
//	-> Решить возможные merge конфликты
//	-> Локальные feature ветки удалить, в origin(github) эти ветки оставить
//	-> Слить все в master(develop оставить локально и удаленно)

using namespace std;