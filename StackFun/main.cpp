#include <iostream>
#include "stacks.hpp"

int main() {
    LinkedStack<int> *pAbs = new LinkedStack<int>;
    cout << pAbs->isEmpty() <<endl;
    pAbs->push(10);
    pAbs->push(11);
    pAbs->push(12);
    pAbs->push(22);
    cout << pAbs->isEmpty() << endl;
    cout << pAbs->top() << endl;
    cout << pAbs->pop() << endl;
    cout << pAbs->top() << endl;
    return 0;
}
