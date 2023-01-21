#include "DataBase.h"

#include <vector>
#include <assert.h>


namespace {
	std::vector<std::string> logins{ "login_1", "login_2" };
}



void database::initialize()
{

}



bool database::isExistLogin(std::string login)
{
	//Итератор - const! Чтобы нельзя было изменить вектор или данные в нём.
	std::vector<std::string>::const_iterator it =
		std::find(logins.begin(), logins.end(), login);	//Для поиска использовать алгоритм STL
	//Элемент не найден
	if (it == logins.end()) {
		return false;
	}
	return true;
}



bool database::isCorrectPassword(std::string login, std::string password)
{
	return false;
}



void database::test()
{
	assert(database::isExistLogin("login_1") == true);
	assert(database::isExistLogin("login_2") == true);
	assert(database::isExistLogin("not_exist") == false);
}