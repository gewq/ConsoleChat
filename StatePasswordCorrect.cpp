#include "StatePasswordCorrect.h"
#include <iostream>

PasswordCorrect::PasswordCorrect() : State("PasswordCorrect")
{

};



void PasswordCorrect::handle(Chat* chat)
{
    std::cout << "���������� ���: ";
    std::string name;
    std::cin >> name;

    //if (database::isExistName(name) == true)
    //{
    //    std::cout << "������������ � ����� ����� ��� ���������������\n";
    //    chat->transitionTo(new PasswordCorrect());
    //}
    //else
    //{
    //    std::cout << "���������� ���\n";

    //    // ��������� ��������� � ������� �� �����




    //    chat->transitionTo(new UserInput());
    //}
}