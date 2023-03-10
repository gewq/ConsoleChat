#include "LoginIncorrect.h"
#include <iostream>

namespace {
    //Возможный выбор пользователя
    enum {
        INPUT_AGAIN = 1,
        REGISTRATION
    };
}



LoginIncorrect::LoginIncorrect() : State("LoginIncorrect")
{
};



void LoginIncorrect::handle(Chat* chat)
{
    std::cout << "| 1 - Ввести Логин заново | 2 - Регистрация | :  ";
    std::string input;
    std::getline(std::cin >> std::ws, input);

    //Введено более одного символа
    if (input.length() > 1) {
        chat->transitionTo(new LoginIncorrect());
    }
    //Введён один символ
    else {
        //Попытка преобразовать символ в число
        try {
            int choice = std::stoi(input);
            handleChoice(chat, choice);
        }
        //Символ не число - вернуться в начало ко вводу
        catch (const std::invalid_argument&) {
            chat->transitionTo(new LoginIncorrect());
        }
    }
}



void LoginIncorrect::handleChoice(Chat* chat, int choice)
{
    switch (choice) {
        case INPUT_AGAIN: {
            chat->transitionTo(new SignIn());
            break;
        }
        case REGISTRATION: {
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