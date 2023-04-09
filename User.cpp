#include "User.h"

#include <assert.h>


User::User() : name_(""), login_(""), password_(""), hashPassword_("")
{
}

User::User(const std::string& name,
	const std::string& login,
	const std::string& password,
	const std::string& hashPassword):
	name_(name), login_(login), password_(password), hashPassword_(hashPassword)
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



std::string User::getPassword() const
{
	return password_;
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


void User::setPassword(const std::string& password)
{
	password_ = password;
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
	assert(user1.getPassword() == "");
	assert(user1.getHashPassword() == "");

	//Тест параметризованного конструктора и get-методов
	const std::string name = "name";
	const std::string login = "login";
	const std::string password = "password";
	const std::string hashPassword = "5baa61e4c9b93f3f0682250b6cf8331b7ee68fd8";

	User user(name, login, password, hashPassword);
	assert(user.getName() == name);
	assert(user.getLogin() == login);
	assert(user.getPassword() == password);
	assert(user.getHashPassword() == hashPassword);

	//Тест set-методов
	const std::string new_name = "new_name";
	const std::string new_login = "new_login";
	const std::string new_password = "new_password";
	const std::string new_hashPassword = "5baa61e4c9b93f3f0682250b6cf8331b7ee68fd8";

	user.setName(new_name);
	user.setLogin(new_login);
	user.setPassword(new_password);
	user.setHashPassword(new_hashPassword);
	assert(user.getName() == new_name);
	assert(user.getLogin() == new_login);
	assert(user.getPassword() == new_password);
	assert(user.getHashPassword() == new_hashPassword);

	//Тест пегруженного оператора ==
	User user2(name, login, password, hashPassword);
	User user3(name, login, new_password, new_hashPassword);
	User user4(new_name, login, new_password, new_hashPassword);

	assert((user == user2) == false);
	assert((user2 == user3) == true);
	assert((user2 == user4) == true);

	//Tecт reset()
	user.reset();
	assert(user.getName() == "");
	assert(user.getLogin() == "");
	assert(user1.getPassword() == "");
	assert(user.getHashPassword() == "");
}