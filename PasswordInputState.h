/**
\file PasswordInputState.h
\brief Класс-обработчик состояния "ЛОГИН КОРРЕКТНЫЙ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class PasswordInputState : public State {
    public:
        /**
        Конструктор по-умолчанию
        */
        PasswordInputState();

        /**
        Обработчик состояния "ЛОГИН КОРРЕКТНЫЙ"
        */
        virtual void handle(Chat& chat) override;
};