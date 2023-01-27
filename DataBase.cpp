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




void database::test()
{
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