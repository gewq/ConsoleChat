﻿#include "StatePasswordIncorrect.h"
#include <iostream>

PasswordIncorrect::PasswordIncorrect() : State("PasswordIncorrect")
{

};



void PasswordIncorrect::handle(Chat* chat)
{
    std::cout << "Пароль неверный!\n[  1 - Ввести его заново;  2 - Отменить вход  ]\n";
    char input;
    std::cin >> input;

    switch (input)
    {
    case '1':
        chat->transitionTo(new LoginCorrect());
        break;
    case '2':
        chat->transitionTo(new StateStart());
        break;
    default:
        std::cin.clear();
        chat->transitionTo(new PasswordIncorrect());
        break;
    }
}