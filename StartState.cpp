#include "StartState.h"
#include <iostream>

StartState::StartState() : State("StartState")
{
};



void StartState::handle(Chat* chat)
{
    std::cout << "| 1 - Вход в чат | 2 - Регистрация | 3 - Выход из программы | :  ";
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