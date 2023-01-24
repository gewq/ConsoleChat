#include "StateLoginNonunique.h"
#include <iostream>

LoginNonunique::LoginNonunique() : State("LoginNonunique")
{

};



void LoginNonunique::handle(Chat* chat)
{
    std::cout << "����� ��� ���������������!\n[  1 - ����� �� ����� ������;  2 - ����� � �����������  ]\n";
    char input;
    std::cin >> input;

    if (input == '1')
    {
        chat->transitionTo(new LoginCorrect());
    }
    else
    {
        chat->transitionTo(new Registration());
    }
}