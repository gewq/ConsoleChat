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

    /*userTemp_.*/

    if (database::isExistLogin(login) == true)
    {
        chat->transitionTo(new LoginCorrect());
    }
    else
    {
        chat->transitionTo(new LoginIncorrect());
    }
}