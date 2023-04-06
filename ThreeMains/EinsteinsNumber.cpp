//
// Created by Andrew on 1/18/2023.
// This file takes a 3 digit number from the user where the first and last digits differ by one
// or more and then reverses it, find the absolute difference between the reversed and original,
// finds the reverse of the difference and adds that to the original reversed to give 1089!
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    cout << "Enter a 3 digit number where the first and last digits differ by one or more: ";
    int number;
    cin >> number;
//(number%10)*100 + (number%100)/10* 10  + number/100
    cout << number << " -- original\n";
    int reversed;
    reversed = (number % 10) * 100 + (number % 100) / 10 * 10 + number / 100;
    cout << reversed << " -- reversed\n";
    int difference;
    difference = abs(number - reversed);
    cout << difference << " -- difference between original and reversed\n";
    reversed = (difference % 10) * 100 + (difference % 100) / 10 * 10 + difference / 100;
    cout << reversed << " -- reverse of differences\n";
    cout << difference + reversed << " -- difference + reverse of the difference\n";
    return 0;
}