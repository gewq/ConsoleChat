#include "LoginUnique.h"

#include <iostream>
#include <memory>

#include "SHA_1_Wrapper.h"



LoginUnique::LoginUnique() : State("LoginUnique")
{
};



void LoginUnique::handle(Chat& chat)
{
    std::cout << "Придумайте Ник: ";
    std::string name;
    std::getline(std::cin >> std::ws, name);

    //Допустимые символы
    if (chat.isCorrectValue(name)) {
        //Такой ник уже зарегистрирован
        if (database::isExistName(name)) {
            std::cout << "Пользователь с таким Ником уже зарегистрирован\n";
            chat.transitionTo(std::move(std::make_unique<LoginUnique>()));
        }

        chat.getUser()->setName(name);
        chat.transitionTo(std::move(std::make_unique<NameCorrectState>()));
    }

    //Недопустимые символы
    else {
        std::cout << "Некорректные символы.\n";
        std::cin.clear();
        chat.transitionTo(std::move(std::make_unique<LoginUnique>()));
    }
}