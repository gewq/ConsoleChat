/**
\file PasswordIncorrect.h
\brief Класс-обработчик состояния "ПАРОЛЬ НЕВЕРНЫЙ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class PasswordIncorrect : public State {
    public:
        /**
        Конструктор по-умолчанию
        */
        PasswordIncorrect();

        /**
        Обработчик состояния "ПАРОЛЬ НЕВЕРНЫЙ"
        */
        virtual void handle(Chat* chat) override;
};