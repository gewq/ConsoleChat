/**
\file StateUserInChat.h
\brief Класс-обработчик состояния "ПОЛЬЗОВАТЕЛЬ В ЧАТЕ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class UserInChat : public State {
public:
    UserInChat();

    virtual void handle(Chat* chat) override;
};
