//
// Created by krotov_ai on 21.03.2021.
//

#ifndef MIPTSTONE_Menu_H

class Logo {
public:

    Logo(int x_value, int y_value);

    void print();

    void remove();

private:
    int x;
    int y;
};

class Menu {
public:
    Menu(int x_value, int y_value);

    void print();

    void remove();

private:
    int x;
    int y;
};

class Start {
public:
    Start(int x_value, int y_value);

    void print();

    void remove();

private:
    int x;
    int y;
};

class Cards {
public:
    Cards(int x_value, int y_value);

    void print();

    void remove();

private:
    int x;
    int y;
};

class Card_logo {

public:
    Card_logo();

    void print();
};

#define MIPTSTONE_Menu_H

#endif //MIPTSTONE_Menu_H
