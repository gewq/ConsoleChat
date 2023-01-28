/**
\file User.h
\brief Класс содержит данные о пользователе

Класс инкапсулирует в себе параметры пользователя:
- Ник (имя) - по нику он будет известен другим пользователям
- Логин - имя по которому он будет заходить в чат
- Пароль
*/

#pragma once

#include <string>

class User {
	public:
		User();
		User(const std::string& name, const std::string& login, const std::string& password);

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
		\return Пароль пользователя
		*/
		std::string getPassword() const;

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
		\param[in] password Пароль
		*/
		void setPassword(const std::string& password);

		/**
		Присвоить значения полей класса пустой строке
		*/
		void reset();

	private:
		std::string name_;		///<Ник
		std::string login_;		///<Логин
		std::string password_;	///<Пароль
};



namespace user {
	/**
	Запустить тестирование методов класса
	*/
	void test();
}