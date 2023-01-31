#include "Registration.h"
#include <iostream>

Registration::Registration() : State("Registration")
{

};



void Registration::handle(Chat* chat)
{
    std::cout << "Придумайте Логин: ";
    std::string login;
    std::getline(std::cin >> std::ws, login); //функция ввода ws использует пробелы из входного потока

    if (!chat->isCorrectValue(login)) {
        chat->transitionTo(new Registration());
    }
    else {
        chat->getUser()->setLogin(login);

        if (database::isExistLogin(login)) {
            chat->transitionTo(new LoginNonunique());
        }
        else {
            chat->transitionTo(new LoginUnique());
        }
    }
}