//
// Created by krotov_ai on 20.03.2021.
//
#include <iostream>
#include "lib_cards.h"
#include "Card.h"
#include "MYmenu.h"
#include <unistd.h>
#include "Stub.h"
#include "PrintCard.h"
#include "fight.cpp"
#include "interaction.h"

int main() {

    Comm_wth_user out;
    lib_cards lib;
    out.Start_menu(lib);
    std::string command;
    std::vector<std::string> str;
    str.push_back("S");
    str.push_back("V");
    str.push_back("Q");
    std::string ans;
    while (true) {
        //out.Start_menu(lib);
        out.Enter_command();
        std::cin >> command;
        int index = find(str.begin(), str.end(), command) - str.begin();
        Fight new_f;
        long long round = 0;
        std::string ans;
        //std::cout<<index<<"\n";
        switch (index) {
            case 0:
                new_f.player_first = Player({}, 1000, 100);
                new_f.player_second = Player({}, 1000, 100);
                new_f.player_status = first;
                while (new_f.player_first.hp > 0 && new_f.player_second.hp > 0) {

                    std::cout << round + 1 << " ROUND!!!!\n";
                    new_f.motion(lib);
                    new_f.motion(lib);
                    new_f.Fight_game(round);
                    round++;
                    std::cout << "END_OF_ROUND!!!\n";
                    std::cout << "Player one. Do you want to sell your Deck?(Y/N)\n";
                    std::cin >> ans;
                    if (ans == "Y") {
                        new_f.Reset_First();
                    }
                    std::cout << "Player two. Do you want to sell your Deck?(Y/N)\n";
                    std::cin >> ans;
                    if (ans == "Y") {
                        new_f.Reset_Second();
                    }
                }
                if (new_f.player_first.hp > 0) {
                    std::cout << "FIRST PLAYER WIN!!!!\n";
                } else {
                    std::cout << "SECOND PLAYER WIN!!!\n";
                }
                std::cout << "\n";
                out.Start_menu(lib);
                break;
            case 1:
                int num;
                std::cin >> num;
                num--;
                if (num >= lib.size()) {
                    std::cout << "Sorry, in the library for now only " << lib.size() << " preps\n";
                } else {
                    PrintCard(std::cout, lib, num);
                }
                break;
            case 2:
                std::cout << "Bye\n";
                sleep(3);
                system("clear");
                return 0;
            default:
                std::cout << "Sorry, wrong command\n";
        }
    }
    return 0;
}
