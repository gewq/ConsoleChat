/**
\file StateLoginCorrect.h
\brief �����-���������� ��������� "����� ����������"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class LoginCorrect : public State {
public:
    LoginCorrect();

    virtual void handle(Chat* chat) override;
};