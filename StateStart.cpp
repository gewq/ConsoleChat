#include "StateStart.h"
#include <iostream>

StateStart::StateStart() : State("StateStart")
{

};



void StateStart::handle(Chat* chat)
{
    std::cout << "[  1 - ���� � ���;  2 - �����������;  3 - ����� �� ���������  ]\n";
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