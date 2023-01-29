#include "StartState.h"
#include <iostream>

StartState::StartState() : State("StartState")
{

};



void StartState::handle(Chat* chat)
{
    chat->currentUser_.setLogin("");
    chat->currentUser_.setPassword("");
    chat->currentUser_.setName("");

    std::cout << "\n| 1 - Вход в чат | 2 - Регистрация | 3 - Выход из программы | :  ";
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
    case '3': {
        std::cout << "Завершение работы";
        chat->exit_ = true;
        break;
    }
    default: {
        std::cin.clear();
        chat->transitionTo(new StartState());
        break;
    }
    }
}