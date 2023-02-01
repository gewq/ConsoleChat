#include "LoginUnique.h"
#include <iostream>

LoginUnique::LoginUnique() : State("LoginUnique")
{
};



void LoginUnique::handle(Chat* chat)
{
    std::cout << "Придумайте Пароль: ";
    std::string password;
    std::getline(std::cin >> std::ws, password);

    if (!chat->isCorrectValue(password)) {
        chat->transitionTo(new LoginUnique());
    }
    else {
        chat->getUser()->setPassword(password);
        chat->transitionTo(new PasswordCorrect());
    }
}