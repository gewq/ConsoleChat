#include "Chat.h"
#include <iostream>
#include <vector>

bool Chat::exit_ = false;
//Message Chat::messagesToCurrentUser_ = std::make_shared<std::vector<Message> >();

//Начальная инициализация указателя на статический объект класса
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