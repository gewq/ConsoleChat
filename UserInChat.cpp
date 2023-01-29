#include "UserInChat.h"
#include <iostream>

UserInChat::UserInChat() : State("UserInChat")
{

};



void UserInChat::handle(Chat* chat)
{
    std::cout << "| 1 - Отправить сообщение | 2 - Прочитать сообщения | 3 - Список пользователей | 4 - Выход из чата | :  ";
    char input;
    std::cin >> input;

    switch (input) {
        case '1': {
            chat->transitionTo(new EnteringAddressee());
            break;
        }
        case '2': {
            chat->printMessagesToUser();
            break;
        }
        case '3': {
            chat->printUserList();
            break;
        }
        case '4': {
            chat->transitionTo(new StartState());
            chat->getUser()->reset();
            break;
        }
        default: {
            std::cin.clear();
            chat->transitionTo(new UserInChat());
            break;
        }
    }
}