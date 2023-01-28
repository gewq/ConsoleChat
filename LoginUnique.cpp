#include "LoginUnique.h"
#include <iostream>

LoginUnique::LoginUnique() : State("LoginUnique")
{

};



void LoginUnique::handle(Chat* chat)
{
    std::cout << "Придумайте пароль: ";
    std::string password;
    std::cin >> password;

    if (password.length() > 0) {
        chat->currentUser_.setPassword(password);
        chat->transitionTo(new PasswordCorrect());
    }
    else {
        std::cout << "Недопустимый пароль (пустой)\n";
        chat->transitionTo(new LoginUnique());
    }
}