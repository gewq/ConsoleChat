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

	User u2("name_2", "login_2", "1");
	users.push_back(u2);
	assert(database::isExistName("name_2") == true);
	assert(database::isExistName("not_exist") == false);

	//Очистить от тестовых значений
	users.clear();
	assert(users.empty() == true);
}