#include "StateLoginUnique.h"
#include <iostream>

LoginUnique::LoginUnique() : State("LoginUnique")
{

};



void LoginUnique::handle(Chat* chat)
{
    std::cout << "���������� ������: ";
    std::string password;
    std::cin >> password;

    //std::string login;//������!!!!! �������� �������� LOGIN �� ������ � ���� ������
    //if (database::isCorrectPassword(login, password) == true)
    //{
    //    std::cout << "������ ����������\n";
    //    chat->transitionTo(new PasswordCorrect());
    //}
    //else
    //{
    //    std::cout << "������������ ������ (������)\n";
    //    chat->transitionTo(new LoginUnique());
    //}
}