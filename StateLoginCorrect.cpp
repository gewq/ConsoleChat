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
   
    chat->currentUser_.setPassword(password);

    if (database::isCorrectPassword(chat->currentUser_.getLogin(), password) == true) {
        
        
        ////////////////////////database::loadMessages(State::currentUser_, )
        ////////////////////////


        chat->transitionTo(new UserInChat());
    }
    else {
        chat->transitionTo(new PasswordIncorrect());
    }
}