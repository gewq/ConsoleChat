﻿#include "LoginUnique.h"
#include <iostream>

LoginUnique::LoginUnique() : State("LoginUnique")
{

};



void LoginUnique::handle(Chat* chat)
{
    std::cout << "Придумайте Пароль: ";
    std::string password;
    std::cin >> password;

    if (!password.empty()) {
        chat->getUser()->setPassword(password);
        chat->transitionTo(new PasswordCorrect());
    }
    else {
        std::cout << "Недопустимый Пароль (пустой)\n";
        chat->transitionTo(new LoginUnique());
    }
}