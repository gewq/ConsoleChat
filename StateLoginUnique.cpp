#include "StateLoginUnique.h"
#include <iostream>

LoginUnique::LoginUnique() : State("LoginUnique")
{

};



void LoginUnique::handle(Chat* chat)
{
    std::cout << "Придумайте пароль: ";
    std::string password;
    std::cin >> password;

    //std::string login;//УБРАТЬ!!!!! ТЕКУЩЕЕЕ ЗНАЧЕНИЕ LOGIN ДО ЗАПИСИ В БАЗУ ДАННЫХ
    //if (database::isCorrectPassword(login, password) == true)
    //{
    //    std::cout << "Пароль корректный\n";
    //    chat->transitionTo(new PasswordCorrect());
    //}
    //else
    //{
    //    std::cout << "Недопустимый пароль (пустой)\n";
    //    chat->transitionTo(new LoginUnique());
    //}
}