/**
\file StatePasswordCorrect.h
\brief Класс-обработчик состояния "ПАРОЛЬ КОРРЕКТНЫЙ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class PasswordCorrect : public State {
public:
    /**
    Конструктор по-умолчанию
    */
    PasswordCorrect();

    /**
    Обработчик состояния "ПАРОЛЬ КОРРЕКТНЫЙ"
    */
    virtual void handle(Chat* chat) override;
};