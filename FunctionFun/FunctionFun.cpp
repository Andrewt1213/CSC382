/*
This file has nine functions headings and specifications related to the fact that CSC 382
students are learning the C++ string type, reviewing writing functions to be tested with
the assert(bool) function in main.

You will need some function an M_PI from cmath and several different functions from <string>.

Many functions can be completed with just one return statement, but you could have more.

Programmers: Rick Mercer and Andrew Tapia
*/

#include <cmath>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

///////////////////////////////////////////////////////////////////////
double roundto(double x, int decimals) {
/*
Return the floating point number x rounded to decimals decimal places.
You will need cmath's round and pow functions
*/
    return round(x * pow(10.0, decimals)) / pow(10.0, decimals);
}


///////////////////////////////////////////////////////////////////////
double circle_area(double radius) {
/*
Return the area of a circle rounded to two decimal places of the given radius. You might have to
look up this formula on the web. You will need cmath's M_PI constant and the pow function
*/
    return roundto(M_PI * pow(radius, 2), 2);
}


///////////////////////////////////////////////////////////////////////
double projectile_range(double degrees, double velocity) {
/*
Complete this function so it returns the range of a projectile rounded
to two decimal places. Here is the formula:

  range = sin(2 * radians) * velocity**2 / 9.8

Since the input is degrees, we must convert degrees to radians for use in the
sin() function that expects radians, not degrees. Here is the formula:

  radians = degrees * math.pi / 180

You will need the constant the sin function and the M_PI constant from <cmath>.
You will also need to use your working roundto function to round to 2 decimal places.
*/
    double radians = degrees * M_PI / 180;
    double range = sin(2 * radians) * pow(velocity, 2) / 9.8;

    return roundto(range, 2);
}


///////////////////////////////////////////////////////////////////////
string anti_matter(const string &matter) {
/*
Everyone knows that interplanetary space travel systems are fueled by mixing matter and
anti-matter. Complete this function that will take a string with the name of some thing
or idea and return a string with "Anti-" prepended to it.

    anti_matter("lol") returns Anti-lol

you will need string concatenation with +'
*/
    return "Anti-" + matter;
}


///////////////////////////////////////////////////////////////////////
string abba(const string &a, const string &b) {
/*
Given two strings, a and b, return the result of putting them together in the
order abba, e.g. "Hi" and "Bye" returns "HiByeByeHi".

  abba("Hi", "Bye") returns "HiByeByeHi"
  abba("Yo", "Alice") returns "YoAliceAliceYo"

You will need string concatenation.
*/
    return a + b + b + a;
}


///////////////////////////////////////////////////////////////////////
// Precondition:  n < sequence.length()
std::string wrap(const string &sequence, int n) {
/*
Return a string that moves the first count words to the end of sequence

You will need the substr function from <cmath>

 wrap("abdee", 3) returns "eeabd"
 wrap("abdee", 2) returns "deeab"


*/
    string remaining_letters = sequence.substr(n);
    string taken_letters = sequence.substr(0, n);


    return remaining_letters + taken_letters;
}


///////////////////////////////////////////////////////////////////////
std::string make_tags(const string &tag, const string &word) {
/*
The web is built with HTML strings like "<i>Yay</i>" which draws Yay
as italic text. In this example, the "i" tag makes <i> and </i> which
surround the word "Yay". Given tag and word strings, create the HTML
string with tags around the word. For example,

make_tags("i", "italic") returns "<i>italic</i>
make_tags("b", "emboldened") returns "<b>emboldened</b>
</i>"

You will need string concatenation with +
*/

    return "<" + tag + ">" + word + "</" + tag + ">";
}


///////////////////////////////////////////////////////////////////////
// Precondition word.length() == 5 exactly, all the time. If not, this function won't work.
string in_lat(const string &word) {
/*
Aoccdrnig to a rscheearch at an Elingsh uinervtisy, it deosn"t mttaer
in waht oredr the ltteers in a wrod are, the olny iprmoetnt tihng
is taht frist and lsat ltteer is at the rghit pclae.

Create a function that will mix up the middle characters in a five letter
word. The precondition states the word must have exactly 5 letters.
If the argument is a different len, the function will not work.

Assuming the letters are indexed as 0-1-2-3-4, they should end up in
the order 0-3-2-1-4. Your function will accept a 5-character string as an
argument and return a 5-character string reordered as described.

in_lat("gears") returns "graes"
in_lat("prior") returns "poirr"
in_lat("scone") returns "snoce"
in_lat("apple") == "alppe")

You cannot use .at(int) or [int] because C++ thinks a string of length 1 is a char,
which C then turns into an integer. It appears this string function is returning an int
Instead, use substr or to_string.
*/
    return word.substr(0, 1) +
           word.substr(3, 1) +
           word.substr(2, 1) +
           word.substr(1, 1) +
           word.substr(4);
}


// Precondition: name must be in the format of a firstname, followed by a space, followed by one
// letter and a dot, followed by a space, followed by a last name, "Rick H. Mercer" for example.
void name_rearrange(string &name) {
    /*
     * Modify name to change the format form "Rick H. Mercer" to "Mercer, Rick H."
     *
     * You will need the string functions find and substr in addition to string concatenation.
     * Do not return anything from this function. Modify the parmeter so this assert passes:
     *  string t1 = "First M. Last";
     *  name_rearrange(t1); // change t1 inside this function
     *  assert(t1 == "Last, First M.");
     */
    string first_name = name.substr(0, name.find(" "));
    string middle_name = name.substr(name.find(" "), 3);
    string last_name = name.substr(name.find(".") + 2);
    name = last_name + ", " + first_name + middle_name;

}

int main() {

    // Test roundto(double x, int decimals) ------------------
    cout << roundto(5.67, 1) << endl;
    assert(roundto(2.4999999, 0) == 2);
    assert(roundto(2.5, 0) == 3);
    assert(roundto(2.56, 1) == 2.6);

    // Test for circle_area(radius) --------------------------
    assert(circle_area(1) == 3.14);

    // Test projectile_range ---------------------------------
    assert(projectile_range(45, 100) == 1020.41);

    // Test Anti_matter --------------------------------------
    assert(anti_matter("LOL") == "Anti-LOL");
    assert(anti_matter("anti") == "Anti-anti");
    assert(anti_matter("ABBBA") == "Anti-ABBBA");
    assert(anti_matter("") == "Anti-");

    // Test abba  --------------------------------------------
    assert(abba("Hi", "Bye") == "HiByeByeHi");
    assert(abba("A", "B") == "ABBA");
    assert(abba("", "") == "");

    // Test wrap ---------------------------------------------
    assert(wrap("XY", 1) == "YX");

    // Test make_tags  ---------------------------------------
    assert(make_tags("i", "italic") == "<i>italic</i>");

    // Test in_lat -------------------------------------------
    assert(in_lat("apple") == "alppe");
    assert (in_lat("Quick") + " " + in_lat("brown") + " " + in_lat("foxes")
            + " " + in_lat("jumps") == "Qciuk bworn fexos jpmus");

    // Test name_rearrange ----------------------------------
    string t1 = "First M. Last";
    // Modfiy t1 inside the function
    name_rearrange(t1);
    assert(t1 == "Last, First M.");

    return 0;
}