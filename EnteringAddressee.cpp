#include "EnteringAddressee.h"
#include <iostream>

EnteringAddressee::EnteringAddressee() : State("EnteringAddressee")
{
};



void EnteringAddressee::handle(Chat* chat)
{
    std::cout << "Введите Ник адресата (all - отправить всем): ";
    std::string nameAdressee;
    std::getline(std::cin >> std::ws, nameAdressee);

    //Зарегистрирован только один пользователь
    if (database::getNumberUser() == 1) {
        std::cout << "Вы единственный пользователь чата\n";
        chat->transitionTo(new UserInChat());
    }

    //Неверное имя адресата
    else if ((nameAdressee != "all") && (!database::isExistName(nameAdressee))) {

        chat->transitionTo(new AddresseeIsMissing());
    }

    //Адресат корректный
    else {
        std::cout << "Введите сообщение: ";
        std::string textMessage;
        std::getline(std::cin >> std::ws, textMessage);

        //Текст введён
        if (!textMessage.empty()) {
            //Создать сообщение
            Message message(chat->getUser()->getName(), nameAdressee, textMessage);
            //Поместить в базу сообщений
            database::pushMessage(message);
            std::cout << "Сообщение отправлено\n";
        }

        //Текст не введён
        else {
            std::cout << "Сообщение не отправлено (отсутствует текст сообщения)\n";
        }
        chat->transitionTo(new UserInChat());
    }
}