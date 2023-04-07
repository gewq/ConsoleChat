/**
\file AddresseeIsMissing.h
\brief Класс-обработчик состояния "АДРЕСАТ ОТСУТСТВУЕТ"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class AddresseeIsMissing : public State {
    public:
        /**
        Конструктор по-умолчанию
        */
        AddresseeIsMissing();

        /**
        Обработчик состояния "АДРЕСАТ ОТСУТСТВУЕТ"
        */
        virtual void handle(Chat& chat) override;

    private:
        /**
        Обработчик ввода пользователя в зависимости от введённого числа
        \param[in] chat Указатель на объект чата для которого выполнять обработку
        \param[in] choice Число которое ввёл пользователь
        */
        void handleChoice(Chat& chat, int choice);
};