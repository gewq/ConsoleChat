#include "PasswordCorrect.h"
#include <iostream>

PasswordCorrect::PasswordCorrect() : State("PasswordCorrect")
{
};



void PasswordCorrect::handle(Chat* chat)
{
    std::cout << "Придумайте Ник: ";
    std::string name;
    std::getline(std::cin >> std::ws, name);

    if (!chat->isCorrectValue(name)) {
        chat->transitionTo(new PasswordCorrect());
    }
    else if (database::isExistName(name)) {
        std::cout << "Пользователь с таким Ником уже зарегистрирован\n";
        chat->transitionTo(new PasswordCorrect());
    }
    else {
        chat->getUser()->setName(name);
        database::addUser(*chat->getUser());
        std::cout << "Вы успешно зарегистрированы!\n"
            << chat->getUser()->getName() << ", добро пожаловать в Чат!\n";
        chat->printMessagesToUser();    //Вывести сообщения пользователю
        chat->transitionTo(new UserInChat());
    }
}