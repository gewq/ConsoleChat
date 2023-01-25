#include "StateUserInChat.h"
#include <iostream>

UserInChat::UserInChat() : State("UserInChat")
{

};



void UserInChat::handle(Chat* chat)
{
    std::cout << "[  1 - Отправить сообщение;  2 - Прочитать сообщения;  3 - Выход из чата  ]\n";
    char input;
    std::cin >> input;

    switch (input) {
    case '1':
        //chat->transitionTo(new EnterReceiver());
        break;
    case '2':
        //Загрузить сообщения и вывести на экран
        break;
    case '3':
        chat->transitionTo(new StateStart());
        break;
    default:
        std::cin.clear();
        chat->transitionTo(new UserInChat());
        break;
    }
}