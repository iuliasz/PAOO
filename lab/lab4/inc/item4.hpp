#ifndef ITEM4_HPP
#define ITEM4_HPP

#include <iostream>
#include <string>
#include "text.hpp"

// ITEM 4: make sure objects are initialized before they're

// 4.1 Uninitialized values are undefined behavior

class Position
{
public:
    int x = 0; // initialized at the declaration (C++11)
    int y = 0;
};

// 4.2 Assignment is not initialization
// Assignment in the body
class ContactAssign
{
public:
    ContactAssign(const std::string &name, int times)
    {
        name_ = name; // assignment, not initialization
        calls_ = times;
    }

private:
    Text name_;
    int calls_;
};

// Member initialization list
class ContactList
{
public:
    ContactList(const std::string &name, int times)
        : name_(name), calls_(times)
    {
    }

private:
    Text name_;
    int calls_;
};

// const members and references MUST be set in the list
class Member
{
public:
    Member(int id, int &visits) : id_(id), visits_(visits) {}
    int id() const { return id_; }
    int visits() const { return visits_; }

private:
    const int id_;
    int &visits_;
};

// 4.3 Initialization order and static objects
// Members are initialized in DECLARATION order, not in the order of the list.
class Order
{
public:
    Order() : second_("second"), first_("first") {}

private:
    Text first_; // declared first  -> built first
    Text second_;
};

// Bad version: b is declared first, so b(a) reads a before a exists.
//     class Pair { int b; int a; public: Pair(int x) : a(x), b(a) {} };   // undefined behavior
// Fix: declare a first.
class PairFixed
{
public:
    PairFixed(int x) : a(x), b(a) {}
    int a; // declared first
    int b;
};

// Static objects: instead of a global object, a function that returns a local static.
class Printer
{
public:
    Printer() : numTrays_(4) { std::cout << "      Printer: created\n"; }
    int numTrays() const { return numTrays_; }

private:
    int numTrays_;
};

Printer &thePrinter(); // clients call thePrinter() instead of using a global object

void item4();

#endif