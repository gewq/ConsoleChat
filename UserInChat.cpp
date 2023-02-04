#include "UserInChat.h"
#include <iostream>

namespace {
    //Возможный выбор пользователя
    enum {
        SEND_MESSAGE = 1,
        READ_MESSAGE,
        SHOW_USERS,
        EXIT,
        REMOVE_ACCOUT
    };
}



UserInChat::UserInChat() : State("UserInChat")
{
};



void UserInChat::handle(Chat* chat)
{
    std::cout << "| 1 - Отправить сообщение | 2 - Прочитать сообщения | 3 - Список пользователей | 4 - Выход из чата | 5 - Удалить аккаунт | :  ";
    std::string input;
    std::getline(std::cin >> std::ws, input);

    //Попытка преобразовать символ в число
    try {
        int choice = std::stoi(input);
        switch (choice) {
            case SEND_MESSAGE: {
                chat->transitionTo(new EnteringAddressee());
                break;
            }
            case READ_MESSAGE: {
                chat->printMessagesToUser();
                break;
            }
            case SHOW_USERS: {
                chat->printUserList();
                break;
            }
            case EXIT: {
                chat->transitionTo(new StartState());
                chat->getUser()->reset();
                break;
            }
            case REMOVE_ACCOUT: {
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
    //Символ не число - вернуться в начало ко вводу
    catch (const std::invalid_argument&) {
        chat->transitionTo(new StartState());
    }
}