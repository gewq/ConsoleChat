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
        //////////////////////////////////////////////
        //  Загрузить сообщения и вывести на экран  //
        //////////////////////////////////////////////

        //database::loadMessages(user_temp_)

        chat->transitionTo(new UserInChat());
    }
    else
    {
        chat->transitionTo(new PasswordIncorrect());
    }
}