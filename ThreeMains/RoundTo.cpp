//
// Created by Andrew on 1/18/2023.
// This file takes in a number from the user and rounds it to
// the user-defined amt of decimal places.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Enter a number to round: ";
    double number; // declare one variable
    cin >> number;

    cout << "Enter number of decimal places: ";
    int decimal_places; // declare another variable
    cin >> decimal_places;

    cout << round(number * pow(10.0, decimal_places)) / pow(10.0, decimal_places) << '\n';

    return 0;
}