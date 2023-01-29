#include "LoginCorrect.h"
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

    if (database::isCorrectPassword(login, password)) {
        chat->currentUser_.setPassword(password);

        name = database::getNameByLogin(login);

        if (!name.empty()) {
            chat->currentUser_.setName(name);

            std::cout << name << ", добро пожаловать в Чат!\n";

            //Загрузить сообщения и вывести на экран                
            auto messagesToUser = std::make_shared<std::vector<Message> >(); //Указатель на вектор сообщений конкретному пользователю
            database::loadMessages(chat->currentUser_, messagesToUser);	     //Заполнить вектор сообщениями адресату

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