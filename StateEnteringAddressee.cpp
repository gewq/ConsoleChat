#include "StateEnteringAddressee.h"
#include <iostream>

EnteringAddressee::EnteringAddressee() : State("EnteringAddressee")
{

};



void EnteringAddressee::handle(Chat* chat)
{
    std::cout << "Введите Ник адресата (all - отправить всем): ";
    std::string name;
    std::cin >> name;///////////////////////////////////////////

    if (database::isExistName(name) == true)
    {
        // Отправить сообщение//////////////////////////////////
        //const std::string nameFrom = "nameFrom";
        //const std::string nameTo = "nameTo";
        //const std::string text = "Hello nameTo!";
        //Message message(nameFrom, nameTo, text);	//Создать сообщение
        //database::putMessage(message);				//Поместить в базу сообщений



    }
    else
    {
        chat->transitionTo(new AddresseeIsMissing());
    }
}