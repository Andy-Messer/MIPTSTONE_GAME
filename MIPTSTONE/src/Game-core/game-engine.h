//
// Created by andrey on 13.05.2021.
//

#ifndef MIPTSTONE_GAME_ENGINE_H
#define MIPTSTONE_GAME_ENGINE_H

#include <iostream>
#include <vector>
#include <string>
#include "lib_cards.h"
#include "Card.h"
#include "PrintCard.h"
#include <stdlib.h>
#include <time.h>

namespace fight {

    const int MAX_cards_in_hand = 7;
    enum Status {
        moving,
        in_game,
        waiting,
        buying,
        end_moving,
        gave_up,
        died
    };

    struct Card_in_game {
        int hp;
        int attack;
        int cost;
        Status status = in_game;
        Card _card;

        Card_in_game() : hp(0), attack(0), cost(0) {}

        Card_in_game(Card card) : hp(card.hp_), attack(card.attack_), cost(card.cost_), _card(card) {}
    };


    void PrintCard_in_game(std::ostream &out, Card_in_game x) {
        out << "               Name: " << x._card.name_ << "\n";
        out << "         Department: " << x._card.department_ << "\n";
        out << "       Expert_level: " << x._card.expert_level_ << "\n";
        out << "   Instructor_level: " << x._card.instructor_level_ << "\n";
        out << "Communication_level: " << x._card.communication_level_ << "\n";
        out << "      Freebie_level: " << x._card.freebie_level_ << "\n";
        out << "             Attack: " << x.attack << "\n";
        out << "                 HP: " << x.hp << "\n";
        out << "               Cost: " << x.cost << "\n";
    }

    void issuing_cards_on_start(int &hp, std::vector<Card_in_game> &hand, std::vector<Card_in_game> &deck) {
        if (!deck.empty()) {
            while (hand.size() != MAX_cards_in_hand) {
                hand.push_back(deck.back());
                deck.pop_back();
            }
        } else {
            std::cout << "You don't have cards in deck\n ! hp -5 !!!!!";
            hp -= 5;
        }
    }

    void issuing_cards(int &hp, std::vector<Card_in_game> &hand, std::vector<Card_in_game> &deck) {
        if (!deck.empty()) {
            if (hand.size() != MAX_cards_in_hand) {
                hand.push_back(deck.back());
                deck.pop_back();
            }
        } else {
            std::cout << "You don't have cards in deck\n ! hp -5 !!!!!";
            hp -= 5;
        }
    }

    struct Player {
        std::vector<Card_in_game> in_hand;
        int hp;
        int mana;
        Status status = in_game;
        std::string ready = "N";
        long long num;

        Player(std::vector<Card_in_game> in_hand, int hp, int mana) : in_hand(in_hand), hp(hp), mana(mana) {}

        Player() {}

        void preparing_to_fight_interface(std::vector<Card_in_game> &table) {
            while (status != end_moving && status != gave_up) {
                std::cout << "\n";
                std::cout << "Player " << num << " your move\n";
                std::cout << "Your health: " << hp << "\n";
                std::cout << "Your mana: " << mana << "\n";
                std::cout << "Commands: end - E, hand - H, select card - S, table - T, give up - G\n";
                std::vector<std::string> str;
                str.push_back("E");
                str.push_back("H");
                str.push_back("S");
                str.push_back("G");
                str.push_back("T");
                std::cout << "Enter command: ";
                std::string command;
                std::cin >> command;
                int index = std::find(str.begin(), str.end(), command) - str.begin();
                std::string s;
                if (index == 3)
                    status = gave_up;
                switch (index) {
                    case 0:
                        status = end_moving;
                        return;
                    case 1:
                        for (auto &i:in_hand) {
                            std::cout << '\n';
                            PrintCard_in_game(std::cout, i);
                        }
                        std::cout
                                << "\n if you want to give card to table select it with command - S and give a number\n";
                        break;
                    case 2:
                        std::cout << "give a number\n";
                        long long number;
                        std::cin >> number;
                        std::cout << "buying this card will cost " << in_hand[number - 1].cost << '\n';
                        std::cout << "Are you sure? - Y/N\n";
                        std::cin >> s;
                        if (s == "Y") {
                            if (mana >= in_hand[number - 1].cost) {
                                mana -= in_hand[number - 1].cost;
                                table.push_back(in_hand[number - 1]);
                                in_hand.erase(in_hand.begin() + number - 1);
                                std::cout << "Ok\n";
                            } else {
                                std::cout << "You don't have any mana for this\n";
                            }
                        }
                        break;
                    case 3:
                        status = gave_up;
                        break;
                    case 4:
                        for (auto &i:table) {
                            std::cout << '\n';
                            PrintCard_in_game(std::cout, i);
                        }
                        break;
                    default:
                        std::cout << "Sorry, wrong command\n";
                }
            }
        }

    };

    enum Status_Player {
        first,
        second
    };

    void reverse(Status_Player &a) {
        if (a == first)
            a = second;
        else
            a = first;
    }

    class Fight {
        Status_Player player_status;
        Player player_first;
        Player player_second;
        std::vector<Card_in_game> on_table_player_first;
        std::vector<Card_in_game> on_table_player_second;
        std::vector<Card_in_game> on_deck_player_first;
        std::vector<Card_in_game> on_deck_player_second;

        long long round = 0;

        std::vector<Card_in_game> generate_deck(lib_cards &lib) {
            std::vector<Card_in_game> temp;
            while (temp.size() <= 30) {
                temp.push_back(Card_in_game(lib.Get_card((rand()) % lib.size())));
            }
            return temp;
        }

    public:
        void start(lib_cards &lib) {
            system("clear");
            srand(time(NULL));
            player_first.hp = 100;
            player_second.hp = 100;
            player_first.num = 1;
            player_second.num = 2;
            on_deck_player_first = generate_deck(lib);
            on_deck_player_second = generate_deck(lib);
            player_status = first;
            round = 1;
            issuing_cards_on_start(player_second.hp, player_first.in_hand, on_deck_player_first);

            issuing_cards_on_start(player_second.hp, player_second.in_hand, on_deck_player_second);

            while (player_first.hp >= 0 && player_second.hp >= 0 && player_first.status == in_game &&
                   player_second.status == in_game) {
                std::cout << "!--- Attention ---! round: " << round;
                int moves = 0;
                while (moves < 2) {
                    if (player_status == first) {
                        issuing_cards(player_second.hp, player_first.in_hand, on_deck_player_first);
                        player_first.mana = (round + 1) * 50;
                        player_first.preparing_to_fight_interface(on_table_player_first);
                        if (player_first.status == gave_up)
                            break;
                        moves++;
                        reverse(player_status);
                        if (player_first.status == end_moving) {
                            player_first.status = in_game;
                        }
                        system("clear");
                    } else {
                        std::cout << "!--- Attention ---! round: " << round;
                        issuing_cards(player_second.hp, player_second.in_hand, on_deck_player_second);
                        player_second.mana = (round + 1) * 200;
                        player_second.preparing_to_fight_interface(on_table_player_second);
                        if (player_second.status == gave_up)
                            break;
                        moves++;
                        if (player_second.status == end_moving) {
                            player_second.status = in_game;
                        }
                        reverse(player_status);
                        system("clear");
                    }
                }
                if (player_second.status != gave_up && player_first.status != gave_up)
                    std::cout << "------------!!!!-FIGHT-!!!!------------\n";
                sleep(1);
                system("clear");
                while (!on_table_player_first.empty() && !on_table_player_second.empty()) {
                    std::vector<int> died_1;
                    std::vector<int> died_2;
                    if (player_status == first) {
                        int ind1 = 0, ind2 = 0;
                        for (auto &f:on_table_player_first) {
                            ++ind1;
                            if (f.status != died)
                                for (auto &s:on_table_player_second) {
                                    ++ind2;
                                    if (s.status != died) {
                                        fight_cards(f, s);
                                    } else
                                        died_2.push_back(ind2);
                                }
                            else
                                died_1.push_back(ind1);
                        }

                    } else {
                        int ind1 = 0, ind2 = 0;
                        for (auto &s:on_table_player_second) {
                            ++ind2;
                            if (s.status != died)
                                for (auto &f:on_table_player_first) {
                                    ++ind1;
                                    if (f.status != died) {
                                        fight_cards(f, s);
                                    } else
                                        died_1.push_back(ind1);
                                }
                            else
                                died_2.push_back(ind2);
                        }
                    }
                    for (auto &i:died_1) {
                        on_table_player_first.erase(on_table_player_first.begin() + i - 1);
                    }
                    for (auto &i:died_2) {
                        on_table_player_second.erase(on_table_player_second.begin() + i - 1);
                    }
                    reverse(player_status);
                }
                if (on_table_player_second.empty()) {
                    if (!on_table_player_first.empty()) {
                        for (auto &i:on_table_player_first) {
                            player_second.hp -= i.attack;
                        }
                    }
                } else {
                    for (auto &i:on_table_player_second) {
                        player_first.hp -= i.attack;
                    }
                }
                reverse(player_status);
                round++;
            }
            system("clear");
        }

        void fight_cards(Card_in_game &attacking, Card_in_game &defending) {
            attacking.hp -= defending.attack;
            defending.hp -= attacking.attack;
            if (attacking.hp < 0) {
                attacking.status = died;
            }
            if (defending.hp < 0) {
                defending.status = died;
            }
        }

        void reset() {
            player_first.status = in_game;
            player_second.status = in_game;
            on_table_player_second.clear();
            on_table_player_first.clear();
            on_deck_player_second.clear();
            on_deck_player_first.clear();
        }
    };


}
#endif //MIPTSTONE_GAME_ENGINE_H