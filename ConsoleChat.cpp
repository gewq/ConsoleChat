#include <iostream>

#include "DataBase.h"
#include "UserTest.h"
#include "Chat.h"

int main()
{
	setlocale(LC_ALL, "");
	try {
		user_test::test();
		database::test();

		database::initialize();

		while (true) {
			Chat::getInstance()->process();
		}
	}
	catch (std::bad_alloc& error) {
		std::cerr << "Ошибка выделения памяти: " << error.what() << std::endl;
	}
	catch (std::exception& error) {
		std::cerr << error.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Неопределённое исключение" << std::endl;
	}
	return EXIT_SUCCESS;
}