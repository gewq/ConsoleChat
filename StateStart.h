/**
\file UserLogout.h
\brief �����-���������� ��������� "����� �� ���������"
*/

#pragma once

#include "State.h"
#include "Chat.h"

class StateStart : public State {
public:
    StateStart();

    virtual void handle(Chat* chat) override;
};