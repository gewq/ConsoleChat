#include "DataBase.h"

#include <map>
#include <list>
#include <assert.h>
#include <iostream>

#include "SHA_1_Wrapper.h"

#include "User.h"

namespace {
	//Имя адресата чтобы отправить сообщение всем
	const std::string MSG_TO_ALL = "all";

	/*
	Хэш таблица данных пользователей
	Ключ 	 - Логин пользователя
	Значение - Пользователь
	*/
	std::map <std::string, User> userData;
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




void database::pushMessage(const std::string& nameAdressee,
	const Message& message)
{
	//Сообщение для всех
	if (nameAdressee == MSG_TO_ALL) {
		//Каждому пользователю в базе отправить сообщение
		for (auto& dataPair : userData) {
			dataPair.second.setMessage(message);
		}
	}

	//Сообщение личное
	else {
		//Пользователь не зарегистрирован
		if (!isExistName(nameAdressee)) {
			return;
		}
		userData[database::getLoginByName(nameAdressee)].setMessage(message);
	}
}



void database::loadMessages(const std::string& login, std::shared_ptr<std::list<Message> >& messages)
{
	//Пользователь не зарегистрирован
	if (!isExistLogin(login)) {
		return;
	}

	messages->clear();
	messages = userData[login].getMessageList();
}


void database::removeUser(const std::string& login)
{
	userData.erase(login);
}



std::string database::getNameByLogin(const std::string& login)
{
	//Логина нет в базе
	if (!database::isExistLogin(login)) {
		return "";
	}
	return userData.find(login)->second.getName();
}



std::string database::getLoginByName(const std::string& name)
{
	//Пользователь не зарегистрирован
	if (!isExistName(name)) {
		return "";
	}

	for (const auto& dataPair : userData) {
		if (dataPair.second.getName() == name) {
			return dataPair.second.getLogin();
		}
	}
	return "";
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



//=========================================================================================================
static void testIsExistLogin();
static void testIsExistName();
static void testIsCorrectPassword();
static void testPushMessage();
static void testLoadMessages();
static void testRemoveUser();
static void testGetNameByLogin();
static void testGetLoginByName();
static void testGetNumberUser();
static void testLoadUserNames();


void database::test()
{
	testIsExistLogin();
	testIsExistName();
	testIsCorrectPassword();
	testPushMessage();
	testLoadMessages();
	testRemoveUser();
	testGetNameByLogin();
	testGetLoginByName();
	testGetNumberUser();
	testLoadUserNames();

	//После тестов база должна быть пуста
	assert(userData.empty() == true);
}



static void testIsExistLogin()
{
	//Поместить тестовое значение
	const std::string login = "login";
	database::addUser("name", login, "password");

	assert(database::isExistLogin(login) == true);
	assert(database::isExistLogin("incorrect_login") == false);

	//Очистить от тестовых значений
	userData.clear();
}



static void testIsExistName()
{
	//Поместить тестовое значение
	const std::string name = "name";
	database::addUser(name, "login", "password");

	assert(database::isExistName(name) == true);
	assert(database::isExistName("incorrect_name") == false);

	//Очистить от тестовых значений
	userData.clear();
}



static void testIsCorrectPassword()
{
	//Поместить тестовое значение
	const std::string login = "login";
	const std::string password = "password";
	database::addUser("name", login, password);

	assert(database::isCorrectPassword(login, password) == true);
	assert(database::isCorrectPassword(login, "incorrect_password") == false);
	assert(database::isCorrectPassword("incorrect_login", password) == false);

	//Очистить от тестовых значений
	userData.clear();
}



static void testPushMessage()
{
	//Поместить тестовое значение
	User user_1("name_1", "login_1", "1", "1");
	User user_2("name_2", "login_2", "1", "1");
	User user_3("name_3", "login_3", "1", "1");

	database::addUser(user_1.getName(), user_1.getLogin(), user_1.getPassword());
	database::addUser(user_2.getName(), user_2.getLogin(), user_2.getPassword());
	database::addUser(user_3.getName(), user_3.getLogin(), user_3.getPassword());

	//Собщение User_1 -> User_2
	const std::string nameFromUser = user_1.getName();
	const std::string nameToUser = user_2.getName();
	const std::string textToUser = "Hello " + nameToUser;
	database::pushMessage(nameToUser, Message(nameFromUser, textToUser));

	//Собщение User_2 -> ALL
	const std::string nameFromToAll = user_2.getName();
	const std::string nameToAll = MSG_TO_ALL;
	const std::string textToAll = "Hello ALL";
	database::pushMessage(nameToAll, Message(nameFromToAll, textToAll));

	assert(userData[user_1.getLogin()].getMessageList()->back().getNameFrom() == nameFromToAll);
	assert(userData[user_1.getLogin()].getMessageList()->back().getText() == textToAll);
	assert(userData[user_1.getLogin()].getMessageList()->size() == 1);

	assert(userData[user_2.getLogin()].getMessageList()->back().getNameFrom() == nameFromUser);
	assert(userData[user_2.getLogin()].getMessageList()->back().getText() == textToUser);
	assert(userData[user_2.getLogin()].getMessageList()->front().getNameFrom() == nameFromToAll);
	assert(userData[user_2.getLogin()].getMessageList()->front().getText() == textToAll);
	assert(userData[user_2.getLogin()].getMessageList()->size() == 2);

	assert(userData[user_3.getLogin()].getMessageList()->back().getNameFrom() == nameFromToAll);
	assert(userData[user_3.getLogin()].getMessageList()->back().getText() == textToAll);
	assert(userData[user_3.getLogin()].getMessageList()->size() == 1);

	//Очистить от тестовых значений
	userData.clear();
}



static void testLoadMessages()
{
	//Поместить тестовое значение
	User user_1("name_1", "login_1", "1", "1");
	User user_2("name_2", "login_2", "1", "1");
	User user_3("name_3", "login_3", "1", "1");

	database::addUser(user_1.getName(), user_1.getLogin(), user_1.getPassword());
	database::addUser(user_2.getName(), user_2.getLogin(), user_2.getPassword());
	database::addUser(user_3.getName(), user_3.getLogin(), user_3.getPassword());

	//Собщение User_1 -> User_2
	const std::string nameFromUser = user_1.getName();
	const std::string nameToUser = user_2.getName();
	const std::string textToUser = "Hello " + nameToUser;
	database::pushMessage(nameToUser, Message(nameFromUser, textToUser));

	//Собщение User_2 -> ALL
	const std::string nameFromToAll = user_2.getName();
	const std::string nameToAll = MSG_TO_ALL;
	const std::string textToAll = "Hello ALL";
	database::pushMessage(nameToAll, Message(nameFromToAll, textToAll));

	//Укзатель на сообщения конкретному пользователю
	auto messagesToUser_1 = std::make_shared<std::list<Message> >();
	auto messagesToUser_2 = std::make_shared<std::list<Message> >();
	auto messagesToUser_3 = std::make_shared<std::list<Message> >();
	database::loadMessages(user_1.getLogin(), messagesToUser_1);
	database::loadMessages(user_2.getLogin(), messagesToUser_2);
	database::loadMessages(user_3.getLogin(), messagesToUser_3);

	assert(messagesToUser_1->back().getNameFrom() == nameFromToAll);
	assert(messagesToUser_1->back().getText() == textToAll);
	assert(messagesToUser_1->size() == 1);

	assert(messagesToUser_2->back().getNameFrom() == nameFromUser);
	assert(messagesToUser_2->back().getText() == textToUser);
	assert(messagesToUser_2->front().getNameFrom() == nameFromToAll);
	assert(messagesToUser_2->front().getText() == textToAll);
	assert(messagesToUser_2->size() == 2);

	assert(messagesToUser_3->back().getNameFrom() == nameFromToAll);
	assert(messagesToUser_3->back().getText() == textToAll);
	assert(messagesToUser_3->size() == 1);

	//Очистить от тестовых значений
	userData.clear();
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


static void testGetLoginByName()
{
	//Поместить тестовое значение
	const std::string name = "name";
	const std::string login = "login";
	const std::string password = "password";
	database::addUser(name, login, password);

	assert(database::getLoginByName(name) == login);
	assert(database::getLoginByName("Not_Exist") == "");

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