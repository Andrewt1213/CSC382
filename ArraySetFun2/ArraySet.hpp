//
// Implement a ArraySet class with << and >> overloaded for ArraySet
// union and intersection using a raw C array as the data member
//
// Authors Rick Mercer and Andrew Tapia
//

#ifndef ARRAYSETFUN2_ARRAYSET_HPP
#define ARRAYSETFUN2_ARRAYSET_HPP

#include <iostream>
#include <initializer_list>

using namespace std;

template<typename T>
class ArraySet {
private:
    // You must use a raw C array like T* data
    int n = 0; // number of elements
    T *elements; // the pointer to the array.
public:
    // Allow ArraySet objects to be constructed with universal initializers.
    // Add all elements in initialList while maintaining an ArraySet
    ArraySet(const std::initializer_list<T> &initialList) {
        elements = new T[100]; // dynamically allocates memory for array with room for 100 elements
        int i = 0;
        for (auto item: initialList) {
            elements[i] = item;
            i++;
            n++;
        }
    }

    void printSet() {
        cout << "Printing set..." << endl;
        for (int i = 0; i < n; i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }


    // To this class, add a destructor, a copy constructor, and overload the assignment operator

    // Add element to this ArraySet and increase the size by 1 if it isn't in
    // the set and return true. If element is present, return false.
    //
    // Precondition: size() < 100;  Do not grow the array.
    //
    bool insert(T const &element) {
        for (int i = 0; i < n; i++) {
            if (elements[i] == element) {
                return false;
            }
        }
        elements[n] = element;
        n++;
        return true;
    }

    // Return the number of data that are currently in this ArraySet
    int size() const {
        return n;
    }

    // Return true if value is in this set or false if not
    bool contains(T const &value) const {
        for (int i = 0; i < this->n; i++) {
            if (elements[i] == value) {
                return true;
            }
        }
        return false;
    }

    // Union
    // Return the union of two sets by overloading <<. The union of two sets A and B is the set
    // of elements which are in A, in B, or in both A and B. For example, if A = {1, 3, 5, 7} and
    // B = {1, 2, 4, 6} then A << B = {1, 2, 3, 4, 5, 6, 7}.
    //
    // Since we are in class ArraySet<T>, you can reference other.data in addition to this->data
    //
    // Usage: ArraySet<int> union = set1 << set2;
    //
    ArraySet<T> operator<<(const ArraySet<T> &other) const {
        ArraySet<int> unionSet = {};
        for (int i = 0; i < n; i++) {
            unionSet.insert(elements[i]);
        }
        for (int i = 0; i < other.n; i++) {
            if (!contains(other.elements[i])) {
                unionSet.insert(other.elements[i]);
            }
        }
        return unionSet;
    }

    // Intersection
    // Return the intersection of two sets by overloading >>. The intersection of two sets
    // A and B is the set of elements which are in both A and B. For example, if ArraySet<int>
    // A = {7, 1, 5, 3} and B = {6, 5, 4, 1, 7} then A >> B returns the ArraySet<int> {1, 7, 5}.
    //
    // Since we are in class ArraySet<T>, you can reference other.data in addition to this->data
    //
    // Usage: ArraySet<int> intersect = set1 >> set2;
    //
    ArraySet<T> operator>>(const ArraySet<T> &other) const {
        ArraySet<int> intersect = {};
        for (int i = 0; i < other.n; i++) {
            if (this->contains(other.elements[i])) {
                intersect.insert(other.elements[i]);
            }
        }
        return intersect;
    }

    ~ArraySet() {
        delete[] elements;
    }

    // deep copy on assignment, still super confusing.
    ArraySet &operator=(const ArraySet &other) {
        T *temp = new T[100];
        for (int i = 0; i < other.n; i++) {
            temp[i] = other.elements[i];
        }
        delete[] this->elements;
        this->elements = temp;
        this->n = other.n;
        return *this;
    }

    // Copy Constructor
    ArraySet(const ArraySet &other) {
        elements = new T[100]; // dynamically allocates memory for array with room for 100 elements
        for (int i = 0; i < other.n; i++) {
            elements[i] = other.elements[i];
        }
        this->n = other.n;
    }
};

#endif //ARRAYSETFUN2_ARRAYSET_HPP
