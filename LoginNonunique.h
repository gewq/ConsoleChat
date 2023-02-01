/**
\file LoginNonunique.h
\brief Класс-обработчик состояния "ЛОГИН НЕУНИКАЛЬНЫЙ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class LoginNonunique : public State {
    public:
        /**
        Конструктор по-умолчанию
        */
        LoginNonunique();

        /**
        Обработчик состояния "ЛОГИН НЕУНИКАЛЬНЫЙ"
        */
        virtual void handle(Chat* chat) override;
};