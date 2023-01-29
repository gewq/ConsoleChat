﻿#include "LoginCorrect.h"
#include <iostream>

LoginCorrect::LoginCorrect() : State("LoginCorrect")
{

};



void LoginCorrect::handle(Chat* chat)
{
    std::cout << "Введите пароль: ";
    std::string password;
    std::cin >> password;

    std::string login = chat->getUser()->getLogin();
    std::string name;

    if (database::isCorrectPassword(login, password)) {
        chat->getUser()->setPassword(password);

        name = database::getNameByLogin(login);

        if (!name.empty()) {
            chat->getUser()->setName(name);
            std::cout << name << ", добро пожаловать в Чат!\n";
            chat->printMessagesToUser();    //Вывести сообщения пользователю
            chat->transitionTo(new UserInChat());
        }
        else {
            std::cout << "Логин отсутствует в базе\n";
            chat->transitionTo(new SignIn());
        }
    }
    else {
        chat->transitionTo(new PasswordIncorrect());
    }
}