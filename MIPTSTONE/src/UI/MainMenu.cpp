//
// Created by Admin on 13.05.2021.
//
#include "MainMenu.h"
#include <string>
#include <algorithm>
#include "PrintCard.h"
#include <unistd.h>
#include "game-engine.h"

void game::Card_logo_Picture::print() {
    std::cout << "\033[20;200H";
    std::cout << "\033[20G:::::::::::::::;,'...'''....''''';;:::::ccccccc:::\n"
                 "\033[20G::;;:::::;;,,,'''''.........',,'.',,;:cccccccccc::\n"
                 "\033[20G;;:::::,'.....'''''''''.......'..',,,;;::ccccccccc\n"
                 "\033[20G;;::::,........''''.............'''''',;:ccccccccc\n"
                 "\033[20G::::;'..........'.........'''',,,,''''',;::ccccccc\n"
                 "\033[20G:::;'..............''',;:::cccccc:;,'''',,;:cccccc\n"
                 "\033[20G:::'........'''',,;:ccloddddxddoool:,...''';cccccc\n"
                 "\033[20G::;.  ....',;::ccloooodxxxkkkkxxdddoc;'..'',:ccccc\n"
                 "\033[20G::,. ...,:cloddddxxxkkkO000OOkkxxxxxxo:,,,,;cccccc\n"
                 "\033[20G::,...':oxkOO00000KKKKKKKK00OOkkkkkkxdc;,,,:cccccc\n"
                 "\033[20G::;..,lxkO000KKKKKKKKKK000OOkkkkOOOOkoc;,,;::ccccc\n"
                 "\033[20G::;'.;oxOOOOOOOOOOOO0Okkxxdolccccldkkxl:,';;;clccc\n"
                 "\033[20G:::,.,ldxxddlllloddxxxol:;,'.....',:oxxo;',;;:clcc\n"
                 "\033[20G:::,.'cl:;,'...',:oxkxl;,'''','''',;coxkd;,;:loolc\n"
                 "\033[20G::::'':c,'''''',;cdO0OdlllllllcccccloxkOkoc:;cddlc\n"
                 "\033[20G:::c;;lolllollooxkkO0Oxoddxxxxxdddxxkkkkkxoc;codoc\n"
                 "\033[20G:::llcoxkkkkkkOOOOOO0OxdoodxkOOOkkkxxxxxdol:coddoc\n"
                 "\033[20G:::lxxdxkOOO0000OkkO00OkdoloxkOOOkkxdddodo::ldxdlc\n"
                 "\033[20G:::lxkxdxkOOOOOkxxxO0Okxdolldxkkkxdolllodl::cllccc\n"
                 "\033[20G:::coxkdoxxkkxxdoocclc;,,,,:ldddoolccclddc::::cccc\n"
                 "\033[20G::::ccllclloddodxdc,,'....';cooolcc:cloddl:::ccccc\n"
                 "\033[20G::::::::::cllodxxddlc:;;;;;;::::ccccclooolcccccccc\n"
                 "\033[20G:::::::::::cloolccc:::;;,,,,,,,:ccc::clloc:::ccccc\n"
                 "\033[20G::::::::::::cllcc:::ccc::::;;;:clc:;:cclllc::ccccc\n"
                 "\033[20G:::::::::::::::clllc:::;;;,,,;:cc:;;:cclol:cc:::cc\n"
                 "\033[20G:::::::::::::;;;:clcc:::::::ccllc::::::lolcccccccc\n"
                 "\033[20G:::::::::::::::;;cloooooooooolcc:;;;,;:oo:;clolccc\n"
                 "\033[20G:::::::::::::ccc:;:cccc:ccc:;;,;,,,,,;codc',:lxdc:\n"
                 "\033[20G::::::::::::lolllc:;,,,,,'''''''''',;:codl;';o00dc\n"
                 "\033[20G::::::::::::ddlodolc;,'.....'''''',;::cool;;lOKXOl";
}

game::Logo_Picture::Logo_Picture(int x_value, int y_value) {
    x = x_value;
    y = y_value;
}

void game::Logo_Picture::print() {
    std::cout << "\x1b[5;5H" << '\n';
    std::cout << "\x1b[34m             ▄▄▄▄ ▄▄▄▄─╔▄▄µ             ,▄▄▄▄▄\n"
                 "\x1b[34m            j████ ████▌╫██µ╒▄▄▄▄▄▄ ▓███J███╙██▌▄███┐ ▄▄▄▄▄  ▄▄▄▄▄▄, ▓▓▓▓\n"
                 "\x1b[34m            j█████████▌╫██▌▐██▌╟██▌╟██▌`███▓▄└ ╙███└███╨███ ███╙███ ██▌╙\n"
                 "\x1b[34m            j██▌███▓██▌╫██▌▐██▌╟██▌╞██▌  ╙████▄ ███ ███ ███ ███ ███ ████\n"
                 "\x1b[34m            j██▌███▐██▌╫██▌▐██▌╟██▌╞██▌ ███ ███ ███ ███ ███ ███ ███ ██▌\n"
                 "\x1b[34m            j██▌╟██▐██▌╫██▌▐██████⌐└███▌▀█████▀ ████╙█████▀ ███ ███ ████▌\n"
                 "\x1b[34m                           └▀▀▀\n";
}

game::Menu_Picture::Menu_Picture(int x_value, int y_value) {
    x = x_value;
    y = y_value;
}

void game::Menu_Picture::print() {
    std::cout << "\033[12;1H\n";
    std::cout << "\x1b[31m                            ▄    ▄⌐\n"
                 "\x1b[31m                           ██▌  ▓██\n"
                 "\x1b[31m                          ]███ ▐█▓█   ██▀██   ███▀█µ █Γ  █▌\n"
                 "\x1b[31m                           ██ █▓█▌ █▌ ██▓█▀╙  █▓  █▌ █⌐  █▌\n"
                 "\x1b[31m                          ▐█▒ ╟██  ╟█~╙█▄▄▄▓▌ █Γ  ██ █▓▄▄█▌\n";

}

void game::Menu::print_menu(lib_cards &lib) {
    system("clear");
    Logo_Picture A(1, 1);
    Menu_Picture L(1, 1);
    Card_logo_Picture P;
    A.print();
    L.print();
    P.print();
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Enter some of that commands:\n";
    std::cout << "    1) Start New Game        = S\n";
    std::cout << "    2) " << "Show Card with number [1 - "
              << lib.size() << "] = V [number]" << "\n";
    std::cout << "    3) Quit                  = Q\n";
}

void game::Menu::escape() {
    std::cout << "Bye\n";
    sleep(3);
    system("clear");
}

void game::Menu::command_handler(lib_cards &lib) {
    std::string command;
    std::vector<std::string> str;
    str.push_back("S");
    str.push_back("V");
    str.push_back("Q");
    fight::Fight fight1;
    while (true) {
        print_menu(lib);
        Enter_command();
        std::cin >> command;
        int index = std::find(str.begin(), str.end(), command) - str.begin();
        switch (index) {
            case 0:
                fight1.reset();
                fight1.start(lib);
                break;
            case 1:
                print_card(lib);
                break;
            case 2:
                escape();
                return;
            default:
                std::cout << "Sorry, wrong command\n";
        }
    }
}

void game::Menu::print_card(lib_cards &lib) {
    int num;
    std::cin >> num;
    num--;
    if (num >= lib.size()) {
        std::cout << "Sorry, in the library for now only " << lib.size() << " preps\n";
    } else {
        PrintCard(std::cout, lib, num);
    }
}