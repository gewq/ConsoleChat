#include "DataBase.h"

#include <vector>
#include <assert.h>

#include "User.h"

namespace {
	//Зарегистрированные пользователи
	std::vector<User> users;
}



void database::initialize()
{

}



bool database::isExistLogin(const std::string& login)
{
	//Ищем объект класса User
	User wanted("1", login, "1");	//При поиске сравниваем только login
	//Итератор - const! Чтобы нельзя было изменить вектор или данные в нём.
	std::vector<User>::const_iterator it =
		std::find(users.begin(), users.end(), wanted);	//Используем алгоритм STL (find)
	//Элемент не найден
	if (it == users.end()) {
		return false;
	}
	return true;
}



bool database::isCorrectPassword(const std::string& login, const std::string& password)
{
	return false;
}



void database::test()
{
	//Поместить тестовое значение
	User u1("1", "login_1", "1");
	users.push_back(u1);

	assert(database::isExistLogin("login_1") == true);
	assert(database::isExistLogin("not_exist") == false);

	//Очистить от тестовых значений
	users.clear();
	assert(users.empty() == true);
}