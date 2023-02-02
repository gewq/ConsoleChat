#include "LoginCorrect.h"
#include <iostream>

LoginCorrect::LoginCorrect() : State("LoginCorrect")
{
};



void LoginCorrect::handle(Chat* chat)
{
    std::cout << "Введите Пароль: ";
    std::string password;
    std::getline(std::cin >> std::ws, password);

    //Допустимые символы
    if (chat->isCorrectValue(password)) {
        const std::string login = chat->getUser()->getLogin();
        //Пароль правильный
        if (database::isCorrectPassword(login, password)) {
            //Загрузить из базы и задать Ник текущего пользователя
            const std::string name = database::getNameByLogin(login);
            chat->getUser()->setName(name);
            chat->transitionTo(new UserInChat());
        }

        //Пароль неверный
        else {
            std::cout << "Пароль неверный!\n";
            chat->transitionTo(new PasswordIncorrect());
        }
    }

    //Недопустимые символы
    else {
        std::cout << "Некорректные символы.\n";
        std::cin.clear();
        chat->transitionTo(new LoginCorrect());
    }
}