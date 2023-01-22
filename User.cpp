#include "User.h"

User::User(std::string name, std::string login, std::string password):
	name_(name), login_(login), password_(password)
{
}

std::string User::getName() const
{
	return name_;
}

std::string User::getLogin() const
{
	return login_;
}

std::string User::getPassword() const
{
	return password_;
}
