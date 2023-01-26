#include "StateStart.h"
#include <iostream>

StateStart::StateStart() : State("StateStart")
{

};



void StateStart::handle(Chat* chat)
{
    std::cout << "| 1 - Вход в чат | 2 - Регистрация | 3 - Выход из программы | :  ";
    char input;
    std::cin >> input;

    switch (input)
    {
    case '1':
        chat->transitionTo(new SignIn());
        break;
    case '2':
        chat->transitionTo(new Registration());
        break;
    case '3':
        ///////////////////////////////////////////////////
        ///////////     ВЫХОД ИЗ ПРОГРАММЫ       //////////
        ///////////////////////////////////////////////////
        break;
    default:
        std::cin.clear();
        chat->transitionTo(new StateStart());
        break;
    }
}