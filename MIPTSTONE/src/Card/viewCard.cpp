//
// Created by krotov_ai on 21.03.2021.
//
#include "ViewCard.h"
#include "lib_cards.h"
void ViewCard(lib_cards& lib, int num){
    Card card_to_show = lib.Get_card(num);
    std::cout<<"            name: "<<card_to_show.getName()<<"\n";
    std::cout<<"     departament: "<<card_to_show.getDepartament()<<"\n";
    std::cout<<"Knowledge: "<<card_to_show.getKnowledge()<<"\n";
    std::cout<<"Teaching: "<<card_to_show.getTeaching()<<"\n";
    std::cout<<"Communication: "<<card_to_show.getCommunication()<<"\n";
    std::cout<<"Khaluavnost: "<<card_to_show.getKhaluavnost()<<"\n";
    std::cout<<"Attack: "<<card_to_show.getAttack()<<"\n";
    std::cout<<"HP: "<<card_to_show.getHp()<<"\n";
    std::cout<<"Cost: "<<card_to_show.getCost()<<"\n";
}