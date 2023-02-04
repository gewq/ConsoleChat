#include "PasswordIncorrect.h"
#include <iostream>

namespace {
    //Возможный выбор пользователя
    enum {
        INPUT_AGAIN = 1,
        TO_MAIN_MENU
    };
}



PasswordIncorrect::PasswordIncorrect() : State("PasswordIncorrect")
{
};



void PasswordIncorrect::handle(Chat* chat)
{
    std::cout << "| 1 - Ввести пароль заново | 2 - Отменить вход | :  ";
    std::string input;
    std::getline(std::cin >> std::ws, input);

    //Попытка преобразовать символ в число
    try {
        int choice = std::stoi(input);
        switch (choice) {
            case INPUT_AGAIN: {
                chat->transitionTo(new LoginCorrect());
                break;
            }
            case TO_MAIN_MENU: {
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
    //Символ не число - вернуться в начало ко вводу
    catch (std::invalid_argument e) {
        chat->transitionTo(new PasswordIncorrect());
    }
}