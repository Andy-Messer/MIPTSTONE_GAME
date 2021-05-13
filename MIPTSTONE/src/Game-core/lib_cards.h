//
// Created by krotov_ai on 20.03.2021.
//

#ifndef TP_GAME_PROJECT_LIB_CARDS_H


#include <vector>
#include "Card.h"
#include <iostream>
#include <string>



struct lib_cards {

private:

    std::vector<Card> lib_of_cards;

    bool Read_cards_from_file();

public:
    void CTL();
    size_t size();

    lib_cards() {
        if (!Read_cards_from_file()) std::cout<<"where is my lib Libovsky!";
    }

    Card Get_card(int num_of_card);
};


#define TP_GAME_PROJECT_LIB_CARDS_H

#endif //TP_GAME_PROJECT_LIB_CARDS_H
