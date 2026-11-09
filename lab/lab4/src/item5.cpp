#include "../inc/item5.hpp"
#include <iostream>
#include <type_traits>
using namespace std;

void item5()
{
    cout << "\nITEM 5: what the compiler writes\n";

    cout << "\n5.1 What C++ writes for you\n";
    cout << "   Blank (1 = yes):\n";
    cout << "      default constructor: " << is_default_constructible<Blank>::value << "\n";
    cout << "      copy constructor:    " << is_copy_constructible<Blank>::value << "\n";
    cout << "      copy assignment:     " << is_copy_assignable<Blank>::value << "\n";
    cout << "      move constructor:    " << is_move_constructible<Blank>::value << "  (C++11)\n";
    cout << "      move assignment:     " << is_move_assignable<Blank>::value << "  (C++11)\n";

    cout << "\n   Wrapper (we wrote nothing, watch Text):\n";
    {
        cout << "   Wrapper h1;\n";
        Wrapper h1;
        cout << "   Wrapper h2(h1);\n";
        Wrapper h2(h1);
        cout << "   h2 = h1;\n";
        h2 = h1;
        cout << "   end of block:\n";
    }

    cout << "\n   NeedsValue has a constructor, so no default constructor:\n";
    cout << "      default constructor: " << is_default_constructible<NeedsValue>::value << "\n";
    // NeedsValue n;   // error: no matching function for call to NeedsValue::NeedsValue()

    cout << "\n   IntArray: generated copy copies the address:\n";
    IntArray x;
    IntArray y(x);
    cout << "      x points to " << x.data() << "\n";
    cout << "      y points to " << y.data() << "   <- same address (shallow copy)\n";
    delete[] x.data(); // the generated destructor does not do this

    cout << "\n5.2 When operator= is not generated\n";
    string nameA("Pluto");
    string nameB("Rex");
    Labeled<int> p(nameA, 2);
    Labeled<int> s(nameB, 36);
    // p = s;   // error: use of deleted function operator=
    Labeled<int> c(p); // compiles: the copy constructor initializes, it does not assign
    cout << "   c(p) works: " << c.name() << ", " << c.value() << "\n";
    cout << "   copy constructor: " << is_copy_constructible<Labeled<int>>::value << "\n";
    cout << "   copy assignment:  " << is_copy_assignable<Labeled<int>>::value
         << "  (deleted: reference and const members)\n";
    (void)s;
}