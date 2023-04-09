#include "User.h"

#include <assert.h>


User::User() : name_(""), login_(""), hashPassword_("")
{
}



User::User(const std::string& name,
	const std::string& login,
	const std::string& hashPassword) :
	name_(name), login_(login), hashPassword_(hashPassword)
{
}



bool User::operator==(User other) const
{
	//Объекты равны если совпадает Логин
	if (login_ == other.login_) {
		return true;
	}
	return false;
}



std::string User::getName() const
{
	return name_;
}



std::string User::getLogin() const
{
	return login_;
}



std::string User::getHashPassword() const
{
	return hashPassword_;
}



void User::setName(const std::string& name)
{
	name_ = name;
}



void User::setLogin(const std::string& login)
{
	login_ = login;
}



void User::setHashPassword(const std::string& hashPassword)
{
	hashPassword_ = hashPassword;
}



void User::reset()
{
	name_.clear();
	login_.clear();
	hashPassword_.clear();
}



void user::test()
{
	//Тест конструктора по-умолчанию и get-методов
	User user1;
	assert(user1.getName() == "");
	assert(user1.getLogin() == "");
	assert(user1.getHashPassword() == "");

	//Тест параметризованного конструктора и get-методов
	std::string name = "name";
	std::string login = "login";
	std::string hashPassword = "5baa61e4c9b93f3f0682250b6cf8331b7ee68fd8";

	User user(name, login, hashPassword);
	assert(user.getName() == name);
	assert(user.getLogin() == login);
	assert(user.getHashPassword() == hashPassword);

	//Тест set-методов
	std::string new_name = "new_name";
	std::string new_login = "new_login";
	std::string new_password = "f054ffc85b4c1615a7190ea0b248564bb1e9f9ab";
	user.setName(new_name);
	user.setLogin(new_login);
	user.setHashPassword(new_password);
	assert(user.getName() == new_name);
	assert(user.getLogin() == new_login);
	assert(user.getHashPassword() == new_password);

	//Тест пегруженного оператора ==
	User user2(name, login, hashPassword);
	User user3(name, login, new_password);
	User user4(new_name, login, new_password);

	assert((user == user2) == false);
	assert((user2 == user3) == true);
	assert((user2 == user4) == true);

	//Tecт reset()
	user.reset();
	assert(user.getName() == "");
	assert(user.getLogin() == "");
	assert(user.getHashPassword() == "");
}