#include <cstdlib>
#include <iostream>

#include "player.hpp"

namespace {
    void show_player_address(IBusko::Player player);
}

int main() {
    std::system("chcp 1251 > log");

    const char *first_name = "Илья";
    const char *last_name = "Бусько";
    const char *country = "Беларусь";
    const int score = 2185;

    IBusko::Player p1 = { first_name, last_name, country, score };

    std::cout << "show_player_address(p1);" << std::endl;
    show_player_address(p1);
    std::cout << std::endl;

    {
        std::cout << "IBusko::Player p2(p1);" << std::endl;
        IBusko::Player p2(p1);
        std::cout << "Выходим из блока видимости p2" << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "IBusko::Player p3 = p1;" << std::endl;
        IBusko::Player p3;
        p3 = p1;
        std::cout << "Выходим из блока видимости p3" << std::endl;
        std::cout << std::endl;
    }

    return 0;
}

namespace {
    void show_player_address(IBusko::Player player) {
        std::cout << "Внутри функции. При передаче объекта должен был быть вызван КК." << std::endl;
        std::cout << "Выходим из блока видимости show_player_address" << std::endl;
    }
}
