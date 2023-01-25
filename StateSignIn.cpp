#include "StateSignIn.h"
#include <iostream>

SignIn::SignIn() : State("SignIn")
{

};



void SignIn::handle(Chat* chat)
{
    std::cout << "Введите Ваш логин: ";
    std::string login;
    std::cin >> login;
    //user_tmp.setLogin(login);

    //if (database::isExistLogin(login) == true)
    //{
    //    std::cout << "Логин есть в базе\n";
    //    chat->transitionTo(new LoginCorrect());
    //}
    //else
    //{
    //    std::cout << "Логин некорректный\n";
    //    chat->transitionTo(new LoginIncorrect());
    //}
}