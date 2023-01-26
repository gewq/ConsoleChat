/**
\file StateRegistration.h
\brief Класс-обработчик состояния "РЕГИСТРАЦИЯ ПОЛЬЗОВАТЕЛЯ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class Registration : public State {
public:
    Registration();

    virtual void handle(Chat* chat) override;
};