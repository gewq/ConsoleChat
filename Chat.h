/**
\file Chat.h
\brief Класс управляет логикой работы чата

Управляет процессом входа / выхода / регистрации нового пользователя в системе,
отправкой сообщений и т.д.
Логика работы представлена в виде конечного автомата - паттерн State.
Логика определяется текущим состоянием и условиями переходами между ними.
Объект класса должен быть ОДИН - паттерн Singleton
*/

#pragma once

#include <string>
#include <iostream>
#include "User.h"
//Классы-обработчики состояний
#include "State.h"
#include "StateStart.h"
#include "StateSignIn.h"
#include "StateRegistration.h"
#include "LoginCorrect.h"
#include "LoginIncorrect.h"
#include "StateLoginUnique.h"
#include "LoginNonunique.h"
#include "StatePasswordCorrect.h"
#include "StatePasswordIncorrect.h"
#include "StateUserInChat.h"
#include "EnteringAddressee.h"
#include "AddresseeIsMissing.h"

class Chat{
    public:
        /**
        Единая точка доступа к единственному объекту класса
        \return Указатель на объект класса
        */
        static Chat* getInstance();

        //Объект класса нельзя копировать и перемещать
        Chat(const Chat& other) = delete;
        Chat(Chat&& other) = delete;
        Chat& operator= (const Chat& other) = delete;
        Chat& operator= (Chat&& other) = delete;

        /**
        Логика работы чата
        */
        void process();

        /**
        Перейти в новое состояние
        \param[in] newState Указатель на объект - новое состояние
        */
        void transitionTo(State* newState);

        static bool exit_;//выход из программы
        User currentUser_{ "", "", "" };

    private:
        /**
        Конструктор private - потому что нельзя создавать объект извне класса
        */
        explicit Chat(State* state);

        State* state_;          ///<Текущее состояние
        static Chat* instance_; ///<Указатель на единственный объект класса
};