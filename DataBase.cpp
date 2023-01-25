#include "DataBase.h"

#include <vector>
#include <assert.h>
#include <iostream>

#include "User.h"
#include "Message.h"

namespace {
	//Имя адресата чтобы отправить сообщение всем
	const std::string MSG_TO_ALL = "all";

	std::vector<User> users;		//База зарегистрированных пользователей
	std::vector<Message> messages;	//База сообщений пользователей друг другу
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



void database::putMessage(const Message& message)
{
	messages.push_back(message);
}



void database::loadMessages(const User& user, std::vector<Message>* destination)
{
	destination->clear();
	//Пройти по сообщениям в базе
	for (auto& message : messages) {
		//Если адресат сообщения совпадает с заданным пользователем
		//или сообщение ВСЕМ
		if (message.getNameTo() == user.getName() ||
			(message.getNameTo() == MSG_TO_ALL)) {
			destination->push_back(message);
		}
	}
}



void database::addUser(const User& user)
{
	//Если пользователь ещё не в базе данных
	if (!isExistLogin(user.getLogin())) {
		users.push_back(user);
	}
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

/**
Запустить тест функции putMessage()
*/
static void testPutMessage();

/**
Запустить тест функции loadMessages()
*/
static void testLoadMessages();

/**
Запустить тест функции addUser()
*/
static void testAddUser();



void database::test()
{
	testIsExistLogin();
	testIsExistName();
	testIsCorrectPassword();
	testGetUserPosition();
	testPutMessage();
	testLoadMessages();
	testAddUser();
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



static void testPutMessage()
{
	const std::string nameFrom = "nameFrom";
	const std::string nameTo = "nameTo";
	const std::string text = "Hello nameTo!";
	Message message(nameFrom, nameTo, text);	//Создать сообщение
	database::putMessage(message);				//Поместить в базу сообщений
	assert(messages.at(0).getNameFrom() == nameFrom);
	assert(messages.at(0).getNameTo() == nameTo);
	assert(messages.at(0).getText() == text);

	//Очистить от тестовых значений
	messages.clear();
	assert(messages.empty() == true);
}



static void testLoadMessages()
{
	User u1("name_1", "login_1", "pass_1");
	User u2("name_2", "login_2", "pass_2");
	User u3("name_3", "login_3", "pass_3");

	//Создать сообщения
	Message messageU1_U2(u1.getName(), u2.getName(), "U1 -> U2");
	Message messageU1_U3(u1.getName(), u3.getName(), "U1 -> U3");
	Message messageU2_U3(u2.getName(), u3.getName(), "U2 -> U3");
	Message messageU1_ALL(u1.getName(), MSG_TO_ALL, "U1 -> ALL");
	//Поместить сообщения в базу данных
	database::putMessage(messageU1_U2);
	database::putMessage(messageU1_U3);
	database::putMessage(messageU2_U3);
	database::putMessage(messageU1_ALL);

	std::vector<Message> messagesToUser;//Вектор сообщений конкретному пользователю

	database::loadMessages(u1, &messagesToUser);	//Заполнить вектор сообщениями адресату
	assert(messagesToUser.size() == 1);

	database::loadMessages(u2, &messagesToUser);
	assert(messagesToUser.size() == 2);

	database::loadMessages(u3, &messagesToUser);

	assert(messagesToUser.size() == 3);
	assert(messagesToUser.at(0).getNameFrom() == u1.getName());
	assert(messagesToUser.at(0).getNameTo() == u3.getName());
	assert(messagesToUser.at(0).getText() == "U1 -> U3");

	assert(messagesToUser.at(1).getNameFrom() == u2.getName());
	assert(messagesToUser.at(1).getNameTo() == u3.getName());
	assert(messagesToUser.at(1).getText() == "U2 -> U3");

	assert(messagesToUser.at(2).getNameFrom() == u1.getName());
	assert(messagesToUser.at(2).getNameTo() == MSG_TO_ALL);
	assert(messagesToUser.at(2).getText() == "U1 -> ALL");
}



static void testAddUser()
{
	//Поместить тестовое значение
	User user("name", "login", "password");
	database::addUser(user);
	assert(database::isExistName(user.getName()) == true);
	assert(database::isExistLogin(user.getLogin()) == true);
	assert(database::isCorrectPassword(user.getLogin(), user.getPassword()) == true);
	//Очистить от тестовых значений
	users.clear();
	assert(users.empty() == true);
}