#include "UserTest.h"

#include <assert.h>

void user_test::test()
{
	std::string name = "name";
	std::string login = "login";
	std::string password = "password";

	User user(name, login, password);
	assert(user.getName() == name);
	assert(user.getLogin() == login);
	assert(user.getPassword() == password);

	std::string new_name = "new_name";
	std::string new_login = "new_login";
	std::string new_password = "new_password";
	user.setName(new_name);
	user.setLogin(new_login);
	user.setPassword(new_password);
	assert(user.getName() == new_name);
	assert(user.getLogin() == new_login);
	assert(user.getPassword() == new_password);
}