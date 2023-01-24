#include "StateLoginNonunique.h"
#include <iostream>

LoginNonunique::LoginNonunique() : State("LoginNonunique")
{

};



void LoginNonunique::handle(Chat* chat)
{
    std::cout << "Логин уже зарегистрирован!\n[  1 - Войти по этому логину;  2 - Назад к регистрации  ]\n";
    char input;
    std::cin >> input;

    if (input == '1')
    {
        chat->transitionTo(new LoginCorrect());
    }
    else
    {
        chat->transitionTo(new Registration());
    }
}