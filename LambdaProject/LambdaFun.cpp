/* Implement all six functions using STL algorithms. Most functions are only one
 * line of code, even evensLeft. Please read the comments to understand that you
 * must use the specified STL algorithm and a lambda as a 3rd argument. All six
 * functions assume the vector<T> argument is not empty(). Do not make any function
 * work for empty vectors. We will not test for empty vectors either.
 *
 * Programmer: Andrew Tapia
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function allEven returns true if the vector<int> argument has all even integers.
// Return false if there are one or more odd integers. You must use std::all_of.
// You must use a lambda as the 3rd argument to std::all_of.
//
// Precondition nums.size() >= 1
bool allEven(const vector<int> & nums){
    return all_of(nums.begin(), nums.end(), [](int n) {return n %2 == 0;});
}


// Function allPositive returns true if the vector<int> argument has all positive
// integers or 0s. An empty vector You must use std::any_of. You must use a lambda
// as the 3rd argument to std::all_of.
//
// Precondition nums.size() >= 1
bool allPositive(const vector<int> & nums) {
    return all_of(nums.begin(), nums.end(), [](int n) {return n >= 0;});
}

// Template function hasNoneOfThese returns true if the vector<T> argument does not
// have any values equal to the 2nd argument of type T.  This should work with any
// type that overrides the == operator such as string, integer, and double. You must
// use std::none_of. You must use a lambda as the 3rd argument to std::none_of.
//
// Precondition nums.size() >= 1
template <class T>
bool hasNoneOfThese(const vector<T> & nums, T value) {
    return none_of(nums.begin(), nums.end(), [&value](T &n) {return n == value;});;
}

// Function cleanVector takes a vector<int> argument to create a new vector<int> that
// only has all integers in the range of [0..100]. Use std:: copy_if so no negatives or
// integers > 100 are in the return vector<int>. You will have to resize the new vector
// before it is returned. You will need the vector resize function and std::distance.
// The following TEST_CASE must pass:
//
// TEST_CASE("using count_if()") {
//   vector<int> tests = {-5, 89, 0, -1, 99, 101};
//   vector<int> result = cleanVector(tests);
//   REQUIRE(result.size() == 3);
//   REQUIRE(result[0] == 89);
//   REQUIRE(result[1] == 0);
//   REQUIRE(result[2] == 99);
// }
//
// Precondition tests.size() >= 1
vector<int> cleanVector(const vector<int> & tests) {
    vector<int> return_vector(tests.size());
    auto it = copy_if (tests.begin(), tests.end(), return_vector.begin(), [](int i){return (i>=0 && i <=100);} );
    return_vector.resize(distance(return_vector.begin(), it));
    return return_vector;
}

// Template function change() takes a vector<t> argument and "increments" the 2nd argument
// of type T to every vector element using the += operator. It should work on vectors
// of int, double, and string. You must use std::for_each(). You must use a lambda as
// the 3rd argument to std::for_each().
//
// Preconditions: Type T must have += defined and vec.size() >= 1
template <class T>
void change(vector<T> & vec, T inc) {
    for_each(vec.begin(), vec.end(), [&inc](T &num){
        num = num + inc;
    });
}

// Function evensLeft() modifies the vector<int> argument such that all the even integers
// comes before all the odd integers. For example, evensLeft({1, 0, 1, 0, 0, 1, 1}) changes
// the argument in the function call to {0, 0, 0, 1, 1, 1, 1} and  evensLeft({3, 3, 2})
// changes the argument to {2, 3, 3}. You must use std::partition(). You must use a lambda
// as the 3rd argument to std::partition(). The following TEST_CASE must pass:
//
// TEST_CASE("using partition()") {
//   vector<int> nums = {0, 1, 2, 3, 4, 5, 6};
//   evensLeft(nums);
//   for(auto itr = nums.begin(); itr != nums.end() - 3; itr++) {
//     REQUIRE(*itr % 2 == 0);
//   }
//
//   for(auto itr = nums.begin()+4; itr != nums.end(); itr++) {
//     REQUIRE(*itr % 2 != 0);
//   }
// }
//
// Note: This function can be implemented in one line of code.
//
// Precondition v.size() >= 1
void evensLeft (vector<int> & v) {
    partition(v.begin(), v.end(), [](int i){ return (i % 2 == 0); });
}