#pragma once

namespace IBusko {
    class Player {
    private:
        char *first_name;
        char *last_name;
        char *full_name;
        char *country;
        int score;
    public:
        // Конструктор по умолчанию.
        // Вызывается в конструкции IBusko::Player p3;
        Player();

        // Перегрузка конструктора
        Player(
            const char *const first_name,
            const char *const last_name,
            const char *const country,
            const int score
        );

        // Конструктор копирования.
        // Вызывается при:
        //  1. Объявлении и инициализации одновременно IBusko::Player p2(p1);
        //  и IBusko::Player p3 = p1; - НО не путать с оператором присваивания
        //  2. При входе в функцию и передаче туда объекта Player show_player_address(p1); 
        Player(const Player &player);
        
        // Константный метод. А возвращаемое значение неконстантное.
        char* get_full_name() const;

        // Перегруженный оператор присваивания.
        // Вызывается в ситуации:
        //  IBusko::Player p3; - а здесь будет вызван конструктор по умолчанию
        //  p3 = p1;
        const Player& operator = (const Player &player);
        
        // Деструктор.
        // Вызывается, когда объект выходит из области видимости.
        ~Player();
    };
}
