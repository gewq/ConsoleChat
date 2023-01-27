#include "StateLoginIncorrect.h"
#include <iostream>

LoginIncorrect::LoginIncorrect() : State("LoginIncorrect")
{

};



void LoginIncorrect::handle(Chat* chat)
{
    std::cout << "Логин не зарегистрирован!\n| 1 - Ввести логин заново | 2 - Регистрация | :  ";
    char input;
    std::cin >> input;

    switch (input) {
        case '1': {
            chat->transitionTo(new SignIn());
            break;
        }        
        case '2': {
            chat->transitionTo(new Registration());
            break;
        }
        default: {
            std::cin.clear();
            chat->transitionTo(new LoginIncorrect());
            break;
        }
    }
}