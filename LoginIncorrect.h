/**
\file LoginIncorrect.h
\brief Класс-обработчик состояния "ЛОГИН НЕКОРРЕКТНЫЙ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class LoginIncorrect : public State {
    public:
        /**
        Конструктор по-умолчанию
        */
        LoginIncorrect();

        /**
        Обработчик состояния "ЛОГИН НЕКОРРЕКТНЫЙ"
        */
        virtual void handle(Chat* chat) override;
};