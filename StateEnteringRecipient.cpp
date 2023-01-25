#include "StateEnteringRecipient.h"
#include <iostream>

EnteringRecipient::EnteringRecipient() : State("EnteringRecipient")
{

};



void EnteringRecipient::handle(Chat* chat)
{
    std::cout << "Введите Ник адресата (all - отправить всем): ";
    std::string name;
    std::cin >> name;///////////////////////////////////////////

    if (database::isExistName(name) == true)
    {
        // Отправить сообщение//////////////////////////////////




    }
    else
    {
        std::cout << "Ника нет в базе\n";
        //chat->transitionTo(new RecipientIsMissing());
    }
}