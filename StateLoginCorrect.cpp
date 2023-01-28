#include "StateLoginCorrect.h"
#include <iostream>

LoginCorrect::LoginCorrect() : State("LoginCorrect")
{

};



void LoginCorrect::handle(Chat* chat)
{
    std::cout << "Введите пароль: ";
    std::string password;
    std::cin >> password;

    std::string login = chat->currentUser_.getLogin();
    std::string name;

    if (database::isCorrectPassword(login, password) == true) {
        chat->currentUser_.setPassword(password);

        name = database::getNameByLogin(login);

        if (name.length() > 0) {
            chat->currentUser_.setName(name);

            std::cout << name << ", добро пожаловать в Чат!\n";

            //Загрузить сообщения и вывести на экран
            //database::loadMessages(chat->currentUser_, chat->messagesToCurrentUser_);

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