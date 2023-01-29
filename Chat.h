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
#include "StartState.h"
#include "SignIn.h"
#include "Registration.h"
#include "LoginCorrect.h"
#include "LoginIncorrect.h"
#include "LoginUnique.h"
#include "LoginNonunique.h"
#include "PasswordCorrect.h"
#include "PasswordIncorrect.h"
#include "UserInChat.h"
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
        Перейти в заданное состояние
        \param[in] newState Указатель на объект - новое состояние
        */
        void transitionTo(State* newState);

        /**
        \return Указатель на текущего пользователя чата
        */
        User* getUser();

        /**
        Установить Признак продолжения работы программы
        */
        void attach(bool* isRun);

        /**
        Завершить работу программы
        */
        void exit();

        /**
        Вывод на экран списка имён зарегистрированных пользователей
        */
        void printUserList();

    private:
        /**
        Конструктор private - потому что нельзя создавать объект извне класса
        */
        explicit Chat();

        static Chat* instance_; ///<Указатель на единственный объект класса
        User* user_;            ///<Текущий пользователь чата (чтобы передавать параметры пользователя между состояниями)
        State* state_;          ///<Текущее состояние
        bool* isRun_;           ///<Признак продолжения работы программы
};