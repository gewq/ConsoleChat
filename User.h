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
		User(const std::string& name, const std::string& login, const std::string& password);

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

	private:
		std::string name_;
		std::string login_;
		std::string password_;
};

#endif