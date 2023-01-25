/**
\file StateStart.h
\brief Класс-обработчик состояния "НИКТО НЕ ЗАЛОГИНЕН"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class StateStart : public State {
public:
    StateStart();

    virtual void handle(Chat* chat) override;
};