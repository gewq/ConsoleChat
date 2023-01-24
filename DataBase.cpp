#include "DataBase.h"

#include <vector>
#include <assert.h>
#include <iostream>

#include "User.h"

namespace {
	//Зарегистрированные пользователи
	std::vector<User> users;
}



void database::initialize()
{
	User u1("G", "Ger", "123");
	User u2("S", "Sve", "qwe");
	users.push_back(u1);
	users.push_back(u2);
}



bool database::isExistLogin(const std::string& login)
{
	//Range-based loop
	for (User user : users) {
		if (user.getLogin() == login) {
			return true;
		}
	}
	return false;
}



bool database::isExistName(const std::string& name)
{
	//Range-based loop
	for (User user : users) {
		if (user.getName() == name) {
			return true;
		}
	}
	return false;
}



/**
Найти индекс пользователя в базе по логину
Если пользователь не найден - возвращает -1
\param[in] login Логин пользователя
\return Индекс в векторе пользователей
*/
static int8_t getUserPosition(const std::string& login);


bool database::isCorrectPassword(const std::string& login, const std::string& password)
{
	return false;
}



void database::test()
{
	//Поместить тестовое значение
	User u1("1", "login_1", "1");
	User u2("name_2", "login_2", "1");
	users.push_back(u1);
	users.push_back(u2);

	assert(database::isExistLogin("login_1") == true);
	assert(database::isExistLogin("not_exist") == false);

	assert(database::isExistName("name_2") == true);
	assert(database::isExistName("not_exist") == false);

	assert(getUserPosition("login_1") == 0);
	assert(getUserPosition("login_2") == 1);

	//Очистить от тестовых значений
	users.clear();
	assert(users.empty() == true);
}



static int8_t getUserPosition(const std::string& login)
{
	//Ищем объект класса User
	User wanted("1", login, "1");	//При поиске сравниваем только login
	//Итератор - const чтобы нельзя было изменить вектор или объект в нём
	std::vector<User>::const_iterator iterator =
		std::find(users.begin(), users.end(), wanted);

	//Элемент НЕ найден
	if (iterator == users.end()) {
		return -1;
	}
	//Элемент НАЙДЕН
	else {
		return static_cast<int8_t> (iterator - users.begin());
	}
}