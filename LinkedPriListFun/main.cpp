#include <iostream>
#include "LinkedPriorityList.hpp"
#include <string>
using namespace std;
int main() {
    LinkedPriorityList<string> list;
    //cout << "sz: " << list.size() <<  endl;
    list.insertElementAt(0, "1st");
    //cout << "sz: " << list.size() <<  endl;
    list.insertElementAt(1, "2nd");
    //cout << "sz: " << list.size() <<  endl;
    list.insertElementAt(2, "3rd");
    //cout << "sz: " << list.size() <<  endl;
    list.printList();

    list.moveToTop(2);
    list.printList();



    return 0;
}
