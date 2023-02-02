#include "AddresseeIsMissing.h"
#include <iostream>

AddresseeIsMissing::AddresseeIsMissing() : State("AddresseeIsMissing")
{
};



void AddresseeIsMissing::handle(Chat* chat)
{
    std::cout << "| 1 - Ввести Ник адресата повторно | 2 - Отменить отправку сообщения | :  ";
    std::string input_str;
    std::getline(std::cin >> std::ws, input_str);

    char input;
    try {
        input = input_str[0];
    }
    catch (std::invalid_argument e) {
        std::cout << "Caught Invalid Argument Exception\n";
        chat->transitionTo(new AddresseeIsMissing());
    }

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