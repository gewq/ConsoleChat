﻿#include "Chat.h"
#include <iostream>
#include <vector>

//Начальная инициализация указателя на статический объект класса
Chat* Chat::instance_ = nullptr;



Chat* Chat::getInstance()
{
    if (instance_ == nullptr) {
        instance_ = new Chat();
    }
    return instance_;
}



void Chat::process()
{
    state_->handle(this);
}



Chat::Chat() : state_(new StartState()), user_(new User) 
{

};



void Chat::transitionTo(State* newState)
{
    delete state_;
    state_ = newState;
}



User* Chat::getUser()
{
    return user_;
}



void Chat::attach(bool* isRun)
{
    isRun_ = isRun;
}



void Chat::exit()
{
    *isRun_ = false;
}



void Chat::printUserList()
{
    //Загрузить список пользователей и вывести на экран
    auto userNames = std::make_shared<std::vector<std::string> >();
    database::loadUserNames(userNames);
    for (auto& name : *userNames) {
        std::cout << name << std::endl;
    }
}



void Chat::printMessagesToUser()
{
    //Загрузить сообщения и вывести на экран
    auto messagesToUser = std::make_shared<std::vector<Message> >();    //Сообщения текущему пользователю
    database::loadMessages(*user_, messagesToUser);                     //Заполнить вектор - сообщениями пользователю
    if (messagesToUser->empty()) {
        std::cout << "Сообщений нет.\n";
    }
    else {
        for (auto& message : *messagesToUser) {
            std::cout << message.getNameFrom() <<
                ": " << message.getText() << std::endl;
        }
    }
}