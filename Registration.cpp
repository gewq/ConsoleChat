#include "Registration.h"
#include <iostream>

Registration::Registration() : State("Registration")
{

};



void Registration::handle(Chat* chat)
{
    std::cout << "Придумайте логин: ";
    std::string login;
    std::cin >> login;

    chat->getUser()->setLogin(login);

    if (database::isExistLogin(login)) {
        chat->transitionTo(new LoginNonunique());
    }
    else {
        chat->transitionTo(new LoginUnique());
    }
}