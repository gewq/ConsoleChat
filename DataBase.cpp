#include "DataBase.h"

#include <vector>
#include <assert.h>
#include <iostream>

#include "User.h"
#include "Message.h"

namespace {
	std::vector<User> users;		//Зарегистрированные пользователи
	std::vector<Message> messages;	//Архив сообщений пользователей друг другу
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
	for (auto& user : users) {
		if (user.getLogin() == login) {
			return true;
		}
	}
	return false;
}



bool database::isExistName(const std::string& name)
{
	//Range-based loop
	for (auto& user : users) {
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
	if (isExistLogin(login)) {
		int8_t userPosition = getUserPosition(login);
		if (users.at(userPosition).getPassword() == password) {
			return true;
		}
	}
	return false;
}


/**
Запустить тест функции isExistLogin()
*/
static void testIsExistLogin();

/**
Запустить тест функции isExistName()
*/
static void testIsExistName();

/**
Запустить тест функции isCorrectPassword()
*/
static void testIsCorrectPassword();

/**
Запустить тест функции getUserPosition()
*/
static void testGetUserPosition();



void database::test()
{
	testIsExistLogin();
	testIsExistName();
	testIsCorrectPassword();
	testGetUserPosition();
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



static void testIsExistLogin()
{
	//Поместить тестовое значение
	User user("name", "login", "password");
	users.push_back(user);

	assert(database::isExistLogin(user.getLogin()) == true);
	assert(database::isExistLogin("incorrect_login") == false);

	//Очистить от тестовых значений
	users.clear();
	assert(users.empty() == true);
}



static void testIsExistName()
{
	//Поместить тестовое значение
	User user("name", "login", "password");
	users.push_back(user);

	assert(database::isExistName(user.getName()) == true);
	assert(database::isExistName("incorrect_name") == false);

	//Очистить от тестовых значений
	users.clear();
	assert(users.empty() == true);
}



static void testIsCorrectPassword()
{
	//Поместить тестовое значение
	User user("name", "login", "password");
	users.push_back(user);

	assert(database::isCorrectPassword(user.getLogin(), user.getPassword()) == true);
	assert(database::isCorrectPassword(user.getLogin(), "incorrect_password") == false);
	assert(database::isCorrectPassword("incorrect_login", user.getPassword()) == false);

	//Очистить от тестовых значений
	users.clear();
	assert(users.empty() == true);
}



static void testGetUserPosition()
{
	//Поместить тестовое значение
	User user_1("name_1", "login_1", "password_1");
	User user_2("name_2", "login_2", "password_2");
	users.push_back(user_1);
	users.push_back(user_2);

	assert(getUserPosition(user_1.getLogin()) == 0);
	assert(getUserPosition(user_2.getLogin()) == 1);

	//Очистить от тестовых значений
	users.clear();
	assert(users.empty() == true);
}