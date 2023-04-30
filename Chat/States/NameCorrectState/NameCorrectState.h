/**
\file NameCorrectState.h
\brief Класс-обработчик состояния "НИК КОРРЕКТНЫЙ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class NameCorrectState : public State {
    public:
        /**
        Конструктор по-умолчанию
        */
        NameCorrectState();

        /**
        Обработчик состояния "ПАРОЛЬ КОРРЕКТНЫЙ"
        */
        virtual void handle(Chat& chat) override;
};