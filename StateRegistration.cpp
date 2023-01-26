#include "StateRegistration.h"
#include <iostream>

Registration::Registration() : State("Registration")
{

};



void Registration::handle(Chat* chat)
{
    std::cout << "Придумайте логин: ";
    std::string login;
    std::cin >> login;

    if (database::isExistLogin(login) == true)
    {
        chat->transitionTo(new LoginNonunique());
    }
    else
    {
        chat->transitionTo(new LoginUnique());
    }
}