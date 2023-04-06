/*
 * Andrew Tapia
 */
#include <vector>
#include <cstdlib>
#include <string>

#ifndef STACKS_HPP
#define STACKS_HPP
using namespace std;

// Stack is an abstract class because it has all pure virtual
// functions.  This is the equivalent to the Java interface
template<typename Type>
class Stack {
public:
    virtual void push (Type const &) = 0; // push element
    virtual Type pop () = 0; // return top element & remove
    virtual Type top () const = 0;  // return top el
    virtual bool isEmpty () const = 0;  // return true
};
/*
 *
 */


/////////// VectorStack //////////////
template<class Type>
class VectorStack : Stack<Type> {
private :
    vector<Type> elems{};
public:
    void push (Type const &elem) override{
        elems.push_back(elem);
    }
    Type pop () override {
        Type temp = elems.back();
        elems.pop_back();
        return temp;
    }
    Type top () const override {
        return elems.back();
    }
    bool isEmpty() const override{
        return elems.empty();
    }
};


//////////// ArrayStack //////////////
template<class Type>
class ArrayStack : Stack<Type> {
private:
   Type data[1000];
   int index = -1;
public:
    void push (Type const &elem) override{
        index++;
        data[index] = elem;
    }
    Type pop () override {
        int temp = index;
        index--;
        return data[temp];
    }
    Type top () const override {
        return data[index];
    }
    bool isEmpty() const override{
        return index == -1;
    }
};


///////// LinkedStack
template<class Type>
class LinkedStack : Stack<Type> {
  struct Node{
      Type data;
      Node *next;

      Node (Type const & element, Node *nextRef) {
          data = element;
          next = nextRef;
      }
  };
private:
    Node *tail = nullptr;
public:
    void push (Type const &elem) override{
        Node *newNode = new Node(elem, tail);
        tail = newNode;
    }
    Type pop () override {
        Type temp = tail->data;
        tail = tail->next;
        return temp;
    }
    Type top () const override {
        return tail->data;
    }
    bool isEmpty() const override{
        return tail == nullptr;
    }

};


#endif