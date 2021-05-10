cmake_minimum_required(VERSION 3.16)

project(CardsLib)

add_library(CardsLib SHARED Units/lib_cards.cpp Units/Card.cpp)
add_library(LogosLib SHARED logo/menu.cpp)
add_library(StubLib SHARED Stub/Stub.cpp)
add_library(CardPrintLib SHARED Card/PrintCard.cpp)
add_library(Comm_wth_user SHARED Interaction/interaction.cpp)
