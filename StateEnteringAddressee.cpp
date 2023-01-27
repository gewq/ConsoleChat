﻿#include "StateEnteringAddressee.h"
#include <iostream>

EnteringAddressee::EnteringAddressee() : State("EnteringAddressee")
{

};



void EnteringAddressee::handle(Chat* chat)
{
    std::cout << "Введите Ник адресата (all - отправить всем): ";
    std::string name;
    std::cin >> name;

    if (database::isExistName(name) == true) {
        std::cout << "Сообщение: ";
        std::string text;
        std::cin >> text;

        if (text.length() > 0) {
            // Отправить сообщение
            Message message(chat->currentUser_.getName(), name, text);	//Создать сообщение
            database::putMessage(message);				                //Поместить в базу сообщений

            std::cout << "Сообщение отправлено\n";
        }
        else {
            std::cout << "Сообщение не было отправлено (отсутствует текст сообщения)\n";
        }

        chat->transitionTo(new UserInChat());
    }
    else {
        chat->transitionTo(new AddresseeIsMissing());
    }
}