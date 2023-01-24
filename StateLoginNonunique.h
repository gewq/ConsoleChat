/**
\file StateLoginNonunique.h
\brief Класс-обработчик состояния "ЛОГИН НЕУНИКАЛЬНЫЙ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class LoginNonunique : public State {
public:
    LoginNonunique();

    virtual void handle(Chat* chat) override;
};