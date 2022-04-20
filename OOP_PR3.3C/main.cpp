#include <iostream>
#include <stddef.h>
#include <stdio.h>
#include "Fraction.hpp"
#include "Object.hpp"

using namespace std;

int main() {

    Fraction n1;
    Read(n1);
    cout << "The number is ";
    Display(n1);
    
    Fraction n2(0, 0);
    Read(n2);

    Fraction n3(n2);
    cout << "The number is ";
    Display(n3);
    
    Fraction nsum;
    nsum = n1 + n3;
    cout << " Sum: ";
    Display(nsum);

    Fraction nmultiplication;
    nmultiplication = n1 * n3;
    cout << " Multiplication: ";
    Display(nmultiplication);
    cout << "Object count: " << n1.get_count() << endl;
    return 0;
}
