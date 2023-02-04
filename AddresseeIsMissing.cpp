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

    try {
        int choice = std::stoi(input);
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
    catch (std::invalid_argument e) {
        chat->transitionTo(new AddresseeIsMissing());
    }
}