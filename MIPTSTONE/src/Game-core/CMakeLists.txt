cmake_minimum_required(VERSION 3.16)

add_library(Cards_lib SHARED lib_cards.cpp lib_cards.h)
add_library(Card_structure SHARED Card.cpp Card.h)
add_library(Card_print SHARED PrintCard.cpp PrintCard.h)
add_library(game SHARED game-engine.cpp game-engine.h)

