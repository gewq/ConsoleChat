#include "StateLoginIncorrect.h"
#include <iostream>

LoginIncorrect::LoginIncorrect() : State("LoginIncorrect")
{

};



void LoginIncorrect::handle(Chat* chat)
{
    std::cout << "����� �� ���������������!\n[  1 - ������ ����� ������;  2 - �����������  ]\n";
    char input;
    std::cin >> input;

    //if (input == '1')
    //{
    //    chat->transitionTo(new SignIn());
    //}
    //else
    //{
    //    chat->transitionTo(new Registration());
    //}
}