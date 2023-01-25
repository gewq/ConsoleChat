/**
\file StateLoginCorrect.h
\brief Класс-обработчик состояния "ЛОГИН КОРРЕКТНЫЙ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class LoginCorrect : public State {
public:
    LoginCorrect();

    virtual void handle(Chat* chat) override;
};