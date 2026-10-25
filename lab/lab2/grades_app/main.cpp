#include <iostream>
#include "grades.h"

using namespace std;

int main()
{
    double a, b, c;

    cout << "Enter 3 grades: ";
    cin >> a >> b >> c;

    double averageGrade = calculateAverageGrade(a, b, c);
    cout << "Average grade: " << averageGrade << endl;

    if (isPassing(averageGrade))
    {
        cout << "Passed!" << endl;
    }
    else
    {
        cout << "Failed!" << endl;
    }

    return 0;
}