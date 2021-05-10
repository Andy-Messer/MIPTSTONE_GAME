#include <iostream>
#include <stdio.h>
#include "MYmenu.h"


Logo::Logo(int x_value, int y_value) {
    x = x_value;
    y = y_value;
}

void Logo::print() {
    std::cout << "\x1b[5;5H" << '\n';
    std::cout << "\x1b[34m             ▄▄▄▄ ▄▄▄▄─╔▄▄µ             ,▄▄▄▄▄\n"
                 "\x1b[34m            j████ ████▌╫██µ╒▄▄▄▄▄▄ ▓███J███╙██▌▄███┐ ▄▄▄▄▄  ▄▄▄▄▄▄, ▓▓▓▓\n"
                 "\x1b[34m            j█████████▌╫██▌▐██▌╟██▌╟██▌`███▓▄└ ╙███└███╨███ ███╙███ ██▌╙\n"
                 "\x1b[34m            j██▌███▓██▌╫██▌▐██▌╟██▌╞██▌  ╙████▄ ███ ███ ███ ███ ███ ████\n"
                 "\x1b[34m            j██▌███▐██▌╫██▌▐██▌╟██▌╞██▌ ███ ███ ███ ███ ███ ███ ███ ██▌\n"
                 "\x1b[34m            j██▌╟██▐██▌╫██▌▐██████⌐└███▌▀█████▀ ████╙█████▀ ███ ███ ████▌\n"
                 "\x1b[34m                           └▀▀▀\n";
}

void Logo::remove() {

}

Menu::Menu(int x_value, int y_value) {
    x = x_value;
    y = y_value;
}

void Menu::print() {
    std::cout << "\033[12;1H\n";
    std::cout << "\x1b[31m                            ▄    ▄⌐\n"
                 "\x1b[31m                           ██▌  ▓██\n"
                 "\x1b[31m                          ]███ ▐█▓█   ██▀██   ███▀█µ █Γ  █▌\n"
                 "\x1b[31m                           ██ █▓█▌ █▌ ██▓█▀╙  █▓  █▌ █⌐  █▌\n"
                 "\x1b[31m                          ▐█▒ ╟██  ╟█~╙█▄▄▄▓▌ █Γ  ██ █▓▄▄█▌\n";

}

void Menu::remove() {

}

Start::Start(int x_value, int y_value) {
    x = x_value;
    y = y_value;
}

void Start::print() {
    std::cout << "\033[20;5H                          ▓▀▀█ ▀▀█▀▀  ▓▌  █▀▀▌ ▀▀█▀▀\n";
    std::cout << "\033[5G                          ▀▀▀▄   █   ▓▄█  █▀█    █\n";
    std::cout << "\033[5G                          ▀▀▀▀   ▀  ▀  ▀  ▀ ▀▀   ▀\n";
}

void Start::remove() {

}

Cards::Cards(int x_value, int y_value) {
    x = x_value;
    y = y_value;
}

void Cards::print() {
    std::cout << "\033[24;5H                          █▀▀▌   █▌  █▀▀▌ ▐▌▀▓ ▐▌▀▀\n";
    std::cout << "\033[5G                          ▌  ,  ▓▄█  █▀█  ▐▌ ▐▌ ▀▀▓\n";
    std::cout << "\033[5G                          ▀▀▀  ▀  ▀  ▀ ▀▀ ╙▀▀▀  ▀▀▀\n";
}

void Cards::remove() {

}

Card_logo::Card_logo() {

}

void Card_logo::print() {
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
