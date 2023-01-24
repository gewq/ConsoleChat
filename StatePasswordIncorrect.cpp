#include "StatePasswordIncorrect.h"
#include <iostream>

PasswordIncorrect::PasswordIncorrect() : State("PasswordIncorrect")
{

};



void PasswordIncorrect::handle(Chat* chat)
{
    std::cout << "Пароль неверный!\n[  1 - Ввести его заново;  2 - Отменить вход  ]\n";
    char input;
    std::cin >> input;

    if (input == '1')
    {
        chat->transitionTo(new LoginCorrect());
    }
    else
    {
        chat->transitionTo(new StateStart());
    }
}