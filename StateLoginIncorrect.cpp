#include "StateLoginIncorrect.h"
#include <iostream>

LoginIncorrect::LoginIncorrect() : State("LoginIncorrect")
{

};



void LoginIncorrect::handle(Chat* chat)
{
    std::cout << "Логин не зарегистрирован!\n[  1 - Ввести логин заново;  2 - Регистрация  ]\n";
    char input;
    std::cin >> input;

    //if (input == '1')
    //{
    //    chat->transitionTo(new SignIn());
    //}
    //else
    //{
    //    chat->transitionTo(new Registration());
    //}
}