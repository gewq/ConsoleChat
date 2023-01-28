#include <iostream>

#include "DataBase.h"
#include "UserTest.h"
#include "Chat.h"

/**
��������� ����� ������� ���������
*/
static void test();

int main()
{
	setlocale(LC_ALL, "");
	try {
		//test();
		database::initialize();

		while (Chat::exit_ != true) {
			Chat::getInstance()->process();
		}
	}
	catch (std::bad_alloc& error) {
		std::cerr << "������ ��������� ������: " << error.what() << std::endl;
	}
	catch (std::exception& error) {
		std::cerr << error.what() << std::endl;
	}
	catch (...) {
		std::cerr << "������������� ����������" << std::endl;
	}
	return EXIT_SUCCESS;
}



static void test()
{
	user_test::test();
	database::test();
}