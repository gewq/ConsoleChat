/**
\file StateEnteringRecipient.h
\brief Класс-обработчик состояния "ВВОД АДРЕСАТА"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class EnteringRecipient : public State {
public:
    EnteringRecipient();

    virtual void handle(Chat* chat) override;
};