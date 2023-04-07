#include "UserInChat.h"

#include <iostream>
#include <memory>


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

    //Введено более одного символа
    if (input.length() > 1) {
        chat->transitionTo(std::move(std::make_unique<UserInChat>()));
    }
    //Введён один символ
    else {
        //Попытка преобразовать символ в число
        try {
            int choice = std::stoi(input);
            handleChoice(chat, choice);
        }
        //Символ не число - вернуться в начало ко вводу
        catch (const std::invalid_argument&) {
            chat->transitionTo(std::move(std::make_unique<StartState>()));
        }
    }
}



void UserInChat::handleChoice(Chat* chat, int choice)
{
    switch (choice) {
        case SEND_MESSAGE: {
            chat->transitionTo(std::move(std::make_unique<EnteringAddressee>()));
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
            chat->transitionTo(std::move(std::make_unique<StartState>()));
            chat->getUser()->reset();
            break;
        }
        case REMOVE_ACCOUT: {
            chat->removeAccount();
            chat->transitionTo(std::move(std::make_unique<StartState>()));
            break;
        }
        default: {
            std::cin.clear();
            chat->transitionTo(std::move(std::make_unique<UserInChat>()));
            break;
        }
    }
}