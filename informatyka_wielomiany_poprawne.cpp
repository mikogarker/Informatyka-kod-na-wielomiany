#include <iostream>
#include "polynomian.h"
#include <vector>
using namespace std;

void entry() {
    cout << "Witam w programie co chcesz zrobic?\n";
    cout << "\n";
    cout << "dostac wartosci dla (a+b)^n | nacisnij 1\n";
    cout << "dostac wzor dla rownania o danym stopniu | nacinij 2 \n";
    cout << "dodac wielomiany | nacisnij 3\n";
    cout << "odjac wielomiany | nacisnij 4\n";
    cout << "pomnozyc wielomiany | nacisnij 5\n";
    cout << "policzyc interpolacje | nacisnij 6\n";
}

int main() {
    
    int level1, level2;
    vector<double> values1, values2;
    //wczytywanie danych
    cout << "podaj poziom pierwszego rownania: ";
    cin >> level1;
    cout << '\n' << "podaj poziom drugiego rownania: ";
    cin >> level2;
    cout << "podja wartosci pierwszego rownania: \n";
    for (int i = 0; i <= level1; i++) {
        float pom;
        if (i == level1)
            cout << "c=";
        else {
            cout << "x^" << level1 - i << "   x=";
        }
        cin >> pom, values1.push_back(pom);
    }
    cout << "podja wartosci drugiego rownania: \n";
    for (int i = 0; i <= level2; i++) {
        float pom;
        if (i == level2)
            cout << "c: ";
        else {
            cout << "x^" << level2 - i << "   x=";
        }
        cin >> pom, values2.push_back(pom);
    }
    reverse(values1.begin(), values1.end());
    reverse(values2.begin(), values2.end());
    //// wkładanie do struktu
    polynomial poly1{}, poly2{};
    poly1.level = level1+1;
    poly2.level = level2+1;
    poly1.values = &values1[0];
    poly2.values = &values2[0];
    ////dodawanie
    cout << "dodawanie: ";
    polynomial poly4 = add(poly1, poly2);
    for (int i = 0; i < get_level(poly4); i++) {
        if (i == 0) {
            cout << get_value(poly4,i);
        }
        else {
            cout << " + " << get_value(poly4, i) << "x^" << i;
        }
    }
    ////odejmowanie
    cout << '\n' << "odejmowanie: ";
    polynomial poly5 = subtract(poly1, poly2);
    for (int i = 0; i < get_level(poly5); i++) {
        if (i == 0) {
            cout << get_value(poly5, i);
        }
        else {
            cout << " + " << get_value(poly5, i) << "x^" << i;
        }
    }
    cout << '\n';
    ////mnozenie
    cout << "mnozenie: ";
    polynomial poly3 = multiply(poly1, poly2);
    for (int i = 0; i < get_level(poly3); i++) {
        cout << get_value(poly3, i) << "x^" << i << " + ";
    }
    cout << '\n';

    return 0;
}