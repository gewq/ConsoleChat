#include "StateLoginCorrect.h"
#include <iostream>

LoginCorrect::LoginCorrect() : State("LoginCorrect")
{

};



void LoginCorrect::handle(Chat* chat)
{
    std::cout << "������� ������: ";
    std::string password;
    std::cin >> password;

    //std::string login;//������!!!!! �������� �������� LOGIN �� ������ � ���� ������
    //if (database::isCorrectPassword(login, password) == true)
    //{
    //    std::cout << "������ ������\n";

    //    // ��������� ��������� � ������� �� �����


    //    chat->transitionTo(new UserInput());
    //}
    //else
    //{
    //    std::cout << "�������� ������\n";
    //    chat->transitionTo(new PasswordIncorrect());
    //}
}