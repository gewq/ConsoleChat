#include "UserTest.h"

#include <assert.h>

void user_test::test()
{
	//Тест параметризованного конструктора и get-методов
	std::string name = "name";
	std::string login = "login";
	std::string password = "password";

	User user(name, login, password);
	assert(user.getName() == name);
	assert(user.getLogin() == login);
	assert(user.getPassword() == password);

	//Тест set-методов
	std::string new_name = "new_name";
	std::string new_login = "new_login";
	std::string new_password = "new_password";
	user.setName(new_name);
	user.setLogin(new_login);
	user.setPassword(new_password);
	assert(user.getName() == new_name);
	assert(user.getLogin() == new_login);
	assert(user.getPassword() == new_password);

	//Тест пегруженного оператора ==
	User user2(name, login, password);
	User user3(name, login, new_password);
	User user4(new_name, login, new_password);

	assert((user == user2) == false);
	assert((user2 == user3) == true);
	assert((user2 == user4) == true);
}