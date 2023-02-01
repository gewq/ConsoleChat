﻿/**
\file EnteringAddressee.h
\brief Класс-обработчик состояния "ВВОД АДРЕСАТА"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class EnteringAddressee : public State {
    public:
        /**
        Конструктор по-умолчанию
        */
        EnteringAddressee();

        /**
        Обработчик состояния "ВВОД АДРЕСАТА"
        */
        virtual void handle(Chat* chat) override;
};