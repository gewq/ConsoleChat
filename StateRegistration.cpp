#include "StateRegistration.h"
#include <iostream>

Registration::Registration() : State("Registration")
{

};



void Registration::handle(Chat* chat)
{
    std::cout << "���������� �����: ";
    std::string login;
    std::cin >> login;

    //if (database::isExistLogin(login) == true)
    //{
    //    std::cout << "����� ��� ���� � ����\n";
    //    chat->transitionTo(new LoginNonunique());
    //}
    //else
    //{
    //    std::cout << "������ ��� � ����\n";
    //    chat->transitionTo(new LoginUnique());
    //}
}