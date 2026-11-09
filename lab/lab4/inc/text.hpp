#ifndef TEXT_HPP
#define TEXT_HPP

#include <iostream>
#include <string>

// Helper class: prints a message whenever C++ creates, copies, assigns or destroys it.
class Text
{
public:
    Text() { std::cout << "      Text: default constructor\n"; }
    Text(const std::string &s) : s_(s) { std::cout << "      Text \"" << s_ << "\": constructor with value\n"; }
    Text(const Text &other) : s_(other.s_) { std::cout << "      Text: copy constructor\n"; }
    Text &operator=(const std::string &s)
    {
        s_ = s;
        std::cout << "      Text: assignment from string\n";
        return *this;
    }
    Text &operator=(const Text &other)
    {
        s_ = other.s_;
        std::cout << "      Text: copy assignment\n";
        return *this;
    }
    ~Text() { std::cout << "      Text: destructor\n"; }

private:
    std::string s_;
};

#endif