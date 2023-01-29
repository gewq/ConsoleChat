/**
\file StartState.h
\brief Класс-обработчик состояния "НИКТО НЕ ЗАЛОГИНЕН"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class StartState : public State {
public:
    /**
    Конструктор по-умолчанию
    */
    StartState();

    /**
    Обработчик состояния "НИКТО НЕ ЗАЛОГИНЕН"
    */
    virtual void handle(Chat* chat) override;
};