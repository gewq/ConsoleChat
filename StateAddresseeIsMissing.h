/**
\file StateAddresseeIsMissing.h
\brief Класс-обработчик состояния "АДРЕСАТ ОТСУТСТВУЕТ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class AddresseeIsMissing : public State {
public:
    AddresseeIsMissing();

    virtual void handle(Chat* chat) override;
};