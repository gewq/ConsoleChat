#include "UserInChat.h"
#include <iostream>

UserInChat::UserInChat() : State("UserInChat")
{
};



void UserInChat::handle(Chat* chat)
{
    std::cout << "| 1 - Отправить сообщение | 2 - Прочитать сообщения | 3 - Список пользователей | 4 - Выход из чата | 5 - Удалить аккаунт | :  ";
    std::string input_str;
    std::getline(std::cin >> std::ws, input_str);

    char input;
    try {
        input = input_str[0];
    }
    catch (std::invalid_argument e) {
        std::cout << "Caught Invalid Argument Exception\n";
        chat->transitionTo(new UserInChat());
    }

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
    case '5': {
        chat->removeAccount();
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