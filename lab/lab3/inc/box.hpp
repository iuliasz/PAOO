#ifndef BOX_HPP
#define BOX_HPP

class Box
{
public:
    explicit Box(int size); // constructor

    Box(const Box &other); // copy constructor

    Box(Box &&other) noexcept; // move constructor

    ~Box(); // destructor

    // incapsulare
    bool set(int index, int value); // false daca indexul este invalid
    int get(int index) const;       // -1 daca indexul este invalid
    int size() const;
    bool isEmpty() const; // true dupa un move (data_ == nullptr)
    int id() const;
    const int *address() const; // adresa din heap

private:
    static int nextId_;
    const int id_;
    int size_;
    int *data_;
};

#endif