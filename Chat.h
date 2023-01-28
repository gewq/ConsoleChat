/**
\file Chat.h
\brief Класс управляет логикой работы чата

Управляет процессом входа / выхода / регистрации нового пользователя в системе.
Представляет собой конечный автомат - использовать паттерн State.
Объект класса должен быть ОДИН - использовать паттерн Singleton
*/

#pragma once

#include <string>
#include <iostream>
#include "User.h"
#include "Message.h"
//Классы-обработчики состояний
#include "State.h"
#include "StateStart.h"
#include "StateSignIn.h"
#include "StateRegistration.h"
#include "StateLoginCorrect.h"
#include "StateLoginIncorrect.h"
#include "StateLoginUnique.h"
#include "StateLoginNonunique.h"
#include "StatePasswordCorrect.h"
#include "StatePasswordIncorrect.h"
#include "StateUserInChat.h"
#include "StateEnteringAddressee.h"
#include "StateAddresseeIsMissing.h"

class Chat
{
public:
    /**
    Единая точка доступа к единственному объекту класса
    */
    static Chat* getInstance();

    /**
    Объект класса нельзя копировать и перемещать
    */
    Chat(const Chat& other) = delete;
    Chat(Chat&& other) = delete;
    Chat& operator= (const Chat& other) = delete;
    Chat& operator= (Chat&& other) = delete;

    /**
    Запустить процесс
    */
    void process();

    /**
    Перейти в состояние
    \param[in] newState Название состояния
    */
    void transitionTo(State* newState);

    static bool exit_;              ///<Признак завершения работы программы: true -завершить работу 
    User currentUser_{ "", "", "" };///<Экземпляр класса User для прохождения состояний автомата
    //static Message messagesToCurrentUser_;// = std::make_shared<std::vector<Message> >(); ///<Указатель на вектор сообщений пользователю

private:
    /**
    Нельзя создавать объект извне класса
    */
    Chat(State* state);

    State* state_;                  ///<Класс обработчиков состояний
    static Chat* instance_;         ///<Текущее состояние
};