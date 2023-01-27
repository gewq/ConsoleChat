#include "Chat.h"
#include <iostream>

//Завершение работы программы
bool Chat::exit_ = false;

//Начальная инициализация указателя
Chat* Chat::instance_ = nullptr;

Chat* Chat::getInstance()
{
    if (instance_ == nullptr) {
        instance_ = new Chat(new StateStart());
    }
    return instance_;
}



void Chat::process()
{
    state_->handle(this);
}



Chat::Chat(State* state) : state_(state)
{

};



void Chat::transitionTo(State* newState)
{
    delete state_;
    state_ = newState;
}