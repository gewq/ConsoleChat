#include "LoginNonunique.h"
#include <iostream>

namespace {
    //Возможный выбор пользователя
    enum {
        INPUT_AGAIN = 1,
        REGISTRATION
    };
}



LoginNonunique::LoginNonunique() : State("LoginNonunique")
{
};



void LoginNonunique::handle(Chat* chat)
{
    std::cout << "| 1 - Войти по этому Логину | 2 - Назад к регистрации | :  ";
    std::string input;
    std::getline(std::cin >> std::ws, input);

    //Попытка преобразовать символ в число
    try {
        int choice = std::stoi(input);
        switch (choice) {
            case INPUT_AGAIN: {
                chat->transitionTo(new LoginCorrect());
                break;
            }
            case REGISTRATION: {
                chat->transitionTo(new Registration());
                break;
            }
            default: {
                std::cin.clear();
                chat->transitionTo(new LoginNonunique());
                break;
            }
        }
    }
    //Символ не число - вернуться в начало ко вводу
    catch (std::invalid_argument e) {
        chat->transitionTo(new LoginNonunique());
    }
}