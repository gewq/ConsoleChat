#include "StartState.h"
#include <iostream>

namespace {
    //Возможный выбор пользователя
    enum {
        SIGN_IN = 1,
        REGISTRATION,
        EXIT
    };
}



StartState::StartState() : State("StartState")
{
};



void StartState::handle(Chat* chat)
{
    std::cout << "| 1 - Вход в чат | 2 - Регистрация | 3 - Выход из программы | :  ";
    std::string input;
    std::getline(std::cin >> std::ws, input);

    //Введено более одного символа
    if (input.length() > 1) {
        chat->transitionTo(new StartState());
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
            chat->transitionTo(new StartState());
        }
    }
}



void StartState::handleChoice(Chat* chat, int choice)
{
    switch (choice) {
        case SIGN_IN: {
            chat->transitionTo(new SignIn());
            break;
        }
        case REGISTRATION: {
            chat->transitionTo(new Registration());
            break;
        }
        case EXIT: {
            std::cout << "Завершение работы";
            chat->exit();
            break;
        }
        default: {
            std::cin.clear();
            chat->transitionTo(new StartState());
            break;
        }
    }
}