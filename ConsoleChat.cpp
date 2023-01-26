#include <iostream>

#include "DataBase.h"
#include "UserTest.h"
#include "Chat.h"

int main()
{
    user_test::test();
    database::test();

    database::initialize();

    setlocale(LC_ALL, "");

    while (true) {
        Chat::getInstance()->process();
    }
}