#include "DataBase.h"

#include <vector>
#include <list>
#include <assert.h>
#include <iostream>

#include "sha1.hpp"

#include "User.h"
#include "Message.h"

namespace {
	//Имя адресата чтобы отправить сообщение всем
	const std::string MSG_TO_ALL = "all";

	std::vector<User> users;		//База зарегистрированных пользователей
	std::list<Message> messages;	//База сообщений пользователей друг другу
}



void database::initialize()
{
	std::string password = "123";
	auto checksum = std::make_unique<SHA1>();
	checksum->update(password);
	std::string hash = checksum->final();
	User u1("G", "Ger", hash);

	password = "qwe";
	checksum->update(password);
	hash = checksum->final();
	User u2("S", "Sve", hash);

	users.push_back(u1);
	users.push_back(u2);
}



bool database::isExistLogin(const std::string& login)
{
	//Range-based loop
	for (const auto& user : users) {
		if (user.getLogin() == login) {
			return true;
		}
	}
	return false;
}



bool database::isExistName(const std::string& name)
{
	//Range-based loop
	for (const auto& user : users) {
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
	//Пользователь не зарегистрирован
	if (!isExistLogin(login)) {
		return false;
	}

	int8_t userPosition = getUserPosition(login);
	//Хэш введённого пароля совпадает с хэшэм пароля в базе
	auto checksum = std::make_unique<SHA1>();
	checksum->update(password);
	const std::string hashInputPassword = checksum->final();
	if (users.at(userPosition).getHashPassword() == hashInputPassword) {
		return true;
	}

	return false;
}



void database::pushMessage(const Message& message)
{
	messages.push_back(message);
}



void database::loadMessages(const User& addressee, std::shared_ptr<std::list<Message> > destination)
{
	destination->clear();
	//Пройти по сообщениям в базе
	for (const auto& message : messages) {
		//Если адресат сообщения совпадает с заданным пользователем
		//или сообщение ВСЕМ
		if (message.getNameTo() == addressee.getName() ||
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
Удалить из базы все сообщения, адресованные пользователю с заданным ником
\param[in] name Ник пользователя
*/
static void removeMessagesToUser(const std::string& name);

void database::removeUser(const User& user)
{
	removeMessagesToUser(user.getName());
	users.erase(std::remove(users.begin(), users.end(), user), users.end());
}



std::string database::getNameByLogin(const std::string& login)
{
	if (isExistLogin(login)) {
		int userPosition = getUserPosition(login);
		return users.at(userPosition).getName();
	}
	return "";
}



size_t database::getNumberUser()
{
	return users.size();
}



void database::loadUserNames(std::shared_ptr<std::vector<std::string> > userNames)
{
	userNames->clear();
	for (const auto& user : users) {
		userNames->push_back(user.getName());
	}
}



static void testIsExistLogin();
static void testIsExistName();
static void testIsCorrectPassword();
static void testGetUserPosition();
static void testPushMessage();
static void testLoadMessages();
static void testAddUser();
static void testRemoveUser();
static void testGetNameByLogin();
static void testGetNumberUser();
static void testLoadUserNames();
static void testRemoveMessagesToUser();


void database::test()
{
	testIsExistLogin();
	testIsExistName();
	testIsCorrectPassword();
	testGetUserPosition();
	testPushMessage();
	testLoadMessages();
	testAddUser();
	testRemoveUser();
	testGetNameByLogin();
	testGetNumberUser();
	testLoadUserNames();
	testRemoveMessagesToUser();
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



static void removeMessagesToUser(const std::string& name)
{
	//Удалить сообщение по условию true
	messages.remove_if([&name](const Message& message) {
		//Если адресат текущего сообщения совпадает с заданным именем
		if (message.getNameTo() == name) {
			return true;
		}
		return false;
		});
}



static void testIsExistLogin()
{
	//Поместить тестовое значение
	User user("name", "login", "3833b3a1c69cf71a31d86cb5bb4d3866789b4d1e");
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
	User user("name", "login", "3833b3a1c69cf71a31d86cb5bb4d3866789b4d1e");
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
	const std::string password = "password";
	auto checksum = std::make_unique<SHA1>();
	checksum->update(password);
	const std::string hash = checksum->final();

	User user("name", "login", hash);
	users.push_back(user);

	assert(database::isCorrectPassword(user.getLogin(), password) == true);
	assert(database::isCorrectPassword(user.getLogin(), "incorrect_password") == false);
	assert(database::isCorrectPassword("incorrect_login", password) == false);

	//Очистить от тестовых значений
	users.clear();
	assert(users.empty() == true);
}



static void testGetUserPosition()
{
	//Поместить тестовое значение
	User user_1("user_1", "login_1", "3833b3a1c69cf71a31d86cb5bb4d3866789b4d1e");
	User user_2("user_2", "login_2", "148dfdc3c539d35004cb808ca84e17ff962af744");
	users.push_back(user_1);
	users.push_back(user_2);

	assert(getUserPosition(user_1.getLogin()) == 0);
	assert(getUserPosition(user_2.getLogin()) == 1);

	//Очистить от тестовых значений
	users.clear();
	assert(users.empty() == true);
}



static void testPushMessage()
{
	messages.clear();
	const std::string nameFrom = "nameFrom";
	const std::string nameTo = "nameTo";
	const std::string text = "Hello nameTo!";
	Message message(nameFrom, nameTo, text);	//Создать сообщение
	database::pushMessage(message);				//Поместить в базу сообщений
	assert(messages.front().getNameFrom() == nameFrom);
	assert(messages.front().getNameTo() == nameTo);
	assert(messages.front().getText() == text);

	//Очистить от тестовых значений
	messages.clear();
	assert(messages.empty() == true);
}



static void testLoadMessages()
{
	messages.clear();
	User u1("name_1", "login_1", "5baa61e4c9b93f3f0682250b6cf8331b7ee68fd8");
	User u2("name_2", "login_2", "f054ffc85b4c1615a7190ea0b248564bb1e9f9ab");

	//Создать сообщения
	Message messageU1_U2(u1.getName(), u2.getName(), "U1 -> U2");
	Message messageU2_U1(u2.getName(), u1.getName(), "U2 -> U1");
	Message messageU1_ALL(u1.getName(), MSG_TO_ALL, "U1 -> ALL");
	//Поместить сообщения в базу данных
	database::pushMessage(messageU1_U2);
	database::pushMessage(messageU2_U1);
	database::pushMessage(messageU1_ALL);

	//Укзатель на сообщения конкретному пользователю
	auto messagesToUser = std::make_shared<std::list<Message> >();

	database::loadMessages(u1, messagesToUser);	//Заполнить вектор сообщениями адресату
	assert(messagesToUser->size() == 2);
	assert(messagesToUser->front().getNameFrom() == u2.getName());
	assert(messagesToUser->front().getNameTo() == u1.getName());
	assert(messagesToUser->front().getText() == "U2 -> U1");
	assert(messagesToUser->back().getNameFrom() == u1.getName());
	assert(messagesToUser->back().getNameTo() == MSG_TO_ALL);
	assert(messagesToUser->back().getText() == "U1 -> ALL");

	database::loadMessages(u2, messagesToUser);
	assert(messagesToUser->size() == 2);
	assert(messagesToUser->front().getNameFrom() == u1.getName());
	assert(messagesToUser->front().getNameTo() == u2.getName());
	assert(messagesToUser->front().getText() == "U1 -> U2");
	assert(messagesToUser->back().getNameFrom() == u1.getName());
	assert(messagesToUser->back().getNameTo() == MSG_TO_ALL);
	assert(messagesToUser->back().getText() == "U1 -> ALL");

	//Очистить от тестовых значений
	messages.clear();
	assert(messages.empty() == true);
}



static void testAddUser()
{
	//Поместить тестовое значение
	const std::string password = "password";
	auto checksum = std::make_unique<SHA1>();
	checksum->update(password);
	const std::string hash = checksum->final();

	User user("name", "login", hash);

	database::addUser(user);
	assert(database::isExistName(user.getName()) == true);
	assert(database::isExistLogin(user.getLogin()) == true);
	assert(database::isCorrectPassword(user.getLogin(), password) == true);
	//Очистить от тестовых значений
	users.clear();
	assert(users.empty() == true);
}



static void testRemoveUser()
{
	//Поместить тестовое значение
	User user("name", "login", "5baa61e4c9b93f3f0682250b6cf8331b7ee68fd8");
	database::addUser(user);
	database::removeUser(user);

	assert(users.empty() == true);
	assert(database::isExistName(user.getName()) == false);
	assert(database::isExistLogin(user.getLogin()) == false);
	assert(database::isCorrectPassword(user.getLogin(), user.getHashPassword()) == false);

	//Очистить от тестовых значений
	users.clear();
	assert(users.empty() == true);
}



static void testGetNameByLogin()
{
	//Поместить тестовое значение
	User user("name", "login", "5baa61e4c9b93f3f0682250b6cf8331b7ee68fd8");
	users.push_back(user);

	assert(database::getNameByLogin(user.getLogin()) == user.getName());
	assert(database::getNameByLogin("Not_Exist") == "");
	//Очистить от тестовых значений
	users.clear();
	assert(users.empty() == true);
}



static void testGetNumberUser()
{
	//Поместить тестовое значение
	User user("name", "login", "5baa61e4c9b93f3f0682250b6cf8331b7ee68fd8");
	users.push_back(user);
	assert(database::getNumberUser() == 1);

	//Поместить тестовое значение
	User user2("name", "login", "5baa61e4c9b93f3f0682250b6cf8331b7ee68fd8");
	users.push_back(user2);
	assert(database::getNumberUser() == 2);
	//Очистить от тестовых значений
	users.clear();
	assert(users.empty() == true);
}



static void testLoadUserNames()
{
	//Поместить тестовое значение
	User user_1("user_1", "login_1", "3833b3a1c69cf71a31d86cb5bb4d3866789b4d1e");
	User user_2("user_2", "login_2", "148dfdc3c539d35004cb808ca84e17ff962af744");
	users.push_back(user_1);
	users.push_back(user_2);

	//Укзатель на вектор сообщений конкретному пользователю
	auto userNames = std::make_shared<std::vector<std::string> >();

	database::loadUserNames(userNames);
	assert(userNames->size() == 2);
	assert(userNames->at(0) == user_1.getName());
	assert(userNames->at(1) == user_2.getName());

	//Очистить от тестовых значений
	users.clear();
	assert(users.empty() == true);
}



static void testRemoveMessagesToUser()
{
	messages.clear();
	User u1("name_1", "login_1", "3833b3a1c69cf71a31d86cb5bb4d3866789b4d1e");
	User u2("name_2", "login_2", "148dfdc3c539d35004cb808ca84e17ff962af744");

	//Создать сообщения
	Message messageU1_U2(u1.getName(), u2.getName(), "U1 -> U2");
	Message messageU2_U1(u2.getName(), u1.getName(), "U2 -> U1");
	Message messageU1_ALL(u1.getName(), MSG_TO_ALL, "U1 -> ALL");
	//Поместить сообщения в базу данных
	database::pushMessage(messageU1_U2);
	database::pushMessage(messageU2_U1);
	database::pushMessage(messageU1_ALL);

	removeMessagesToUser(u1.getName());

	for (auto& message : messages) {
		//Нет сообщений адресованных пользователю u1
		assert((message.getNameTo() == u1.getName()) == false);
	}
	//Очистить от тестовых значений
	messages.clear();
	assert(messages.empty() == true);
}