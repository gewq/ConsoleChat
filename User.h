/**
\file User.h
\brief Класс содержит данные о пользователе
Класс инкапсулирует в себе параметры пользователя:
- Ник (имя) - по нику он будет известен другим пользователям
- Логин - имя по которому он будет заходить в чат
- Хэш Пароля
*/

#pragma once

#include <string>

class User {
public:
	User();
	User(const std::string& name,
		const std::string& login,
		const std::string& password,
		const std::string& hashPassword);

	/**
	Перегрузка оператора '==' для поиска пользователя в базе данных
	с использованием алгоритмов STL
	*/
	bool operator==(User other) const;

	/**
	\return Ник пользователя
	*/
	std::string getName() const;

	/**
	\return Логин пользователя
	*/
	std::string getLogin() const;

	/**
	\return Пароль
	*/
	std::string getPassword() const;

	/**
	\return Хеш Пароля
	*/
	std::string getHashPassword() const;

	/**
	Задать пользователю Имя
	\param[in] name Имя
	*/
	void setName(const std::string& name);

	/**
	Задать пользователю Логин
	\param[in] login Логин
	*/
	void setLogin(const std::string& login);

	/**
	Задать пользователю Пароль
	\param[in] hashPassword Хэш Пароля
	*/
	void setPassword(const std::string& password);

	/**
	Задать пользователю Хеш Пароля
	\param[in] hashPassword Хэш Пароля
	*/
	void setHashPassword(const std::string& hashPassword);

	/**
	Присвоить значения полей класса - пустая строка
	*/
	void reset();

private:
	std::string name_;		///<Ник
	std::string login_;		///<Логин
	std::string password_;	///<Пароль
	std::string hashPassword_;	///<Хеш Пароля
};



namespace user {
	/**
	Запустить тестирование методов класса
	*/
	void test();
}