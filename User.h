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

	private:
		std::string name_;
		std::string login_;
		std::string password_;
};

#endif