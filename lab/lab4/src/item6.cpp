#include "../inc/item6.hpp"
#include <iostream>
#include <type_traits>
using namespace std;

void item6()
{
    cout << "\nITEM 6: forbid copying\n";

    Apartment h1;
    Apartment h2;
    (void)h1;
    (void)h2;
    // Apartment h3(h1);   // error: use of deleted function
    // h1 = h2;            // error: use of deleted function

    cout << "\n   can copy / can assign (0 = forbidden):\n";
    cout << "      Apartment (= delete):       " << is_copy_constructible<Apartment>::value
         << " / " << is_copy_assignable<Apartment>::value << "\n";
    cout << "      Apartment98 (private):      " << is_copy_constructible<Apartment98>::value
         << " / " << is_copy_assignable<Apartment98>::value << "\n";
    cout << "      ApartmentBase (Uncopyable): " << is_copy_constructible<ApartmentBase>::value
         << " / " << is_copy_assignable<ApartmentBase>::value << "\n";
}