#include "LoginNonunique.h"
#include <iostream>

LoginNonunique::LoginNonunique() : State("LoginNonunique")
{
};



void LoginNonunique::handle(Chat* chat)
{
    std::cout << "| 1 - Войти по этому Логину | 2 - Назад к регистрации | :  ";
    std::string input_str;
    std::getline(std::cin >> std::ws, input_str);

    char input;
    try {
        input = input_str[0];
    }
    catch (std::invalid_argument e) {
        std::cout << "Caught Invalid Argument Exception\n";
        chat->transitionTo(new LoginNonunique());
    }

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