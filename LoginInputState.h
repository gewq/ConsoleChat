/**
\file SignIn.h
\brief Класс-обработчик состояния "ВХОД ПОЛЬЗОВАТЕЛЯ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class LoginInputState : public State {
    public:
        /**
        Конструктор по-умолчанию
        */
        LoginInputState();

        /**
        Обработчик состояния "ВХОД ПОЛЬЗОВАТЕЛЯ"
        */
        virtual void handle(Chat& chat) override;
};