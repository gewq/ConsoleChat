#include "StateSignIn.h"
#include <iostream>


SignIn::SignIn() : State("SignIn")
{
};

void SignIn::handle(Chat* chat)
{
    std::cout << "������� ��� �����: ";
    std::string login;
    std::cin >> login;
    //user_tmp.setLogin(login);

    //if (database::isExistLogin(login) == true)
    //{
    //    std::cout << "����� ���� � ����\n";
    //    chat->transitionTo(new LoginCorrect());
    //}
    //else
    //{
    //    std::cout << "����� ������������\n";
    //    chat->transitionTo(new LoginIncorrect());
    //}
}