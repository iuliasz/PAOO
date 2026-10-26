#include "../inc/box.hpp"
#include <iostream>
using namespace std;

int Box::nextId_ = 1;

// Constructor cu lista de initializare
// id_ este const => poate primi valoare doar in lista de initializare
// Varianta cu atribuire in corpul constructorului nu compileaza:
//
// Box::Box(int size)
// {
//     id_ = nextId_++;   // eroare: assignment of read-only member 'Box::id_'
//     size_ = size;
//     data_ = new int[size];
// }

Box::Box(int size) : id_(nextId_++), size_(size), data_(new int[size])
{
    for (int i = 0; i < size_; i++)
        data_[i] = 0;
    cout << "  [box " << id_ << "] created: " << size_ << " numbers at " << data_ << endl;
}

// Copy constructor
Box::Box(const Box &other)
    : id_(nextId_++), size_(other.size_),
      data_(other.data_ != nullptr ? new int[other.size_] : nullptr)
{
    for (int i = 0; i < size_; i++)
        data_[i] = other.data_[i];
    if (data_ != nullptr)
        cout << "  [box " << id_ << "] copied from box " << other.id_ << ": own memory at " << data_ << endl;
    else
        cout << "  [box " << id_ << "] copied from box " << other.id_ << ": it was empty, nothing to copy" << endl;
}

// Move constructor
Box::Box(Box &&other) noexcept : id_(nextId_++), size_(other.size_), data_(other.data_)
{
    other.data_ = nullptr;
    other.size_ = 0;
    cout << "  [box " << id_ << "] moved from box " << other.id_ << ": takes memory " << data_ << ", box " << other.id_ << " is now empty" << endl;
}

// Destructor
Box::~Box()
{
    if (data_ != nullptr)
        cout << "  [box " << id_ << "] destroyed: memory " << data_ << " freed" << endl;
    else
        cout << "  [box " << id_ << "] destroyed: empty, nothing to free" << endl;
    delete[] data_;
}

// Incapsulare
bool Box::set(int index, int value)
{
    if (index < 0 || index >= size_)
        return false; // index invalid
    data_[index] = value;
    return true;
}

int Box::get(int index) const
{
    if (index < 0 || index >= size_)
        return -1;
    return data_[index];
}

int Box::size() const { return size_; }
int Box::id() const { return id_; }
const int *Box::address() const { return data_; }
bool Box::isEmpty() const { return data_ == nullptr; }
