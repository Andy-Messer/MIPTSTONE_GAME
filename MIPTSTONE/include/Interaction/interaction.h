#include <iostream>
#include "lib_cards.h"
#include "Card.h"
#include "MYmenu.h"
#include <unistd.h>
#include "Stub.h"
#include "PrintCard.h"

class Comm_wth_user{
public:
  Comm_wth_user() = default;

  void Start_menu(lib_cards& lib){
    system("clear");
    Logo A(1, 1);
    Menu L(1, 1);
    Cards C(1, 1);
    Card_logo P;
    A.print();
    L.print();
    P.print();
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Enter some of that commands:\n";
    std::cout << "    1) Start New Game        = S\n";
    std::cout << "    2) " << "Show Card with number [1 - " << lib.size() << "] = V [number]" << "\n";
    std::cout << "    3) Quit                  = Q\n";
  }

  void Enter_command(){
    std::cout << "Enter command: ";
  }

  ~Comm_wth_user() = default;
};
