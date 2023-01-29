#include "UserInChat.h"
#include <iostream>

UserInChat::UserInChat() : State("UserInChat")
{

};



void UserInChat::handle(Chat* chat)
{
    std::cout << "| 1 - Отправить сообщение | 2 - Список пользователей | 3 - Выход из чата | :  ";
    char input;
    std::cin >> input;

    switch (input) {
        case '1': {
            chat->transitionTo(new EnteringAddressee());
            break;
        }
        case '2': {
            //Загрузить список пользователей и вывести на экран
            auto userNames = std::make_shared<std::vector<std::string> >();
            database::loadUserNames(userNames);
            for (auto& name : *userNames) {
                std::cout << name << std::endl;
            }
            break;
        }
        case '3': {
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