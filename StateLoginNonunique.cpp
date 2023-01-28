#include "StateLoginNonunique.h"
#include <iostream>

LoginNonunique::LoginNonunique() : State("LoginNonunique")
{

};



void LoginNonunique::handle(Chat* chat)
{
    std::cout << "Логин уже зарегистрирован!\n\n| 1 - Войти по этому логину | 2 - Назад к регистрации | :  ";
    char input;
    std::cin >> input;

    switch (input) {
    case '1': {
        chat->transitionTo(new LoginCorrect());
        break;
    }
    case '2': {
        chat->transitionTo(new Registration());
        break;
    }
    default: {
        std::cin.clear();
        chat->transitionTo(new LoginNonunique());
        break;
    }
    }
}