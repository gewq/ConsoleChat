/**
\file StateLoginUnique.h
\brief �����-���������� ��������� "����� ����������"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class LoginUnique : public State {
public:
    LoginUnique();

    virtual void handle(Chat* chat) override;
};