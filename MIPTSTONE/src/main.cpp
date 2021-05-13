#include "lib_cards.h"
#include "UI/MainMenu.h"

int main() {
    lib_cards lib;
    game::Menu menu;
    menu.command_handler(lib);
}