#include "NameCorrectState.h"

#include <iostream>
#include <memory>


NameCorrectState::NameCorrectState() : State("NameCorrectState")
{
};



void NameCorrectState::handle(Chat& chat)
{
    std::cout << "Придумайте Пароль: ";
    std::string password;
    std::getline(std::cin >> std::ws, password);

    //Допустимые символы
    if (chat.isCorrectValue(password)) {
        database::addUser(chat.getUser()->getName(),
            chat.getUser()->getLogin(),
            password);

        std::cout << "Вы успешно зарегистрированы!\n"
            << chat.getUser()->getName() << ", добро пожаловать в Чат!\n";
        chat.transitionTo(std::move(std::make_unique<UserInChat>()));
    }

    //Недопустимые символы
    else {
        std::cout << "Некорректные символы.\n";
        std::cin.clear();
        chat.transitionTo(std::move(std::make_unique<NameCorrectState>()));
    }
}