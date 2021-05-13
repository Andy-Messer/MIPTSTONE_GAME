#include "PrintCard.h"

void PrintCard(std::ostream &out, lib_cards &lib, int num) {
    Card card_to_show = lib.Get_card(num);
    out << "               Name: " << card_to_show.name_ << "\n";
    out << "         Department: " << card_to_show.department_ << "\n";
    out << "       Expert_level: " << card_to_show.expert_level_ << "\n";
    out << "   Instructor_level: " << card_to_show.instructor_level_ << "\n";
    out << "Communication_level: " << card_to_show.communication_level_ << "\n";
    out << "      Freebie_level: " << card_to_show.freebie_level_ << "\n";
    out << "             Attack: " << card_to_show.attack_ << "\n";
    out << "                 HP: " << card_to_show.hp_ << "\n";
    out << "               Cost: " << card_to_show.cost_ << "\n";
}