/**
\file StateSignIn.h
\brief �����-���������� ��������� "���� ������������"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class SignIn : public State {
public:
    SignIn();

    virtual void handle(Chat* chat) override;
};