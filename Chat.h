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
//#include "LoginUnique.h"
//#include "LoginNonunique.h"
//#include "PasswordCorrect.h"
//#include "PasswordIncorrect.h"
//#include "UserInput.h"

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

private:
    //Нельзя создавать объект извне класса
    Chat(State* state);

    State* state_;
    static Chat* instance_;
    //User* userTemp_;
};