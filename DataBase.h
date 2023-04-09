/**
\file DataBase.h
\brief Модуль "База данных" - содержит данные о Пользователях
Предоставляет функции работы с базой данных Пользователей:
- проверить есть ли заданный Логин в Базе
- проверить корректный ли Пароль
- добавить пользователя в Базу
*/

#pragma once
#include <string>
#include <vector>
#include <list>
#include <memory>

#include "Message.h"
#include "User.h"


namespace database {
	/**
	Заполнить базу начальными значениями
	*/
	void initialize();

	/**
	Добавить нового пользователя в базу
	\param[in] name Ник пользователя
	\param[in] login Логин пользователя
	\param[in] password Пароль пользователя
	*/
	void addUser(const std::string& name,
		const std::string& login,
		const std::string& password);

	/**
	Проверить есть ли в базе заданный Логин
	\param[in] login Логин
	\return Признак наличия заданного Логина в базе
	*/
	bool isExistLogin(const std::string& login);

	/**
	Проверить есть ли в базе заданный Ник
	\param[in] name Ник
	\return Признак наличия заданного Ника в базе
	*/
	bool isExistName(const std::string& name);

	/**
	Проверить соответствует ли Пароль заданному Логину
	\param[in] login Логин
	\param[in] password Пароль
	\return Признак правильный ли Пароль
	*/
	bool isCorrectPassword(const std::string& login, const std::string& password);

	/**
	Добавить в базу сообщение от одного пользователя другому.
	\param[in] message Сообщение
	*/
	void pushMessage(const Message& message);

	/**
	Загрузить сообщения, адресованные заданному пользователю
	\param[in] addressee Адресат сообщений
	\param[in] destination Умный указатель на вектор в который поместить сообщения
	*/
	void loadMessages(const User& addressee, std::shared_ptr<std::list<Message> > destination);

	/**
	Удалить заданного пользователя из базы
	\param[in] login Логин пользователя которого удалить
	*/
	void removeUser(const std::string& login);

	/**
	Вернуть ник по логину.
	Если логин не зарегистрирован - возвращает пустую строку
	\param[in] login Логин
	\return Ник пользователя
	*/
	std::string getNameByLogin(const std::string& login);

	/**
	\return Количество зарегистрированных пользователей
	*/
	size_t getNumberUser();

	/**
	Загрузить имена зарегистрированных пользователей
	\param[in] userNames Умный указатель на вектор в который поместить имена пользователей
	*/
	void loadUserNames(std::shared_ptr<std::vector<std::string> > userNames);

	/**
	Запустить тесты методов модуля
	*/
	void test();
}