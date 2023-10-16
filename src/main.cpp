#include <iostream>

#include "StartGame.h"

int main()
{
    std::cout << "Welcome to the weapon shop!" << std::endl;
    std::cout << "Here you can buy any weapon you want." << std::endl;
    std::cout << "Enter C to continue. Enter E to exit." << std::endl;

    char game_menu;
    std::cin >> game_menu;

    if (int(game_menu) == 69 || int(game_menu) == 101)
    {
        std::cout << "Bye. See you soon." << std::endl;
        return 0;
    } else {
        StartNewGame();
    }

    return 0;
}