#include "LoginUnique.h"

#include <iostream>
#include <memory>

#include "sha1.hpp"



LoginUnique::LoginUnique() : State("LoginUnique")
{
};



void LoginUnique::handle(Chat& chat)
{
    std::cout << "Придумайте Пароль: ";
    std::string password;
    std::getline(std::cin >> std::ws, password);

    //Допустимые символы
    if (chat.isCorrectValue(password)) {
        //Вычислить Хэш пароля
        auto checksum = std::make_unique<SHA1>();
        checksum->update(password);
        const std::string hash = checksum->final();

        chat.getUser()->setHashPassword(hash);
        chat.transitionTo(std::move(std::make_unique<PasswordCorrect>()));
    }

    //Недопустимые символы
    else {
        std::cout << "Некорректные символы.\n";
        std::cin.clear();
        chat.transitionTo(std::move(std::make_unique<PasswordCorrect>()));
    }
}