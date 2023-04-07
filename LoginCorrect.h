/**
\file LoginCorrect.h
\brief Класс-обработчик состояния "ЛОГИН КОРРЕКТНЫЙ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class LoginCorrect : public State {
    public:
        /**
        Конструктор по-умолчанию
        */
        LoginCorrect();

        /**
        Обработчик состояния "ЛОГИН КОРРЕКТНЫЙ"
        */
        virtual void handle(Chat& chat) override;
};