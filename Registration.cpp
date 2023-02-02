#include "Registration.h"
#include <iostream>

Registration::Registration() : State("Registration")
{
};



void Registration::handle(Chat* chat)
{
    std::cout << "Придумайте Логин (допустимые символы 'a'-'z', 'A'-'Z', '0'-'9'): ";
    std::string login;
    std::getline(std::cin >> std::ws, login); //Функция ввода ws использует пробелы из входного потока

    //Допустимые символы
    if (chat->isCorrectValue(login)) {
        //Такой логин уже зарегистрирован
        if (database::isExistLogin(login)) {
            std::cout << "Логин уже зарегистрирован!\n";
            chat->transitionTo(new LoginNonunique());
        }
        //Логин уникальный
        else {
            chat->getUser()->setLogin(login);
            chat->transitionTo(new LoginUnique());
        }
    }

    //Недопустимые символы
    else {
        std::cout << "Некорректные символы.\n";
        std::cin.clear();
        chat->transitionTo(new Registration());
    }
}