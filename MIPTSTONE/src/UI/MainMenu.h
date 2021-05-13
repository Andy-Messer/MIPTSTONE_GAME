//
// Created by krotov_ai on 21.03.2021.
//

#ifndef MIPTSTONE_Menu_H
#define MIPTSTONE_Menu_H

#include "lib_cards.h"

namespace game {
    class Logo_Picture {
    public:

        Logo_Picture(int x_value, int y_value);

        void print();

    private:
        int x;
        int y;
    };

    class Menu_Picture {
    public:
        Menu_Picture(int x_value, int y_value);

        void print();

    private:
        int x;
        int y;
    };

    class Card_logo_Picture {

    public:
        Card_logo_Picture() = default;

        void print();
    };


    class Menu {
    public:
        void Enter_command() {
            std::cout << "Enter command: ";
        }

        void print_menu(lib_cards &lib);

        void command_handler(lib_cards &lib);

        void escape();

        void print_card(lib_cards &lib);
    };
};

#endif //MIPTSTONE_Menu_H
