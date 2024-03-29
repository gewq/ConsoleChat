﻿#include "LoginInputState.h"

#include <iostream>
#include <memory>



LoginInputState::LoginInputState() : State("SignIn")
{
};



void LoginInputState::handle(Chat& chat)
{
    std::cout << "Введите Ваш Логин (допустимые символы 'a'-'z', 'A'-'Z', '0'-'9'): ";
    std::string login;
    std::getline(std::cin >> std::ws, login);

    //Допустимые символы
    if (chat.isCorrectValue(login)) {
        //Логин зарегистрирован
        if (database::isExistLogin(login)) {
            chat.getUser()->setLogin(login);
            chat.transitionTo(std::move(std::make_unique<PasswordInputState>()));
        }
        //Логин не зарегистрирован
        else {
            std::cout << "Логин не зарегистрирован!\n";
            chat.transitionTo(std::move(std::make_unique<LoginIncorrect>()));
        }
    }
    //Недопустимые символы
    else {
        std::cout << "Некорректные символы.\n";
        std::cin.clear();
        chat.transitionTo(std::move(std::make_unique<LoginInputState>()));
    }
}