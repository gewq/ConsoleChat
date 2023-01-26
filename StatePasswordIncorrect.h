/**
\file StatePasswordIncorrect.h
\brief Класс-обработчик состояния "ПАРОЛЬ НЕВЕРНЫЙ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class PasswordIncorrect : public State {
public:
    PasswordIncorrect();

    virtual void handle(Chat* chat) override;
};