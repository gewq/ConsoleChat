#include "PasswordIncorrect.h"
#include <iostream>

PasswordIncorrect::PasswordIncorrect() : State("PasswordIncorrect")
{
};



void PasswordIncorrect::handle(Chat* chat)
{
    std::cout << "| 1 - Ввести пароль заново | 2 - Отменить вход | :  ";
    std::string input_str;
    std::getline(std::cin >> std::ws, input_str);

    char input;
    try {
        input = input_str[0];
    }
    catch (std::invalid_argument e) {
        std::cout << "Caught Invalid Argument Exception\n";
        chat->transitionTo(new PasswordIncorrect());
    }

    switch (input) {
        case '1': {
            chat->transitionTo(new LoginCorrect());
            break;
        }
        case '2': {
            chat->transitionTo(new StartState());
            break;
        }
        default: {
            std::cin.clear();
            chat->transitionTo(new PasswordIncorrect());
            break;
        }
    }
}