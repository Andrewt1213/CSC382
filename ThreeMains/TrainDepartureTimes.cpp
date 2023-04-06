//
// Created by Andrew on 1/18/2023.
// This program will take in two train times and output the difference in
// time between the train times.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    cout << "Train A departs at:";
    int trainA;
    cin >> trainA;

    cout << "Train B departs at:";
    int trainB;
    cin >> trainB;

    int minutesA;
    minutesA = trainA / 100 * 60 + trainA % 100;
    int minutesB;
    minutesB = trainB / 100 * 60 + trainB % 100;

    int difference;
    difference = abs(minutesA - minutesB);

    cout << "Difference: " << difference / 60 << ":" << difference % 60;

    return 0;
}