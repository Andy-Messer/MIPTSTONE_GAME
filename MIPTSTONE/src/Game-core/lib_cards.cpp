//
// Created by krotov_ai on 20.03.2021.
//

#include "lib_cards.h"
#include <fstream>
#include <iostream>
#include <string>

std::size_t lib_cards::size() {
    return lib_of_cards.size();
}

bool lib_cards::Read_cards_from_file() {
    std::ifstream input;
    input.open("card_database.txt");

    std::string name;
    std::string department;
    std::string value;
    double expert;
    long long count = 0;
    double instructor;
    double communication;
    double freebie;
    if (input.is_open()) {
        while (!input.eof()) {
            getline(input, name);

            count++;

            getline(input, department);

            getline(input, value);
            expert = stod(value);

            getline(input, value);
            instructor = stod(value);

            getline(input, value);
            communication = stod(value);

            getline(input, value);
            freebie = stod(value);

            Card new_card(name, department,
                          expert,
                          instructor,
                          communication,
                          freebie);

            getline(input, value);

            lib_of_cards.push_back(new_card);

        }
        input.close();
        return true;
    } else {
        return false;
    }
}

Card lib_cards::Get_card(int num_of_card) {
    return lib_of_cards[num_of_card];
}
