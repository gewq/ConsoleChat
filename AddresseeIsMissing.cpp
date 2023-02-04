#include "AddresseeIsMissing.h"
#include <iostream>

namespace {
    //Возможный выбор пользователя
    enum {
        INPUT_AGAIN = 1,
        CANCEL
    };
}



AddresseeIsMissing::AddresseeIsMissing() : State("AddresseeIsMissing")
{
};



void AddresseeIsMissing::handle(Chat* chat)
{
    std::cout << "| 1 - Ввести Ник адресата повторно | 2 - Отменить отправку сообщения | :  ";
    std::string input;
    std::getline(std::cin >> std::ws, input);

    //Введено более одного символа
    if (input.length() > 1) {
        chat->transitionTo(new AddresseeIsMissing());
    }
    //Введён один символ
    else {
        try {
            int choice = std::stoi(input);
            handleChoice(chat, choice);
        }
        catch (const std::invalid_argument&) {
            chat->transitionTo(new AddresseeIsMissing());
        }
    }
}



void AddresseeIsMissing::handleChoice(Chat* chat, int choice)
{
    switch (choice) {
        case INPUT_AGAIN: {
            chat->transitionTo(new EnteringAddressee());
            break;
        }
        case CANCEL: {
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