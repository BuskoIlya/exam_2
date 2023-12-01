#include "player.hpp"

#include <cstring>
#include <iostream>

namespace IBusko {

    namespace {
        // char* &dest - ссылка на указатель. 
        // Т.е. в функцию будет передана не копия указатель, а настоящий.
        void copy_str(char* &dest, const char *const src);
        void create_full_name(
            char* &full_name,
            const char *const first_name,
            const char *const last_name
        );

        // Перегрузка функции log
        void log(const char *const comment);
        void log(const char *const comment, const Player &player);
    }

    Player::Player() {
        log("Вызван конструктор по умолчанию");
        first_name = nullptr;
        last_name = nullptr;
        full_name = nullptr;
        country = nullptr;
        score = 0;
    }

    Player::Player(
        const char *const first_name,
        const char *const last_name,
        const char *const country,
        const int score
    ) : Player() {
        log("Вызван конструктор с параметрами");
        copy_str(this->first_name, first_name);
        copy_str(this->last_name, last_name);
        copy_str(this->country, country);
        create_full_name(full_name, first_name, last_name);
        this->score = score;
    }

    Player::Player(const Player &player) :
        Player(player.first_name, player.last_name, player.country, player.score) {
        log("В конструкторе копирования. Копируем игрока", player);
    }

    char* Player::get_full_name() const {
        return full_name;
    }

    const Player& Player::operator = (const Player &player) {
        log("Вызван перегруженный оператор присваивания. Копируем игрока", player);

        if (this == &player) {
            return *this;
        } else if (this) {
            this->~Player();
        }

        // Финт ушами от С++.
        // "placement new"
        // Оператор new создаёт объект в уже выделенной памяти по адресу this
        new (this) Player(player);

        return *this;
    }

    Player::~Player() {
        log("Вызван деструктор для игрока", *this);
        if (first_name) delete[] first_name;
        if (last_name) delete[] last_name;
        if (full_name) delete[] full_name;
        if (country) delete[] country;
        std::cout << std::endl;
    }

    namespace {
        void copy_str(char* &dest, const char *const src) {
            if (dest) delete[] dest;

            const int size = std::strlen(src) + 1;
            dest = new char[size];
            strcpy_s(dest, size, src);
        }

        void create_full_name(
            char* &full_name,
            const char *const first_name,
            const char *const last_name
        ) {
            if (full_name) delete[] full_name;

            const int first_name_size = std::strlen(first_name);
            const int last_name_size = std::strlen(last_name);
            const int full_size = first_name_size + last_name_size + 3;
            full_name = new char[full_size];

            strcpy_s(full_name, full_size, first_name);
            const char* space = " ";
            strcat_s(full_name, full_size, space);
            strcat_s(full_name, full_size, last_name);
        }

        void log(const char *const comment) {
            std::cout << comment << std::endl;
        }

        void log(const char *const comment, const Player &player) {
            const char space = ' ';
            const char* unknown_player = "UNKNOWN PLAYER";
            if (player.get_full_name()) {
                std::cout << comment << space << player.get_full_name() << std::endl;
            } else {
                std::cout << comment << space << unknown_player << std::endl;
            }
        }
    }
}
