#include "Chat.h"
#include <iostream>


//Начальная инициализация указателя
Chat* Chat::instance_ = nullptr;


Chat* Chat::getInstance()
{
    //if (instance_ == nullptr) {
    //    instance_ = new Chat(new StartState());
    //}
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