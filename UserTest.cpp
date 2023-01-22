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
}