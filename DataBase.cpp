#include "DataBase.h"

#include <map>
#include <list>
#include <assert.h>
#include <iostream>

#include "SHA_1_Wrapper.h"

#include "User.h"
#include "Message.h"

namespace {
	//Имя адресата чтобы отправить сообщение всем
	const std::string MSG_TO_ALL = "all";

	/*
	Хэш таблица данных пользователей
	Ключ 	 - Логин пользователя
	Значение - Пользователь
	*/
	std::map <std::string, User> userData;

	std::list<Message> messages;	//База сообщений пользователей друг другу
}



void database::initialize()
{
	database::addUser("G", "Ger", "123");
	database::addUser("S", "Sve", "qwe");
}



bool database::isExistLogin(const std::string& login)
{
	//Логина нет в базе
	if (userData.find(login) == userData.end()) {
		return false;
	}
	return true;
}



bool database::isExistName(const std::string& name)
{
	for (const auto& dataPair : userData) {
		if (dataPair.second.getName() == name) {
			return true;
		}
	}
	return false;
}



bool database::isCorrectPassword(const std::string& login, const std::string& password)
{
	//Пользователь не зарегистрирован
	if (!isExistLogin(login)) {
		return false;
	}

	//Хэш введённого пароля совпадает с хэшем пароля в базе
	if (sha_1::hash(password) == userData[login].getHashPassword()) {
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



/**
Удалить из базы все сообщения, адресованные пользователю с заданным ником
\param[in] name Ник пользователя
*/
static void removeMessagesToUser(const std::string& name);


void database::removeUser(const std::string& login)
{
	removeMessagesToUser(getNameByLogin(login));
	userData.erase(login);
}



std::string database::getNameByLogin(const std::string& login)
{
	//Итератор на пользователя с заданным логином
	auto userIterator = userData.find(login);

	//Логина нет в базе
	if (userIterator == userData.end()) {
		return "";
	}
	return userIterator->second.getName();
}



size_t database::getNumberUser()
{
	return userData.size();
}



void database::loadUserNames(std::shared_ptr<std::vector<std::string> > userNames)
{
	userNames->clear();
	for (const auto& dataPair : userData) {
		userNames->push_back(dataPair.second.getName());
	}
}



void database::addUser(const std::string& name,
	const std::string& login,
	const std::string& password)
{
	//Пользователь уже есть в базе
	if (userData.find(login) != userData.end()) {
		return;
	}
	//Данные пользователя не введены
	if (name.empty() || login.empty() || password.empty()) {
		return;
	}

	//Создать в базе пару Логин-Пользователь
	userData.emplace(std::make_pair(login, User(name, login, password, sha_1::hash(password))));
}



//---------------------------------------------------------------------------------------------------------
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



//=========================================================================================================
static void testIsExistLogin();
static void testIsExistName();
static void testIsCorrectPassword();
static void testPushMessage();
static void testLoadMessages();
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
	testPushMessage();
	testLoadMessages();
	testRemoveUser();
	testGetNameByLogin();
	testGetNumberUser();
	testLoadUserNames();
	testRemoveMessagesToUser();

	//После тестов база должна быть пуста
	assert(userData.empty() == true);
	assert(messages.empty() == true);
}



static void testIsExistLogin()
{
	//Поместить тестовое значение
	const std::string name = "name";
	const std::string login = "login";
	const std::string password = "password";
	database::addUser(name, login, password);

	assert(database::isExistLogin(login) == true);
	assert(database::isExistLogin("incorrect_login") == false);

	//Очистить от тестовых значений
	userData.clear();
}



static void testIsExistName()
{
	//Поместить тестовое значение
	const std::string name = "name";
	const std::string login = "login";
	const std::string password = "password";
	database::addUser(name, login, password);

	assert(database::isExistName(name) == true);
	assert(database::isExistName("incorrect_name") == false);

	//Очистить от тестовых значений
	userData.clear();
}



static void testIsCorrectPassword()
{
	//Поместить тестовое значение
	const std::string name = "name";
	const std::string login = "login";
	const std::string password = "password";
	database::addUser(name, login, password);

	assert(database::isCorrectPassword(login, password) == true);
	assert(database::isCorrectPassword(login, "incorrect_password") == false);
	assert(database::isCorrectPassword("incorrect_login", password) == false);

	//Очистить от тестовых значений
	userData.clear();
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
}



static void testLoadMessages()
{
	messages.clear();
	User u1("name_1", "login_1", "password_1", sha_1::hash("password_1"));
	User u2("name_2", "login_2", "password_2", sha_1::hash("password_2"));

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
}



static void testRemoveUser()
{
	//Поместить тестовое значение
	const std::string name = "name";
	const std::string login = "login";
	const std::string password = "password";
	database::addUser(name, login, password);

	database::removeUser(login);

	assert(userData.empty() == true);
	assert(database::isExistName(name) == false);
	assert(database::isExistLogin(login) == false);
	assert(database::isCorrectPassword(login, password) == false);

	//Очистить от тестовых значений
	userData.clear();
}



static void testGetNameByLogin()
{
	//Поместить тестовое значение
	const std::string name = "name";
	const std::string login = "login";
	const std::string password = "password";
	database::addUser(name, login, password);

	assert(database::getNameByLogin(login) == name);
	assert(database::getNameByLogin("Not_Exist") == "");

	//Очистить от тестовых значений
	userData.clear();
}



static void testGetNumberUser()
{
	//Поместить тестовое значение
	std::string name = "name_1";
	std::string login = "login_1";
	std::string password = "password_1";
	database::addUser(name, login, password);

	assert(database::getNumberUser() == 1);

	//Поместить тестовое значение
	name = "name_2";
	login = "login_2";
	password = "password_2";
	database::addUser(name, login, password);

	assert(database::getNumberUser() == 2);

	//Очистить от тестовых значений
	userData.clear();
}



static void testLoadUserNames()
{
	//Поместить тестовое значение
	const std::string name_1 = "name_1";
	const std::string login_1 = "login_1";
	const std::string password_1 = "password_1";

	const std::string name_2 = "name_2";
	const std::string login_2 = "login_2";
	const std::string password_2 = "password_2";

	database::addUser(name_1, login_1, password_1);
	database::addUser(name_2, login_2, password_2);

	//Укзатель на вектор сообщений конкретному пользователю
	auto userNames = std::make_shared<std::vector<std::string> >();

	database::loadUserNames(userNames);
	assert(userNames->size() == 2);
	assert(userNames->at(0) == name_1);
	assert(userNames->at(1) == name_2);

	//Очистить от тестовых значений
	userData.clear();
}



static void testRemoveMessagesToUser()
{
	const std::string name_1 = "name_1";
	const std::string login_1 = "login_1";
	const std::string password_1 = "password_1";

	const std::string name_2 = "name_2";
	const std::string login_2 = "login_2";
	const std::string password_2 = "password_2";

	//Создать сообщения
	Message messageU1_U2(name_1, name_2, "U1 -> U2");
	Message messageU2_U1(name_2, name_1, "U2 -> U1");
	Message messageU1_ALL(name_1, MSG_TO_ALL, "U1 -> ALL");
	//Поместить сообщения в базу данных
	database::pushMessage(messageU1_U2);
	database::pushMessage(messageU2_U1);
	database::pushMessage(messageU1_ALL);

	removeMessagesToUser(name_1);

	for (auto& message : messages) {
		//Нет сообщений адресованных пользователю u1
		assert((message.getNameTo() == name_1) == false);
	}

	//Очистить от тестовых значений
	messages.clear();
}