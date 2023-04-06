//
// Created by Andrew on 1/26/2023.
//

#ifndef SELECTIONFUNFAST_SFUNS_H
#define SELECTIONFUNFAST_SFUNS_H

#include "SelectionFun1.cpp"

/*
 * This file has 6 functions related by the fact that CSC 382 students are reviewing C,
 * functions, and selection algorithmic patterns such as Guarded Selection, Alternative
 * Selection, and Multiple Selection with C++. The C++ string type, new to some students,
 * is needed to complete this Assignment.
 *
 * The functions specifically use the if and if..else statements written in virtually all
 * languages because these algorithmic patterns occur so frequently while developing software.
 *
 * Programmers: Rick Mercer and Andrew Tapia
 */
#include <string>
using namespace std;

/* Return the std::string "Monday" if the int argument
passed to the parameter dayNumber is 1.
return "Unknown" if the argument is not 1 through 7
return "Tuesday" if the argument 2 and so on up
through returning "Sunday" if argument == 7
dayOfWeek(0) returns "Unknown"
dayOfWeek(3) returns "Wednesday"
*/
string dayOfWeek (int day) {
    if(day == 1)
        return "Monday";
    if(day == 2)
        return "Tuesday";
    if(day == 3)
        return "Wednesday";
    if(day == 4)
        return "Thursday";
    if(day == 5)
        return "Friday";
    if(day == 6)
        return "Saturday";
    if (day == 7)
        return "Sunday";
    return "Unknown";
}

// Complete the function salary that returns a salesperson’s salary
// for the month according to the following policy:
//
// Sales . . But
// .Over . . Not Over . . Monthly Salary
// ======= . ======== . . ==============
// 0 . . . . 10,000 . . . Base salary = $1,500
// 10,000 .. 20,000 . . . Base salary plus 5% of sales over 10,000
// 20,000 .. 30,000 . . . Base salary plus 500.00 plus 8% of sales over 20,000
// 30,000 .. . . . . . .. Base salary plus 1300.00 plus 12% of sales over 30,000
//
// The base salary is $1,500.00, which means salary returns a value that
// is never less than 1500.00. When sales are over $10,000, commission is
// added to the base salary. For example, when sales equals 10001, the
// monthly salary is $1,500.00 + 5% of $1.00 for a total of $1,500.05,
// and when sales is 20001, the monthly salary is $1,500.00 + $500.00 + 8%
// of $1.00 for a total of $2,000.08.
//
// Precondition sales >= 0.0
//
double salary(double sales) {
    if (sales >= 30000) {
        return 2800 + (sales-30000)*0.12;
    }
    else if(sales >= 20000){
        return 2000 + (sales-20000)*0.08;
    }
    else if(sales >= 10000) {
        return 1500 + (sales - 10000) * 0.05;
    }
    return 1500;
}


// You are given three string arguments. Return the string that alphabetically
// precedes or is equal to the other two string arguments
//
// string("a", "b", "c") returns "a"
// string("X", "b", "c") returns "X"
// string("123", "1232", "123 0") returns "123"
//
// Use the ascii character set where  "A" < "a" and "1" < "A"
//
string firstOf3(string const &a, string const &b, string const &c) {
    // TODO: Complete this function
    return "Under construction";
}



// You are given a string str.
// If the string begins with "f" return "Fizz".
// If the string ends with "b" return "Buzz".
// If both the "f" and "b" conditions are true, return "FizzBuzz".
// If neither the "f" and "b" conditions are true, return the string unchanged.
//
// fizzBuzz("fig") returns "Fizz"
// fizzBuzz("dib") returns "Buzz"
// fizzBuzz("fib") returns "FizzBuzz"
// fizzBuzz("abc") returns "abc"
string fizzBuzz(string const &str) {
    if (str.length() > 0){
        if (str.at(0) == 'f'){
            if (str.at(str.length() - 1) == 'b') {
                return "FizzBuzz";
            }
            else {
                return "Fizz";
            }
        }
        if (str.at(str.length() - 1) == 'b'){
            return "Buzz";
        }
    }
    return str;
}



// Complete the free function isLeapYear that returns true if the integer
// argument represents a leap year in which February has 29 days instead of 28 days.
// This is done because there are actually close to 365.25 days on a year. A leap year
// is a year after 1582 that is evenly divisible (no remainder after division) by 4
// unless it is the end of a century. In this case, where the year is also evenly
// divisible by 100—year must also be divisible by 400. For example, 2000 and 2400
// are leap years but 1900 2100 are not. Let leapYear return true if the argument
// represents a leap year or false if it's not.
//
//  isLeapYear(2024) returns true
//  isLeapYear(2100) returns false
//  isLeapYear(2400) returns true
//
//  Precondition: year > 1582
//
bool isLeapYear(int year) {
    if (year > 1582) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return year % 4 == 0;
    }
    return false;
}


// Complete function dayNumber to return how many days a valid date is into the year.
//
// dayNumber("01/03/2016") returns 3
// dayNumber("12/31/2023") returns 365
// dayNumber("12/31/2024") returns 366
//
// Important precondition: The argument must in the format of MM/DD/YYYY"
// where two forward slashes must be at indexes 3 and 6 and M, D, and Y must
// be one of the digits 0..9 so "2019/02/01" and "1/9/2022" are not allowed.
//
// Don't error check. We will not have any REQUIRE that violates any precondition!
//
//  std::stoi("12") returns 12
//
// Precondtion: date is a vaild date. "13/32/-123" is wrong is three places
int dayNumber(string const &date) {
    int days = 0;
    int months = stoi(date.substr(0, 2));
    if (months == 12) {days = 334;}
    else if (months == 11) {days = 304;}
    else if (months == 10) {days = 273;}
    else if (months == 9) {days = 243;}
    else if (months == 8) {days = 212;}
    else if (months == 7) {days = 181;}
    else if (months == 6) {days = 151;}
    else if (months == 5) {days = 120;}
    else if (months == 4) {days = 90;}
    else if (months == 3) {days = 59;}
    else if (months == 2) {days = 31;}
    else if (months == 1) {days = 0;}

    days = days + stoi(date.substr(3, 2));
    if (isLeapYear(stoi(date.substr(6, 4)))){ days+=1;}
    return days;
}


bool validDate(string const &date)  // TODO: Complete this function
    return not true and not false;
}


#endif //SELECTIONFUNFAST_SFUNS_H
