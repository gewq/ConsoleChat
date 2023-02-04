#include "LoginIncorrect.h"
#include <iostream>

namespace {
    //Возможный выбор пользователя
    enum {
        INPUT_AGAIN = 1,
        REGISTRATION
    };
}



LoginIncorrect::LoginIncorrect() : State("LoginIncorrect")
{
};



void LoginIncorrect::handle(Chat* chat)
{
    std::cout << "| 1 - Ввести Логин заново | 2 - Регистрация | :  ";
    std::string input;
    std::getline(std::cin >> std::ws, input);

    //Попытка преобразовать символ в число
    try {
        int choice = std::stoi(input);
        switch (choice) {
            case INPUT_AGAIN: {
                chat->transitionTo(new SignIn());
                break;
            }
            case REGISTRATION: {
                chat->transitionTo(new Registration());
                break;
            }
            default: {
                std::cin.clear();
                chat->transitionTo(new LoginIncorrect());
                break;
            }
        }
    }
    //Символ не число - вернуться в начало ко вводу
    catch (std::invalid_argument e) {
        chat->transitionTo(new LoginIncorrect());
    }
}