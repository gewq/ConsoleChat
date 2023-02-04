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

    //Введено более одного символа
    if (input.length() > 1) {
        chat->transitionTo(new PasswordIncorrect());
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
            chat->transitionTo(new PasswordIncorrect());
        }
    }
}



void PasswordIncorrect::handleChoice(Chat* chat, int choice)
{
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