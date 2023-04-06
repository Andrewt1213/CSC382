/*
 * PriorityList.h
 *
 * An abstract class that provides the interface for a collection
 * that maintains elements where the lowest index 0 has the highest
 * priority.  The element at size()-1 has the lowest priority.  The
 * priority of any element can be changed with member functions
 * such as raisePriorityOf, lowerPriorityOf, and moveToTop.
 *
 * Although we'll just use string elements, in the future we may
 * have Priority type elements. Hence this is a templated class.
 *
 *  Author: Rick Mercer
 */

#ifndef PRIORITYLIST_H_
#define PRIORITYLIST_H_

/*
 * This class describes an abstract base class Priority to store elements where
 * indexes represent priorities and the priorities can change in several ways.
 * Like any container, there are insert and remove functions.  Indexes represent
 * priorities and the priorities can change in several ways. The element at
 * index 0 has the highest priority, the element at size()-1 has the lowest priority.
 *
 *
 * This class is designed to be implemented by subclasses using different
 * data structures such as linked structures or arrays.
 *
 * All members are pure virtual functions. This means the subclass MUST implement that method
 *
 * @author Rick Mercer
 *
 *  <Type>  The type of all elements stored in this collection
 */
template<class Type>
class PriorityList {

public:
  /*
   * Return the number of elements in this PriorityListDone
   */
  virtual int size() const = 0;

  /*
   * Return true if there are zero elements in this PriorityListDone
   */
  virtual bool isEmpty() const = 0;

  /*
   * If possible, return a reference to the element at the given index. If index
   * is out of the valid range of 0..size()-1, throw new IllegalArgumentException();
   * When size is 3, the only possible values for index are 0, 1, and 2.
   */
  virtual Type getElementAt(int index) const = 0;

  /*
   * If possible, insert the element at the given index. If index is out
   * of the valid range of 0..size(), throw new IllegalArgumentException();
   * When size is 3, the only possible values for index are 0, 1, 2, AND 3
   * because you can add an element as the new last.
   */
  virtual void insertElementAt(int index, const Type & el) = 0;

  /*
   * If possible, remove the element at the given index. If index is out of
   * the valid range of 0..size()-1, throw new IllegalArgumentException();
   * When size is 3, the only possible values for index are 0, 1, and 2.
   */
  virtual void removeElementAt(int index) = 0;

  /*
   * If possible, swap the element located at index with the element at index + 1.
   * An attempt to lower the priority of the element at index size()-1 has no effect.
   * If index is out of the valid range of 0..size()-1, throw new IllegalArgumentException();
   * When size is 3, the only possible values for index are 0, 1, and 2.
   */
  virtual void lowerPriorityOf(int index) = 0;

  /*
   * If possible, swap the element located at index with the element at index-1.
   * An attempt to raise the priority at index 0 has no effect. If index is out
   * of the valid range of 0..size()-1, throw new IllegalArgumentException();
   * When size is 3, the only possible values for index are 0, 1, and 2.
   */
  virtual void raisePriorityOf(int index) = 0;

  /*
   * If possible, move the element at the given index to the end of this list.
   * An attempt to move the last element to the last has no effect. If the index
   * is out of the valid range 0..size()-1 throw new IllegalArgumentException();
   * When size is 3, the only possible values for index are 0, 1, and 2.
   */
  virtual void moveToLast(int index) = 0;

  /*
   * If possible, move the element at the given index to the front of this list.
   * An attempt to move the top element to the top has no effect. If the index
   * is out of the valid range of 0..size()-1, throw new IllegalArgumentException();
   * When size is 3, the only possible values for index are 0, 1, and 2.
   */
  virtual void moveToTop(int index) = 0;

};

#endif /* PRIORITYLIST_H_ */
