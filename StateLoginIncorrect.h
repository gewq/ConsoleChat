/**
\file StateLoginIncorrect.h
\brief �����-���������� ��������� "����� ������������"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class LoginIncorrect : public State {
public:
    LoginIncorrect();

    virtual void handle(Chat* chat) override;
};