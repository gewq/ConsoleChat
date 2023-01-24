#include "StateStart.h"
#include <iostream>

StateStart::StateStart() : State("StateStart")
{

};



void StateStart::handle(Chat* chat)
{
    std::cout << "[  1 - Вход в чат;  2 - Регистрация;  3 - Выход из программы  ]\n";
    char input;
    std::cin >> input;

    //if (input == '1') {
    //    chat->transitionTo(new SignIn());
    //}
    //else if (input == '2'){
    //    chat->transitionTo(new Registration());
    //}
    //else {
    //
    //}
}