/*
 * VectorFun.hpp
 *
 * This cpp file will implement ten functions related by the fact that CSC 382
 * students are learning how to do vector processing and use and write template
 * functions. There are several silly contrived methods, some actually helpful
 * like FizzBuzz, a question asked in job interviews that 90% of graduates can't do.
 *
 * @Programmers Rick Mercer and Andrew Tapia
 */
#ifndef SRC_VECTORFUN_HPP_
#define SRC_VECTORFUN_HPP_

#include <string>
#include <vector>

using namespace std;

// Completely write template function numberOfPairs, including
// the function heading, to return the number of times a pair
// occurs in vec. A pair is any two elements that are equal at
// consecutive vector indexes. The vector may be empty or have
// only one element. In both of these cases, return 0.
//
//    vector<int> v1{1, 2, 3, 2, 1};
//    numberOfPairs(v1)) returns 0
//
//    vector<string> v2{"a", "b", "b", "b"};
//    numberOfPairs(v2)) returns 2
//
// Precondition T must overload ==
template<typename T>
int numberOfPairs(vector<T> &vec) {
    int number_of_pairs = 0;
    // Empty case and 1 item case.
    if (vec.size() < 2) {
        return 0;
    }
    // Case for 2+ items
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec.at(i) == vec.at(i + 1)) {
            number_of_pairs++;
        }
    }
    return number_of_pairs;

}


// Complete method shiftOnce so vec "left shifted" one time
// so shiftNTimes({6, 2, 5, 3}, 1) changes the vector
// argument to {2, 5, 3, 6} and shiftNTimes({6, 2, 5, 3}, 2)
// changes the array argument to {5, 3, 6, 2}. You must
// modify the vector argument by changing the parameter
// array inside method shiftNTimes. Remember, a change to
// the parameter inside the method shiftNTimes changes
// the argument inside the test function.
//
// Modify the argument by modifying vec. Do NOT use a return statement.
//
template<typename T>
void shiftOnce(vector<T> &vec) {
    if (vec.size() > 0) {
        T first_item = vec.at(0);
        int i;
        for (i = 1; i < vec.size(); i++) {
            vec.at(i - 1) = vec.at(i);
        }
        vec.at(i - 1) = first_item;
    }
}


// Complete method shiftNTimes so vec "left shifted" n times. For
// example, shiftNTimes({6, 2, 5, 3}, 1) changes the vector argument
// to {2, 5, 3, 6} and shiftNTimes({6, 2, 5, 3}, 2) changes the vector
// argument to {5, 3, 6, 2}. You must modify the vector argument by
// changing the parameter array inside method shiftNTimes. Remember,
// a change to the parameter inside the method shiftNTimes changes
// the argument inside the test function
//
// shiftNTimes( { 1, 2, 3, 4, 5, 6, 7 }, 3 )
// modifies the argument to { 4, 5, 6, 7, 1, 2, 3 }
//
// shiftNTimes( { 1, 2, 3, 4, 5, 6, 7 }, 0 ) modifies nothing
//
// shiftNTimes( { "A", "B", "C" }, 5) modifies the vector argument
// to { "C", "A", "B" }
//
// shiftNTimes( { 3 }, 5) modifies the vector argument to { 3 }
//
// Modify the argument by modifying vec. Do NOT use a return statement.
template<typename T>
void shiftNTimes(vector<T> &vec, int numShifts) {
    for (int i = 0; i < numShifts; i++) {
        shiftOnce(vec);
    }
}


// Given a filled vector of double elements, return true if
// the sum of all elements is greater than sum. Sum may be
// negative. An empty vector's sum is zero.
//
// sumGreaterThan( { 1.1, 2.2, 3.3 }, 4.0) returns true
// sumGreaterThan( { 1.1, 2.2, 3.3 }, 6.6) returns false
// sumGreaterThan( { }, -1.0) returns true
//
bool sumGreaterThan(vector<double> const &numbers, double sum) {
    double sum_of_doubles = 0;
    for (int i = 0; i < numbers.size(); i++) {
        sum_of_doubles += numbers.at(i);
    }
    return sum_of_doubles > sum;
}

// Complete method howMany to return the number of elements in a
// vector of strings that equals valueToFind. The vector may be empty.
//
// howMany({"A", "a", "A", "a" }, "A") returns 2
// howMany({"And", "there", "goes", "another"}, "another") returns 1
// howMany({"And", "there", "goes", "another"}, "Not Here") returns 0
// howMany({ }, "empty array") returns 0
//
int howMany(vector<string> const &array, string const &valueToFind) {
    int number_found = 0;
    for (int i = 0; i < array.size(); i++) {
        if (array.at(i) == valueToFind) {
            number_found++;
        }
    }
    return number_found;
}

// Given a vector containing a stream of integers in the
// range of 0..10 (like quiz scores), return an array of 11
// integers where the first value (at index 0) is the number
// of 0s in the vector, the second value (at index 1) is the
// number of ones on the vector, and the 11th value
// (at index 10) is the number of tens in the vector.
// The following assertions must pass.
//
// Given the argument vector<int> arg {5,0,7,7,7,9,9,5,8,10};,
// frequency must return a vector that looks like this
// {1,0,0,0,0,2,0,3,1,2,1}
//
// Precondition: The vector argument has elements always in the range of 0..10 only.
vector<int> frequency(vector<int> const &vec) {
    vector<int> freq_vector{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < vec.size(); i++) {
        freq_vector.at(vec.at(i))++;
    }
    return freq_vector;
}


// Modify the argument reference by with vec so it still
// contains the exact same numbers as the given array but
// rearranged so that all the even numbers come before all
// the odd numbers. Other than that, the ints can be in
// any order. You must modify the vector argument vec by
// changing array in method evensLeft. The array may be
// empty or have only one element so no change should be made.
//
// Original vector           Modified vector
// {1, 0, 1, 0, 0, 1, 1}     { 0, 0, 0, 1, 1, 1, 1 }
// {3, 3, 2}                 { 2, 3, 3 }
// {3, -2, -2}               { -2, -2, 3}
//
// vec Must be a reference parameter with & so changes made here
// are made to the argument vec is referencing in the unit test.
//
// Modify the argument by modifying vec. Do NOT use a return statement
void evensLeft(vector<int> &vec) {
    vector<int> temp = {};
    int i = 0;
    while (i < vec.size()) {
        if (vec.at(i) % 2 == 0) {
            temp.push_back(vec.at(i));
        }
        i++;
    }
    i = 0;
    while (i < vec.size()) {
        if (vec.at(i) % 2 != 0) {
            temp.push_back(vec.at(i));
        }
        i++;
    }
    i = 0;
    while (i < vec.size()) {
        vec.at(i) = temp.at(i);
        i++;
    }
}


// Return the range of the numbers in an array[].
// The range is the maximum value - minimum value
//
// range ({1, 2, 3, 4}) returns 4 - 1 or 3
// range ({1, 2, -3, 4}) returns 4 - -3 or 7
// range ({ 99 }) returns 0
//
// Precondition: x.length >= 1
int range(vector<int> const &x) {
    int max = 0;
    int min = 0;
    if (x.size() > 0) {
        max = x.at(0);
        min = x.at(0);
    }
    int i = 0;
    while (i < x.size()) {
        if (x.at(i) < min) {
            min = x.at(i);
        }
        if (x.at(i) > max) {
            max = x.at(i);
        }
        i++;
    }
    return max - min;
}

// Consider the series of numbers beginning at start and running
// up to but not including end, so for example start=1 and end=5
// gives the series 1, 2, 3, 4. Return a new vector<std:string>
// containing the string form of these numbers. However for
// multiples of 3, store "Fizz" instead of the number. For
// multiples of 5 use "Buzz". For multiples of both 3 and 5
// use "FizzBuzz". In C++, to_string will make a str::string
// from an int, to_string(12) returns the string literal "12".
//
// fizzBuzz(1, 6) returns ["1", "2", "Fizz", "4", "Buzz"]
// fizzBuzz(1, 8) returns ["1", "2", "Fizz", "4", "Buzz", "Fizz", "7"]
// fizzBuzz(14, 21) returns ["14", "FizzBuzz", "16", "17", "Fizz", "19"]
//
// Precondition: end > start so the return so vector's size() >= 1
vector<string> fizzBuzz(unsigned long &&start, unsigned long &&end) {
    vector<string> return_vector{};
    int current_num = start;
    while (current_num < end) {
        if (current_num % 3 == 0) {
            if (current_num % 5 == 0) {
                return_vector.push_back("FizzBuzz");
            } else {
                return_vector.push_back("Fizz");
            }
        } else if (current_num % 5 == 0) {
            return_vector.push_back("Buzz");
        } else {
            return_vector.push_back(to_string(current_num));
        }
        current_num++;
    }
    return return_vector;
}

#endif // SRC_VECTORFUN_HPP_