#include "grades.h"

double calculateAverageGrade(double a, double b, double c)
{
    return (a + b + c) / 3;
}

bool isPassing(double grade)
{
    return grade >= 5;
}