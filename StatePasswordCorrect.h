/**
\file StatePasswordCorrect.h
\brief �����-���������� ��������� "������ ����������"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class PasswordCorrect : public State {
public:
    PasswordCorrect();

    virtual void handle(Chat* chat) override;
};