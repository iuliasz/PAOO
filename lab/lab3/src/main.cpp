#include <iostream>
#include <utility>
#include "../inc/box.hpp"
using namespace std;

// Are destructor, fara copy constructor
class BadBox
{
public:
    BadBox(int size) : data_(new int[size]) { data_[0] = 0; }
    ~BadBox()
    {
        cout << "  [BadBox] destroyed: memory " << data_ << " freed" << endl;
        delete[] data_;
    }
    void set(int value) { data_[0] = value; }
    int get() const { return data_[0]; }
    const int *address() const { return data_; }

private:
    int *data_;
};

// Aloca in heap, fara destructor
class LeakBox
{
public:
    LeakBox(int size) : data_(new int[size]) {}
    const int *address() const { return data_; }

private:
    int *data_;
};

int main()
{
    cout << "1. Build cu CMake" << endl;
    cout << "  library: box.cpp, program: main.cpp" << endl;

    cout << "\n2. Incapsulare" << endl;
    {
        Box a(3); // box 1
        a.set(0, 10);
        cout << "  a[0] = " << a.get(0) << endl;
        cout << "  a.set(5, 1) -> " << (a.set(5, 1) ? "accepted" : "refused, index 5 does not exist") << endl;
        // a.data_[0] = 5;     // eroare de compilare, data_ e private
    }

    cout << "\n3. Initializare in constructor (id_ este const)" << endl;
    {
        Box x(2); // box 2
        Box y(2); // box 3
        cout << "  x has id " << x.id() << ", y has id " << y.id() << " (each box gets its own id)" << endl;
        cout << "  id_ is const: it can only be set in the initializer list, never changed after" << endl;
        // id_ = nextId_++; in corpul constructorului -> eroare de compilare (vezi box.cpp)
    }

    cout << "\n4. Destructor: eliberarea heap-ului" << endl;
    {
        Box a(3); // box 4
    } // apare mesajul de eliberare
    {
        LeakBox b(3);
        cout << "  [LeakBox] memory at " << b.address() << ", no destructor, so it is never freed (leak!)" << endl;
    } // nu apare nicio eliberare, leak

    cout << "\n5a. Copy constructor, fara el copia partajeaza memoria" << endl;
    {
        BadBox *a = new BadBox(3);
        a->set(7);
        BadBox *b = new BadBox(*a); // copy constructor generat de compilator
        b->set(99);                 // modificam doar copia
        cout << "  we changed only b, but a = " << a->get() << " too!" << endl;
        cout << "  a uses memory " << a->address() << endl;
        cout << "  b uses memory " << b->address() << " <- the same memory!" << endl;
    }

    cout << "\n5b. Copy constructor, cu el copie independenta" << endl;
    {
        Box a(3); // box 5
        a.set(0, 7);
        Box b = a; // box 6: initializare -> copy constructor
        b.set(0, 99);
        cout << "  a[0] = " << a.get(0) << ", b[0] = " << b.get(0) << " (a did not change)" << endl;
    }

    cout << "\n6. Move constructor" << endl;
    {
        Box a(3); // box 7
        a.set(0, 5);
        cout << "  a uses memory " << a.address() << endl;
        Box copy = a;        // box 8: aloca memorie noua, a ramane intact
        Box moved = move(a); // box 9: aceeasi zona, fara alocare
        cout << "  after the move, a is " << (a.isEmpty() ? "empty" : "not empty") << " (size " << a.size() << ")" << endl;
        cout << "  copy[0] = " << copy.get(0) << ", moved[0] = " << moved.get(0) << endl;

        Box copyFromEmpty = a; // box 10: copiere dintr-o sursa goala
        cout << "  the copy of the empty a is " << (copyFromEmpty.isEmpty() ? "empty too" : "not empty") << endl;
    }

    cout << "\n5c. Copy constructor, fara el double free (crash intentionat)" << endl;
    cout << "  BadBox b = a: a and b share memory, both will free it -> crash" << endl;
    {
        BadBox a(3);
        BadBox b = a;
    } // crash

    cout << "  (this line is never reached)" << endl;
    return 0;
}