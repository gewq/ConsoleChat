#include "LoginCorrect.h"
#include <iostream>

LoginCorrect::LoginCorrect() : State("LoginCorrect")
{

};



void LoginCorrect::handle(Chat* chat)
{
    std::cout << "Введите Пароль: ";
    std::string password;
    std::getline(std::cin >> std::ws, password);

    if (!chat->isCorrectValue(password)) {
        chat->transitionTo(new LoginCorrect());
    }
    else {
        std::string login = chat->getUser()->getLogin();

        if (database::isCorrectPassword(login, password)) {
            chat->getUser()->setPassword(password);

            std::string name = database::getNameByLogin(login);
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
}