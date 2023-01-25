#include "StatePasswordCorrect.h"
#include <iostream>

PasswordCorrect::PasswordCorrect() : State("PasswordCorrect")
{

};



void PasswordCorrect::handle(Chat* chat)
{
    std::cout << "Придумайте Ник: ";
    std::string name;
    std::cin >> name;

    if (database::isExistName(name) == true)
    {
        std::cout << "Пользователь с таким Ником уже зарегистрирован\n";
        chat->transitionTo(new PasswordCorrect());
    }
    else
    {
        std::cout << "Уникальный ник\n";

        /////////////////////////////////////////////
        // Загрузить сообщения и вывести на экран  //
        /////////////////////////////////////////////

        chat->transitionTo(new UserInChat());
    }
}