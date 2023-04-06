#include <iostream>
#include "ArraySet.hpp"

int main() {
    ArraySet<int > set1 = {1, 2, 3};
    ArraySet<int > set2 = {0, 1, 2, 4, 5 ,6, 8};
    ArraySet<int > set3 = {1, 2, 545};

    set1.printSet();
    set2.printSet();
    set3.printSet();

    cout << "size: " << set1.size() << endl;

    ArraySet<int> unionSet = set1 << set2;

    unionSet.printSet();

    ArraySet<int> intersect = set1 >> set2;

    cout << endl;

    intersect.printSet();

    return 0;
}
