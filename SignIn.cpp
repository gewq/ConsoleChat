#include "SignIn.h"
#include <iostream>

SignIn::SignIn() : State("SignIn")
{

};



void SignIn::handle(Chat* chat)
{
    std::cout << "Введите Ваш Логин: ";
    std::string login;
    std::getline(std::cin >> std::ws, login);

    if (!chat->isCorrectValue(login)) {
        chat->transitionTo(new SignIn());
    }
    else if (database::isExistLogin(login)) {
        chat->getUser()->setLogin(login);
        chat->transitionTo(new LoginCorrect());
    }
    else {
        chat->transitionTo(new LoginIncorrect());
    }
}