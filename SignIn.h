/**
\file SignIn.h
\brief Класс-обработчик состояния "ВХОД ПОЛЬЗОВАТЕЛЯ"
*/

#pragma once

#include "State.h"
#include "Chat.h"


class SignIn : public State {
public:
    /**
    Конструктор по-умолчанию
    */
    SignIn();

    /**
    Обработчик состояния "ВХОД ПОЛЬЗОВАТЕЛЯ"
    */
    virtual void handle(Chat* chat) override;
};