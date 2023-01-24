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

    //if (database::isExistLogin(login) == true)
    //{
    //    std::cout << "Логин уже есть в базе\n";
    //    chat->transitionTo(new LoginNonunique());
    //}
    //else
    //{
    //    std::cout << "Логина нет в базе\n";
    //    chat->transitionTo(new LoginUnique());
    //}
}