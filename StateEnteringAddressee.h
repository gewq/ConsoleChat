/**
\file StateEnteringAddressee.h
\brief Класс-обработчик состояния "ВВОД АДРЕСАТА"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class EnteringAddressee : public State {
public:
    EnteringAddressee();

    virtual void handle(Chat* chat) override;
};