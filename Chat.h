/**
\file Chat.h
\brief Класс управляет логикой работы чата

Управляет процессом входа / выхода / регистрации нового пользователя в системе.
Представляет собой конечный автомат - использовать паттерн State.
Объект класса должен быть ОДИН - использовать паттерн Singleton
*/

#pragma once

#include <string>
#include "User.h"
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
    //Единая точка доступа к единственному объекту класса
    static Chat* getInstance();
    //Объект класса нельзя копировать и перемещать
    Chat(const Chat& other) = delete;
    Chat(Chat&& other) = delete;
    Chat& operator= (const Chat& other) = delete;
    Chat& operator= (Chat&& other) = delete;

    void process();
    void transitionTo(State* newState);

    static bool exit_;//выход из программы
    User currentUser_{ "", "", "" };

private:
    //Нельзя создавать объект извне класса
    explicit Chat(State* state);

    State* state_;
    static Chat* instance_;
};