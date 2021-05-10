//
// Created by krotov_ai on 21.03.2021.
//
#include <vector>
#include <string>
#include <ctime>
#include <iostream>

void Stub() {
    std::srand(std::time(0));
    std::vector<std::string> str;
    str.push_back("You came too early, come back later...");
    str.push_back("Excuse my eyes need a rest, come back later...");
    str.push_back("Sanya is sleeping again,so there is nothing here yet, come back later...");
    str.push_back("Andrey went to the dance, will come back to finish it, come back later...");
    str.push_back("Arseny is playing monopoly, he will soon fix everything, come back later...");
    int index = (std::rand()) % 5;
    std::cout << str[index] << "\n";
}
