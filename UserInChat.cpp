#include "UserInChat.h"
#include <iostream>

UserInChat::UserInChat() : State("UserInChat")
{

};



void UserInChat::handle(Chat* chat)
{
    std::cout << "\n| 1 - Отправить сообщение | 2 - Прочитать сообщения | 3 - Выход из чата | :  ";
    char input;
    std::cin >> input;

    switch (input) {
    case '1': {
        chat->transitionTo(new EnteringAddressee());
        break;
    }
    case '2': {
        //Загрузить сообщения и вывести на экран
        auto messagesToUser = std::make_shared<std::vector<Message> >(); //Указатель на вектор сообщений конкретному пользователю
        database::loadMessages(chat->currentUser_, messagesToUser);	     //Заполнить вектор сообщениями адресату

        chat->transitionTo(new UserInChat());
        break;
    }
    case '3': {
        chat->transitionTo(new StartState());
        break;
    }
    default: {
        std::cin.clear();
        chat->transitionTo(new UserInChat());
        break;
    }
    }
}