#include "../inc/item4.hpp"
#include <vector>
using namespace std;

int globalInt; // global: initialized to 0 by C++

Printer &thePrinter()
{
    static Printer printer; // created on the FIRST call
    return printer;
}

void item4()
{
    cout << "\nITEM 4: initialize before use\n";

    cout << "\n4.1 Uninitialized values\n";
    static int staticInt;
    cout << "   global int = " << globalInt << ", static int = " << staticInt << " (C++ sets them to 0)\n";
    string s;
    vector<int> v;
    cout << "   string is \"" << s << "\", vector has " << v.size() << " elements (their own constructors)\n";
    // int local;  cout << local;   // undefined behavior: garbage
    Position p;
    cout << "   Position p: x = " << p.x << ", y = " << p.y << " (we initialized them by hand)\n";

    cout << "\n4.2 Assignment is not initialization\n";
    cout << "   Assignment in the body:\n";
    {
        ContactAssign a("Ana", 0);
    }
    cout << "   Member initialization list:\n";
    {
        ContactList b("Ana", 0);
    }

    cout << "\n   const member and reference (must be in the list):\n";
    int visits = 1;
    Member r(7, visits);
    visits = 2;
    cout << "      id = " << r.id() << ", visits = " << r.visits() << "\n";

    cout << "\n4.3 Initialization order and static objects\n";
    cout << "   Order: the list says second, then first. Real order:\n";
    {
        Order o;
    }
    PairFixed f(5);
    cout << "   PairFixed(5): a = " << f.a << ", b = " << f.b << " (a declared first)\n";

    cout << "\n   Static object through thePrinter():\n";
    cout << "   first call:\n";
    int trays1 = thePrinter().numTrays();
    cout << "      numTrays = " << trays1 << "\n";
    cout << "   second call (no new Printer):\n";
    int trays2 = thePrinter().numTrays();
    cout << "      numTrays = " << trays2 << "\n";
}