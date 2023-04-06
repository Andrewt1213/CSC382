/*
 * LinkedPriorityList.cpp
 *
 *  Author: Rick Mercer and Andrew Tapia
 *
 * This class describes one implementation of the abstract base class PriorityList.
 * Like any container, there are insert and remove functions.  Indexes represent
 * priorities and the elements priorities can change in several ways. The element at
 * index 0 has the highest priority, the element at size()-1 has the lowest priority.
 */
#include "PriorityList.h"
#include <stdexcept> // for std::invalid_argument(string)
#include <memory>    // for std::shared_ptr<T>
#include <string>

using namespace std;

template<class Type>
class LinkedPriorityList : public PriorityList<Type> {

private:
    // Add struct Node here.  Use std:shared_ptr
    struct Node {
        Type data;
        shared_ptr<Node> next;

        Node(Type element, shared_ptr<Node> nextRef) {
            data = element;
            next = nextRef;
        }
    };

    // Add other data members here
    int numElements;
    shared_ptr<Node> head = nullptr;
public:

    // Create an empty list with zero elements
    LinkedPriorityList() {
        numElements = 0;
    }


    // Return the number of elements currently in this PriorityList
    int size() const override {
        return numElements;
    }

    // Return true if there are zero elements in this PriorityList
    bool isEmpty() const override {
        return numElements == 0;
    }

    // If possible, return a reference to the element at the given index. If the
    // index is out of range, throw an invalid_argument exception.
    // When size is 2, the only possible indexes are 0 or 1.
    Type getElementAt(int index) const override {
        if (index < 0 || index > size()) {
            throw invalid_argument("In getElementAt, index was " + to_string(index));
        }
        shared_ptr<Node> temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    /*
   * If possible, insert the element at the given index. If index is out
   * of the valid range of 0..size(), throw new IllegalArgumentException();
   * When size is 3, the only possible values for index are 0, 1, 2, AND 3
   * because you can add an element as the new last.
   */
    void insertElementAt(int index, const Type &el) override {
        if (index < 0 || index > size()) {
            throw invalid_argument("In insertElementAt, index was " + to_string(index));
        }
        if (index == 0) {
            if (head == nullptr) {
                head = shared_ptr<Node>{new Node(el, nullptr)};
            } else {
                head = shared_ptr<Node>{new Node(el, head)};
            }
        } else {
            shared_ptr<Node> prev = head;
            int prev_index = index - 1;
            for (int i = 0; i < prev_index; i++) {
                prev = prev->next;
            }
            prev->next = shared_ptr<Node>{new Node(el, prev->next)};
        }
        numElements++;
    }

    // If possible, remove the element at the given index.
    // If the index is out of  range, throw an invalid_argument exception.
    // When size is 3, the only possible insertion locations are 0, 1, and 2.
    void removeElementAt(int index) override {
        if (index < 0 || index >= size()) {
            throw invalid_argument("In removeElementAt, index was " + to_string(index));
        }
        if (index == 0) {
            head = head->next;
        } else {
            shared_ptr<Node> prev = head;
            int prev_index = index - 1;
            for (int i = 0; i < prev_index; i++) {
                prev = prev->next;
            }
            shared_ptr<Node> curr = prev->next;
            prev->next = curr->next;
        }
        numElements--;
    }

    // If possible, move the element at index to index + 1.
    // If the index is out of range, throw an invalid_argument exception.
    // When size is 3, the only possible insertion locations are 0, 1, and 2.
    void lowerPriorityOf(int index) override {
        if (index < 0 || index >= size()) {
            throw invalid_argument("In lowerPriorityOf, index was " + to_string(index));
        }
        shared_ptr<Node> curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        if (curr->next != nullptr) {
            Type temp = curr->data;
            curr->data = curr->next->data;
            curr->next->data = temp;
        }

    }

    // If possible, move the element at index to index - 1.
    // If the index is out of range, throw an invalid_argument exception.
    // When size is 3, the only possible insertion locations are 0, 1, and 2.
    void raisePriorityOf(int index) override {
        if (index < 0 || index >= size()) {
            throw invalid_argument("In raisePriorityOf, index was " + to_string(index));
        }
        shared_ptr<Node> prev = head;
        int prev_index = index - 1;
        for (int i = 0; i < prev_index; i++) {
            prev = prev->next;
        }
        shared_ptr<Node> curr = prev->next;
        if (curr != nullptr) {
            Type temp = curr->data;
            curr->data = prev->data;
            prev->data = temp;
        }
    }

    // If possible, move the element at the given index to the end of this list.
    // If the index is  out of range, throw an invalid_argument exception.
    // When size is 3, the only possible insertion locations are 0, 1, and 2.
    void moveToLast(int index) override {
        if (index < 0 || index >= size()) {
            throw invalid_argument("In moveToLast, index was " + to_string(index));
        }
        shared_ptr<Node> temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        removeElementAt(index);
        insertElementAt(size(), temp->data);
    }

    // If possible, move the element at the given index to the front of this
    // list. If the index is out of range, throw an invalid_argument exception.
    // When size is 3, the only possible insertion locations are 0, 1, and 2.
    void moveToTop(int index) override {
        if (index < 0 || index >= size()) {
            throw invalid_argument("In moveToTop, index was " + to_string(index));
        }
        shared_ptr<Node> temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        removeElementAt(index);
        insertElementAt(0, temp->data);
    }

    void printList() {
        cout << "Printing list..." << endl;
        shared_ptr<Node> temp = head;
        for (int i = 0; i < size(); i++) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

