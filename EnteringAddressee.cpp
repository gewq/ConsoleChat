#include "EnteringAddressee.h"
#include <iostream>

EnteringAddressee::EnteringAddressee() : State("EnteringAddressee")
{

};



void EnteringAddressee::handle(Chat* chat)
{
    std::cout << "Введите Ник адресата (all - отправить всем): ";
    std::string name;
    std::cin >> name;
		
	//Проверить наличие других пользователей чата
    if (database::getNumberUser() == 1) {
        std::cout << "Вы единственный пользователь чата\n";
        chat->transitionTo(new UserInChat());
    }
    else if ((name != "all") && (database::isExistName(name) != true)) {
        chat->transitionTo(new AddresseeIsMissing());
    }
    else {
        std::cout << "Введите сообщение: ";
        std::string text;
        std::cin >> text;
        if (!text.empty()) {
            // Отправить сообщение
            Message message(chat->getUser()->getName(), name, text);  //Создать сообщение
            database::pushMessage(message);				                //Поместить в базу сообщений

            std::cout << "Сообщение отправлено\n";
        }
        else {
            std::cout << "Сообщение не было отправлено (отсутствует текст сообщения)\n";
        }

        chat->transitionTo(new UserInChat());
    }
}