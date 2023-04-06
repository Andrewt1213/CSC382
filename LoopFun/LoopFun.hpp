//
// Created by Richard H. Mercer on 9/6/22.
//
// Author: Andrew Tapia

/*
 * AlgorithmicPatterns.cpp
 *
 * LoopFun.cpp contains twelve free functions all of which require a while or a for loop.
 * Do NOT use recursion!
 *
 * Programmer Rick Mercer and Andrew Tapia
 */
#ifndef LOOPFUN_HPP_
#define LOOPFUN_HPP_

#include <string>
#include<cmath>

using namespace std;

// bool isPrime(int)
//
// One evening, while listening intently at the Very Large Array (VLA)
// radio astronomy observatory 50 miles west of Socorro New Mexico, Ellie
// hears a powerful signal: a prime number pattern emanating from the
// star Vega, confirmed by others the world over, undeniable and strong
// in its pulsing power. What Ellie recognized was the repeating series
// of the first 26 prime numbers. This is someone near Vega trying to
// contact anyone who is listening:
//
//  2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
//
// A prime number is a natural number greater than 1 that has no positive
// divisors other than 1 and itself. Complete function isPrime that returns
// true if the argument is a prime number. Hint: Consider writing a loop
// that divides the argument num by every integer from 2 to num-1, returning
// false if num was found to be evenly divisible by any one of those.
//
bool isPrime(int num) {
    int divisor = num - 1;
    while (divisor > 1) {
        if (num % divisor == 0) { return false; }
        divisor -= 1;
    }
    return true;
}


// fibonacci(int)
//
// In the movie "The Da Vinci Code" with Tom Hanks, this password
// used to unlock a much sought after artifact: 1 2 3 5 8 13 21.
// These are the 2nd through 8th Fibonacci numbers. Fibonacci numbers
// have so much interest, there exists a Fibonacci Quarterly
//
//   http://www.fq.math.ca/
//
// Implement function fibonacci that returns the nth Fibonacci number.
// Fibonnaci numbers can be computed as the sum of the preceeding two.
// You will find it useful to keep track the two previous Fibonacci
// numbers. This is harder than it looks.
//
//  fibonacci(1) returns 1
//  fibonacci(2) returns 1
//  fibonacci(3) returns 2
//  fibonacci(4) returns 3
//  fibonacci(5) returns 5
//  fibonacci(6) returns 8
//
// Precondition: n >= 1
int fibonacci(int n) {
    int previous_num = 1;
    int current_num = 1;
    int i = 2;
    int temp;
    while (i < n) {
        temp = current_num;
        current_num = previous_num + current_num;
        previous_num = temp;
        i++;
    }
    return current_num;
}

// int factorial(int)
//
// Given an integer argument return n factorial, which is written as n!.
// 5! = 5*4*3*2*1 or in general, n! = n*(n-1)*(n-2) …*2*1. Use a for loop.
//
// factorial(0) returns 1
// factorial(1) returns 1
// factorial(2) returns 2, which is 2 * 1
// factorial(3) returns 6, which is 3 * 2 * 1
// factorial(4) returns 24, which is 4 * 3 * 2 * 1
//
// Precondition: n >= 0
//
int factorial(int n) {
    int return_value = 1;
    while (n > 0) {
        return_value = return_value * n;
        n--;
    }
    return return_value;
}


// 4) vowelCount
//
// "How much wood could a woodchuck chuck" contains 11 vowels.  How do we
// know? Five of the 26 English alphabet letters are vowels: a, e, i, o,
// and u. By looking at each letter in the woodchuck string, we find
// 11 vowels. Complete function vowelCount that returns the number of vowels
// in the given std::string argument. This is case insensitive. Upper and lower
// case vowels count. We do not consider y to be a vowel.
//
// vowelCount("a e i o u A E I O U") returns 10
// vowelCount("y+_x1Y2x!y") returns 0
//
int vowelCount(std::string str) {
    int counter = 0;
    for (int i = 0; i < str.length(); i++) {
        if (tolower(str.at(i)) == 'a' or tolower(str.at(i)) == 'e'
            or tolower(str.at(i)) == 'i' or tolower(str.at(i)) == 'o' or tolower(str.at(i)) == 'u') {
            counter++;
        }
    }
    return counter;
}


// 5) numberOfPairs
//
// Return the number of times two consecutive characters occur in str.
//
//   numberOfPairs ("") returns 0
//   numberOfPairs ("abc") returns 0
//   numberOfPairs ("aabbcc") returns 3
//   numberOfPairs ("!!!") returns 2
//   numberOfPairs ("mmmm") returns 3
//   numberOfPairs ("mmOmm") returns 2
//
int numberOfPairs(std::string str);

int numberOfPairs(std::string str) {
    int counter = 0;
    int i = 1;
    char previous_letter;
    char current_letter;
    if (str.length() > 0) {
        previous_letter = str.at(0);
    }
    while (i < str.length()) {
        current_letter = str.at(i);
        if (current_letter == previous_letter) {
            counter++;
        }
        previous_letter = current_letter;
        i++;
    }
    return counter;
}


// 6) howSwedish
//
// ABBA is a band, they have many songs including Dancing Queen, and
// Fernando. ABBA is actually a Swedish band, so if we wanted to find
// out howSwedish a std::string is, we could simply find out how many times
// the std::string contains the std::string "abba".  We want to look for this
// str::string in a case insensitive manner. So "abba" counts, and so
// does "aBbA". We also want to check for overlapping abba's such as
// in the std::string "abbAbba" that contains "abba" twice.
//
//  howSwedish("") returns 0
//  howSwedish("ABB") returns 0
//  howSwedish("AbBa") returns 1
//  howSwedish("AbBa a B b a") returns 1
//  howSwedish("!abbABba!") returns 2
//  howSwedish("abbAbba") returns 2
//
int howSwedish(std::string str) {
    int counter = 0;
    int i = 0;
    while (i < str.length()) {
        if (tolower(str.at(i)) == 'a') {
            if (i + 1 < str.length() and ::towlower(str.at(i + 1)) == 'b') {
                if (i + 2 < str.length() and ::towlower(str.at(i + 2)) == 'b') {
                    if (i + 3 < str.length() and ::towlower(str.at(i + 3)) == 'a') {
                        counter++;
                    }
                }
            }
        }
        i++;
    }
    return counter;
}


// 7) allAsLeft
//
// Given a String, return the same characters in the std::string in the same
// order except all upper case 'A's are to the left.
//
//  allAsLeft("") returns ""
//  allAsLeft("A") returns "A"
//  allAsLeft("G") returns "G"
//  allAsLeft("AB") returns "AB"
//  allAsLeft("BA") returns "AB"
//  allAsLeft("ABCaDEFGaA") returns "AABCaDEFGa";
//
string allAsLeft(string str) {
    int i = 0;
    string return_string = "";
    while (i < str.length()) {
        if (str.at(i) == 'A') {
            return_string = return_string + "A";
        }
        i++;
    }
    i = 0;
    while (i < str.length()) {
        if (str.at(i) != 'A') {
            return_string = return_string + str.at(i);
        }
        i++;
    }
    return return_string;
}

// 8) bool isSorted(string)
//
// Given a String, return true if the characters are in ascending order.
// Note:  'a' < 'b' and  '5' < '8'
//
//   isSorted("") returns true
//   isSorted("a") returns true
//   isSorted("abbcddef") returns true
//   isSorted("123456") returns true
//   isSorted("12321") returns false
//
bool isSorted(string str) {
    if (str.length() > 0) {
        char previous_letter = str.at(0);
        for (int i = 1; i < str.length(); i++) {
            if (str.at(i) < previous_letter) {
                return false;
            }
            previous_letter = str.at(i);
        }
    }
    return true;
}


// 9) string mirrorEnds(string)
//
// Given a string, look for a mirror image (backwards) string at both the beginning
// and end of the given string. In other words, zero or more characters at the very
// beginning of the given string, and at the very end of the string in reverse order
// (possibly overlapping). For example, the string "abXYZba" has the mirror end "ab".
//
// mirrorEnds("abXYZba") return "ab"
// mirrorEnds("abca") returns "a"
// mirrorEnds("aba") returns "aba"
//
string mirrorEnds(string str) {
    string return_string = "";
    int left_index = 0;
    int right_index = str.length() - 1;
    while (left_index <= right_index) {
        if (str.at(left_index) == str.at(right_index)) {
            return_string += str.at(left_index);
            if (left_index == right_index) {
                return str;
            }
        } else {
            return return_string;
        }
        left_index++;
        right_index--;
    }

    return return_string;
}


// 10) string starOut(string)
//
// Return a version of the given string, where for every star (*) in the string
// the star and the chars immediately to its left and right are gone.
// So "ab*cd" yields "ad" and "ab**cd" also yields "ad".
//
//starOut("ab*cd") returns "ad"
//starOut("ab**cd") returns "ad"
//starOut("sm*eilly") returns "silly"
//
string starOut(string str) {
    string return_string = "";
    for (int i = 0; i <= str.length() - 1; i++) {
        if (i < str.length()) {
            if (str.at(i) == '*') {
                int j = i;
                while (i < str.length() and str.at(i) == '*') {
                    i++;
                }
                return_string = return_string.substr(0, j - 1);
            } else {
                return_string = return_string + str.at(i);
            }
        }
    }
    return return_string;
}

// 11) int GCD(int, int)
//
// In mathematics, the greatest common divisor (GCD) of two or more
// integers, which are not all zero, is the largest positive integer
// that divides each of the integers. For example, GCD(2, 12) is 4.
//
// Euclid's solution to finding the GCD is refuted to be the first
// algorithm known to mankind. It is definitely old.
//
// GCD(a, b) can be computed as follows:
//
// while(b != 0):
// .. other = a
// .. a = b
// .. b = other % b
// a is the GCD
//
// GCD(378, 378) returns 378
// GCD(378, 0) returns 378
// GCD(0, 378) returns 378
// GCD(3, 2) returns 1
// GCD(10, 5) returns 5
// GCD(15, 25) returns 5
// GCD(25, 10) returns 5
// GCD(-25, 10) returns 5
// GCD(-25, -10) returns 5
// GCD(25, -10) returns 5
//
// Either argument may be < 0
//
// Precondition: a and or b can be 0, but not both
// GCD(0, 0) is undefined. We do not have an assert for GCD(0,0).
//
int GCD(int a, int b) {
    a = abs(a);
    b = abs(b);
    int other;
    while (b != 0) {
        other = a;
        a = b;
        b = other % b;
    }
    return a;
}

// 12) double square_root(double, double)
//
// The square root of a number >= 0 can be found by making successful
// guesses until it is "close enough". Starting with a guess, make each
// guess like this until the square_root(x) is within the precision specified.
//
// n = 0
// guess[n] = x / 2 // A good first guess is to divide x by 2.0
// guess[n+1] = ( guess[n] + x / guess[n] ) / 2.0
// guess[n+2] = ( guess[n+1] + x / guess[n+1] ) / 2.0
//
// If x = 16.0
// guess[0] = 16.0 / 2; == 8.0
// guess[1] = (8.0 + 16.0 / 8.0) / 2.0 == 5.0
// guess[2] = (5.0 + 16.0 / 5.0) / 2.0 == 4.1
//
// Precondition x >= 0.0 and precision <= 1e-10
//
double square_root(double x, double precision) {
    double guess = x / 2;
    double difference = ::abs(sqrt(x) - guess);
    while (difference > precision) {
        guess = (guess + (x / guess)) / 2;
        difference = ::abs(sqrt(x) - guess);
    }
    return guess;
}

#endif
