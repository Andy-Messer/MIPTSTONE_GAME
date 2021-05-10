#include "PrintCard.h"
#include "lib_cards.h"

void PrintCard(std::ostream &out, lib_cards& lib, int num){
    Card card_to_show = lib.Get_card(num);
    out << "               Name: " << card_to_show.GetName()          << "\n";
    out << "         Department: " << card_to_show.GetDepartment()    << "\n";
    out << "       Expert_level: " << card_to_show.GetExpert()        << "\n";
    out << "   Instructor_level: " << card_to_show.GetInstructor()    << "\n";
    out << "Communication_level: " << card_to_show.GetCommunication() << "\n";
    out << "      Freebie_level: " << card_to_show.GetFreebie()       << "\n";
    out << "             Attack: " << card_to_show.GetAttack()        << "\n";
    out << "                 HP: " << card_to_show.GetHp()            << "\n";
    out << "               Cost: " << card_to_show.GetCost()          << "\n";
}