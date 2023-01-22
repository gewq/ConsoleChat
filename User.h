/**
\file User.h
\brief Класс содержит данные о пользователе
*/

#pragma once
#ifndef USER_H_SENTRY
#define USER_H_SENTRY

#include <string>

class User {
	public:
		User() = delete;
		User(std::string name, std::string login, std::string password);

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

	private:
		std::string name_;
		std::string login_;
		std::string password_;
};

#endif