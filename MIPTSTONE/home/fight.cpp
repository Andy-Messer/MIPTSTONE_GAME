#include <iostream>
#include <vector>
#include <string>
#include "lib_cards.h"
#include "Card.h"
#include "PrintCard.h"

struct Card_in_game {
    int hp;
    int attack;
    int cost;
    Card _card;

    Card_in_game() : hp(hp), attack(attack), cost(cost) {}

    Card_in_game(Card card) : hp(card.GetHp()), attack(card.GetAttack()), cost(card.GetCost()), _card(card) {}
};

struct Player {
    std::vector<Card> in_hand;
    int hp;
    int mana;
    std::string ready = "N";

    Player(std::vector<Card> in_hand, int hp, int mana) : in_hand(in_hand), hp(hp), mana(mana) {

    }

    Player() {}

};

enum Status_Player {
    first,
    second
};

void PrintCard_in_game(std::ostream &out, Card_in_game x) {
    out << "               Name: " << x._card.GetName() << "\n";
    out << "         Department: " << x._card.GetDepartment() << "\n";
    out << "       Expert_level: " << x._card.GetExpert() << "\n";
    out << "   Instructor_level: " << x._card.GetInstructor() << "\n";
    out << "Communication_level: " << x._card.GetCommunication() << "\n";
    out << "      Freebie_level: " << x._card.GetFreebie() << "\n";
    out << "             Attack: " << x.attack << "\n";
    out << "                 HP: " << x.hp << "\n";
    out << "               Cost: " << x.cost << "\n";
}

class Fight {
public:
    Status_Player player_status;
    Player player_first;
    Player player_second;
    std::vector<Card_in_game> on_table_player_first;
    std::vector<Card_in_game> on_table_player_second;

    Fight() {}

    void motion(lib_cards &lib) {
        if (player_status == first) {
            std::cout << "First player:\n";
            std::cout << "Your mana:" << player_first.mana << "\n";
            std::cout << "Join Action: " << '\n';
            std::cout << "BUY, Fight, END, Show table\n";
            std::string action;
            std::cin >> action;
            while (action != "END") {
                if (action == "BUY") {
                    std::cout << "ENTER num of Card [1..868]\n";
                    int x;
                    std::cin >> x;
                    x--;
                    if (x >= lib.size()) {
                        std::cout << "Sorry, in the library for now only " << lib.size() << " preps\n";
                    } else {
                        PrintCard(std::cout, lib, x);
                        if (lib.Get_card(x).GetCost() > player_first.mana) {
                            std::cout << "You don't have any mana for this.\n";
                        } else {
                            std::cout << "Are You really want to buy it?(Y/N)";
                            std::string s;
                            std::cin >> s;
                            if (s == "Y") {
                                player_first.in_hand.push_back(lib.Get_card(x));
                                player_first.mana -= lib.Get_card(x).GetCost();
                            }
                        }
                    }
                }
                if (action == "Show") {
                    std::cout << "table: \n";
                    for (auto &x:on_table_player_first) {
                        PrintCard_in_game(std::cout, x);
                    }
                }
                if (action == "Fight") {
                    for (auto &x:player_first.in_hand) {
                        on_table_player_first.emplace_back(x);
                    }
                    player_first.in_hand.clear();
                    player_first.ready = "Y";
                    action = "END";
                } else {
                    std::cout << "Your mana:" << player_first.mana << "\n";
                    std::cout << "Join Action: " << '\n';
                    std::cout << "BUY, Fight, END, Show table\n";
                    std::cin >> action;
                }
            }
        }
        if (player_status == second) {
            std::cout << "Second player:\n";
            std::cout << "Your mana:" << player_second.mana << "\n";
            std::cout << "Join Action: " << '\n';
            std::cout << "BUY, Fight, END, Show table\n";
            std::string action;
            std::cin >> action;
            while (action != "END") {
                if (action == "BUY") {
                    std::cout << "ENTER num of Card [1..868]\n";
                    int x;
                    std::cin >> x;
                    x--;
                    if (x >= lib.size()) {
                        std::cout << "Sorry, in the library for now only " << lib.size() << " preps\n";
                    } else {
                        PrintCard(std::cout, lib, x);
                        if (lib.Get_card(x).GetCost() > player_second.mana) {
                            std::cout << "You don't have any mana for this.\n";
                        } else {
                            std::cout << "Are You really want to buy it?(Y/N)";
                            std::string s;
                            std::cin >> s;
                            if (s == "Y") {
                                player_second.in_hand.push_back(lib.Get_card(x));
                                player_second.mana -= lib.Get_card(x).GetCost();
                            }
                        }
                    }
                }
                if (action == "Show") {
                    std::cout << "table: \n";
                    for (auto &x:on_table_player_second) {
                        PrintCard_in_game(std::cout, x);
                    }
                }
                if (action == "Fight") {
                    for (auto &x:player_second.in_hand) {
                        on_table_player_second.emplace_back(x);
                    }
                    player_second.in_hand.clear();
                    player_second.ready = "Y";
                    action = "END";
                } else {
                    std::cout << "Second player:\n";
                    std::cout << "Your mana:" << player_second.mana << "\n";
                    std::cout << "Join Action: " << '\n';
                    std::cout << "BUY, Fight, END, Show table\n";
                    std::cin >> action;
                }
            }
        }
        change_status();
    }

    void Reset_First() {
        player_first.ready = "N";
        for (auto &x:on_table_player_first) {
            player_first.mana += x.cost / 2;
        }
        on_table_player_first.clear();
    }

    void Reset_Second() {
        player_second.ready = "N";
        for (auto &x:on_table_player_second) {
            player_second.mana += x.cost / 2;
        }
        on_table_player_second.clear();
    }

    void Fight_game(long long num_of_game) {
        while (!on_table_player_second.empty() && !on_table_player_first.empty()) {
            if (num_of_game % 2 == 0) {
                long long ind = 0;
                for (auto &x:on_table_player_first) {
                    long long index = 0;
                    while (x.hp > 0 && !on_table_player_second.empty()) {
                        fight_cards(x, on_table_player_second[index]);
                        if (on_table_player_second[index].hp < 0) {
                            on_table_player_second.erase(on_table_player_second.begin() + ind);
                        }
                        index++;
                        if (on_table_player_second.size() > 0)
                            index %= on_table_player_second.size();
                    }

                    if (x.hp <= 0)
                        on_table_player_first.erase(on_table_player_first.begin() + ind);
                    else
                        ind++;
                }
                ind = 0;
                for (auto &x:on_table_player_second) {
                    long long index = 0;
                    while (x.hp > 0 && !on_table_player_first.empty()) {
                        fight_cards(x, on_table_player_first[index]);
                        if (on_table_player_first[index].hp < 0) {
                            on_table_player_first.erase(on_table_player_first.begin() + ind);
                        }
                        index++;
                        if (on_table_player_first.size() > 0)
                            index %= on_table_player_first.size();
                    }

                    if (x.hp <= 0)
                        on_table_player_second.erase(on_table_player_second.begin() + ind);
                    else
                        ind++;
                }
            } else {

                long long ind = 0;
                for (auto &x:on_table_player_second) {
                    long long index = 0;
                    while (x.hp > 0 && !on_table_player_first.empty()) {
                        fight_cards(x, on_table_player_first[index]);
                        if (on_table_player_first[index].hp < 0) {
                            on_table_player_first.erase(on_table_player_first.begin() + ind);
                        }
                        index++;
                        if (on_table_player_first.size() > 0)
                            index %= on_table_player_first.size();
                    }

                    if (x.hp <= 0)
                        on_table_player_second.erase(on_table_player_second.begin() + ind);
                    else
                        ind++;
                }
                ind = 0;

                for (auto &x:on_table_player_first) {
                    long long index = 0;
                    while (x.hp > 0 && !on_table_player_second.empty()) {
                        fight_cards(x, on_table_player_second[index]);
                        if (on_table_player_second[index].hp < 0) {
                            on_table_player_second.erase(on_table_player_second.begin() + ind);
                        }
                        index++;

                        if (on_table_player_second.size() > 0)
                            index %= on_table_player_second.size();
                    }

                    if (x.hp <= 0)
                        on_table_player_first.erase(on_table_player_first.begin() + ind);
                    else
                        ind++;
                }

            }
        }
        for (auto &x:on_table_player_first){
            player_second.hp-=x.attack;
        }
        for (auto &x:on_table_player_second){
            player_first.hp-=x.attack;
        }
    }

private:
    void change_status() {
        if (player_status == first) player_status = second;
        else player_status = first;
    }

//
    void fight_cards(Card_in_game &attack_card, Card_in_game &defence_card) {
        attack_card.hp -= defence_card.attack;
        defence_card.hp -= attack_card.attack;
    }
//
//    void fight_player(Card &attack_card) {
//        if (player_status == first) {
//            player_second.hp -= attack_card.attack;
//        } else {
//            player_first.hp -= attack_card.attack;
//        }
//    }
};
