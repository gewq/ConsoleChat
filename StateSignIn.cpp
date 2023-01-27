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

    if (database::isExistLogin(login) == true) {
        chat->currentUser_.setLogin(login);
        chat->transitionTo(new LoginCorrect());
    }
    else {
        chat->transitionTo(new LoginIncorrect());
    }
}