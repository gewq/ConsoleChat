#include "StatePasswordIncorrect.h"
#include <iostream>

PasswordIncorrect::PasswordIncorrect() : State("PasswordIncorrect")
{

};



void PasswordIncorrect::handle(Chat* chat)
{
    std::cout << "������ ��������!\n[  1 - ������ ��� ������;  2 - �������� ����  ]\n";
    char input;
    std::cin >> input;

    if (input == '1')
    {
        chat->transitionTo(new LoginCorrect());
    }
    else
    {
        chat->transitionTo(new StateStart());
    }
}