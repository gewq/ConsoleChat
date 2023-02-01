/**
\file UserInChat.h
\brief Класс-обработчик состояния "ПОЛЬЗОВАТЕЛЬ В ЧАТЕ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class UserInChat : public State {
    public:
        /**
        Конструктор по-умолчанию
        */
        UserInChat();

        /**
        Обработчик состояния "ПОЛЬЗОВАТЕЛЬ В ЧАТЕ"
        */
        virtual void handle(Chat* chat) override;
};
