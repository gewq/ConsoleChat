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
	bool isExistLogin(std::string login);

	/**
	Проверить соответствует ли Пароль заданному Логину
	\param[in] login Логин
	\param[in] password Пароль
	\return Признак правильный ли Пароль
	*/
	bool isCorrectPassword(std::string login, std::string password);

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