#ifndef ITEM6_HPP
#define ITEM6_HPP

// ITEM 6: explicitly disallow compiler generated functions you do not want

// C++11 and later: = delete
class Apartment
{
public:
    Apartment() = default;
    Apartment(const Apartment &) = delete;
    Apartment &operator=(const Apartment &) = delete;
};

// C++98 (the book): declare private, never define
class Apartment98
{
public:
    Apartment98() {}

private:
    Apartment98(const Apartment98 &); // declared, never defined
    Apartment98 &operator=(const Apartment98 &);
};

// C++98 (the book): inherit privately from Uncopyable
class Uncopyable
{
protected:
    Uncopyable() {}
    ~Uncopyable() {}

private:
    Uncopyable(const Uncopyable &);
    Uncopyable &operator=(const Uncopyable &);
};

class ApartmentBase : private Uncopyable
{
};

void item6();

#endif