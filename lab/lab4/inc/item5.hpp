#ifndef ITEM5_HPP
#define ITEM5_HPP

#include <string>
#include "text.hpp"

// ITEM 5: know what functions C++ silently writes and calls

// 5.1 What C++ writes for you
class Blank
{
}; // we wrote nothing; the compiler writes all the special functions

// A class with a Text member: the generated functions call the ones of Text
class Wrapper
{
    Text member_;
};

// No default constructor if you declare any constructor
class NeedsValue
{
public:
    NeedsValue(int v) : v_(v) {}

private:
    int v_;
};

// Generated copy is memberwise: a pointer is copied as an address (shallow).
// The generated destructor does not delete what the pointer points to.
class IntArray
{
public:
    IntArray() : data_(new int[3]) {}
    int *data() const { return data_; }

private:
    int *data_;
};

// 5.2 When operator= is not generated
template <typename T>
class Labeled
{
public:
    Labeled(std::string &name, const T &value) : label_(name), value_(value) {}
    const std::string &name() const { return label_; }
    const T &value() const { return value_; }

private:
    std::string &label_; // reference
    const T value_;      // const
};

void item5();

#endif