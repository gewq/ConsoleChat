#include "StateLoginUnique.h"
#include <iostream>

LoginUnique::LoginUnique() : State("LoginUnique")
{

};



void LoginUnique::handle(Chat* chat)
{
    std::cout << "Придумайте пароль: ";
    std::string password;
    std::cin >> password;

    std::string login = "q";//УБРАТЬ!!!!! ТЕКУЩЕЕЕ ЗНАЧЕНИЕ LOGIN ДО ЗАПИСИ В БАЗУ ДАННЫХ
    if (password.length() > 0)
    {
        chat->transitionTo(new PasswordCorrect());
    }
    else
    {
        std::cout << "Недопустимый пароль (пустой)\n";
        chat->transitionTo(new LoginUnique());
    }
}