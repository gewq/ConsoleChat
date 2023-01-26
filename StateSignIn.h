/**
\file StateSignIn.h
\brief Класс-обработчик состояния "ВХОД ПОЛЬЗОВАТЕЛЯ"
*/

#pragma once

#include "State.h"
#include "Chat.h"


class SignIn : public State {
public:
    SignIn();

    virtual void handle(Chat* chat) override;
};