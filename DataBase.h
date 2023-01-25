/**
\file DataBase.h
\brief Модуль "База данных" - содержит данные о Пользователях

Предоставляет функции работы с базой данных Пользователей:
- проверить есть ли заданный Логин в Базе
- проверить корректный ли Пароль
- добавить пользователя в Базу
*/

#pragma once
#ifndef DATA_BASE_H_SENTRY
#define DATA_BASE_H_SENTRY

#include <string>
#include <vector>

#include "Message.h"
#include "User.h"


namespace database {
	/**
	Заполнить базу начальными значениями
	*/
	void initialize();

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
	void putMessage(const Message& message);

	/**
	Загрузить сообщения, адресованные заданному пользователю
	\param[in] user Адресат сообщений
	\param[in] destination Вектор в который поместить сообщения
	*/
	void loadMessages(const User& user, std::vector<Message>* destination);

	/**
	Добавить в базу заданного пользователя
	\param[in] user Пользователь которого добавить
	*/
	//void addUser(User user);

	/**
	Запустить тесты методов модуля
	*/
	void test();
}

#endif