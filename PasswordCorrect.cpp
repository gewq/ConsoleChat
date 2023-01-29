﻿#include "PasswordCorrect.h"
#include <iostream>

PasswordCorrect::PasswordCorrect() : State("PasswordCorrect")
{

};



void PasswordCorrect::handle(Chat* chat)
{
    std::cout << "Придумайте Ник: ";
    std::string name;
    std::cin >> name;

    if (database::isExistName(name)) {
        std::cout << "Пользователь с таким Ником уже зарегистрирован\n";
        chat->transitionTo(new PasswordCorrect());
    }
    else {
        chat->getUser()->setName(name);
        database::addUser(*chat->getUser());
        std::cout << "Вы успешно зарегистрированы!\n"
            << chat->getUser()->getName() << ", добро пожаловать в Чат!\n";

        //Загрузить сообщения и вывести на экран                
        auto messagesToUser = std::make_shared<std::vector<Message> >(); //Указатель на вектор сообщений конкретному пользователю
        database::loadMessages(*chat->getUser(), messagesToUser);	     //Заполнить вектор сообщениями адресату

        chat->transitionTo(new UserInChat());
    }
}