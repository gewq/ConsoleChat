#include "StateLoginCorrect.h"
#include <iostream>

LoginCorrect::LoginCorrect() : State("LoginCorrect")
{

};



void LoginCorrect::handle(Chat* chat)
{
    std::cout << "Введите пароль: ";
    std::string password;
    std::cin >> password;

    std::string login;//УБРАТЬ!!!!! ТЕКУЩЕЕЕ ЗНАЧЕНИЕ LOGIN ДО ЗАПИСИ В БАЗУ ДАННЫХ
    if (database::isCorrectPassword(login, password) == true)
    {
        std::cout << "Верный пароль\n";

        //////////////////////////////////////////////
        //  Загрузить сообщения и вывести на экран  //
        //////////////////////////////////////////////

        chat->transitionTo(new UserInChat());
    }
    else
    {
        std::cout << "Неверный пароль\n";
        chat->transitionTo(new PasswordIncorrect());
    }
}