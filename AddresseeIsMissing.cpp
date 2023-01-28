#include "AddresseeIsMissing.h"
#include <iostream>

AddresseeIsMissing::AddresseeIsMissing() : State("AddresseeIsMissing")
{

};



void AddresseeIsMissing::handle(Chat* chat)
{
    std::cout << "Пользователь с таким Ником не зарегистрирован.\n\n"
              << "| 1 - Ввести Ник адресата повторно | 2 - Отмена отправки сообщения | :  ";
    char input;
    std::cin >> input;

    switch (input) {
    case '1': {
        chat->transitionTo(new EnteringAddressee());
        break;
    }
    case '2': {
        chat->transitionTo(new UserInChat());
        break;
    }
    default: {
        std::cin.clear();
        chat->transitionTo(new AddresseeIsMissing());
        break;
    }
    }
}