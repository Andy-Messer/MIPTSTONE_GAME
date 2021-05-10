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
    input.open("prepods.txt");
    std::string name;
    std::string department;
    std::string value;
    double expert;
    long long count = 0;
    double instructor;
    double communication;
    double freebie;
    std::cout<<"\nprogress:      ";
    if (input.is_open())
        while (!input.eof()) {
            if (count%40==0 && count!=0) std::cout<<"█";
            getline(input, name);
            count++;
            getline(input, department);
            getline(input, value); expert = stod(value);
            getline(input, value); instructor = stod(value);
            getline(input, value); communication = stod(value);
            getline(input, value); freebie = stod(value);
            Card new_card(name, department,
                          expert,
                          instructor,
                          communication,
                          freebie);
            getline(input, value);
            lib_of_cards.push_back(new_card);

        }
    else {
        std::cout << "JOPA\n";
        return false;
    }
    std::cout<<"      библиотека загружена:)\n";
    input.close();

    return true;
}

// void lib_cards::CTL(){
//     std::ifstream prepods_lib;
//     prepods_lib.open("prepods.txt");
//     std::string s;
//     for (int i=0;i<lib_of_cards.size()*7;i++){
//         getline(std::cin,s);
//     }
//     std::string name;
//     std::string department;
//     double knowledge_level;
//     double teaching_level;
//     double communication_level;
//     double khaluavnost_level;
//     prepods_lib >> name;
//     prepods_lib >> department;
//     prepods_lib >> knowledge_level;
//     prepods_lib >> teaching_level;
//     prepods_lib >> communication_level;
//     prepods_lib >> khaluavnost_level;
//     Card new_card(name, department,
//                   knowledge_level,
//                   teaching_level,
//                   communication_level,
//                   khaluavnost_level);

//     lib_of_cards.push_back(new_card);
//     prepods_lib.close();
// }

Card lib_cards::Get_card(int num_of_card) {
    return lib_of_cards[num_of_card];
}
