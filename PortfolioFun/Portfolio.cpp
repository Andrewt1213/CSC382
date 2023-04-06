/*
 * Portfolio.cpp
 *
 * This file contains a small inheritance hierarchy of Assets that can be stored
 * in the same container. In C++, with inheritance, the container we must use a
 * vector of pointers to different type objects instead of a vector of one type.
 * You are required to use smart pointers, specifically std::shared_ptr.
 *
 * Programmers: Rick Mercer and Andrew Tapia
 */
#include <iostream>
#include <memory>  // shared_ptr
#include <vector>
#include <iomanip> // setprecision() fixed
using namespace std;

class Asset {
  // All Asset objects have a name. This could be protected, but private
  // makes me add a getter common to all. private: also requires all
  // subclasses to call the superclass constructor.
private:
  string name;

public:
  Asset (string assetName) {
    name = assetName;
  }

  // All subclasses get this member function
  string getName () {
    return name;
  }

  // Virtual methods like getValue must be implemented by any class
  // that is derived by this abstract class Asset.
  virtual double getValue () = 0;
};

/////////////////////////////////////////////
// TODO: Implement class BankAccount so objects can be stored in a vector<shared_ptr<Asset>>
class BankAccount: public Asset{
private:
    string name;
    double value;
public:
    BankAccount (string name, double value) :  Asset(name){
        this->name = name;
        this->value = value;
    }

    double getValue() override {
        return value;
    }

    void withdraw(double amt){
        value -= amt;
    }

    void deposit(double amt){
        value += amt;
    }
};

///////////////////////////////////////////
// TODO: Implement class Bond so objects can be stored in a vector<shared_ptr<Asset>>
class Bond : public Asset {
private:
    string name;
    double value;
public:
    Bond (string name, double value) : Asset (name){
        this->name = name;
        this->value = value;
    }

    double getValue() override {
        return value;
    }

};

////////////////////////////////////////////////////////////
// TODO: Implement class Stock so objects can be stored in a vector<shared_ptr<Asset>>
class Stock : public Asset {
private:
    string name;
    int amtStock;
    double price;
public:
    Stock (string name, int amtStock, double price) : Asset(name) {
        this->name = name;
        this->amtStock = amtStock;
        this->price = price;
    }

    double getValue () override {
        return amtStock * price;
    }

    void changeShares(int amt){
        amtStock = amt;
    }

    void changePrice(double price){
        this->price = price;
    }
};

////////////////////////////////////////////////////////////
// TODO: Implement class Portfolio as a container of shared_ptr<Assets>s
class Portfolio {
private:
    vector<shared_ptr<Asset>> portfolio;
public:
    void add(shared_ptr<Asset> item){
        portfolio.push_back(item);
    }
    shared_ptr<Asset> get(int index){
        return portfolio.at(index);
    }

    void showAll(){
        cout << "All Assets" << endl;
        cout << "==========" << endl;
        for (shared_ptr<Asset> item : portfolio) {
            cout << item->getValue() << endl;
        }
    }

    double getValue(){
        double value = 0;
        for (shared_ptr<Asset> item : portfolio) {
            value += item->getValue();
        }
        return value;
    }
};


// Add all classes above to make sure this code compiles and generates the output shown after main
int main () {

  // Note: At first, you will see many compile time errors

  // Three different ways to initialize smart pointer to an Asset
  shared_ptr<BankAccount> acct = shared_ptr<BankAccount>{new BankAccount{"account", 50.00}};
  auto stock = shared_ptr<Stock>{new Stock("stock", 50, 10.0)};
  auto bond = shared_ptr<Bond>(new Bond{"bond", 5000});

  Portfolio portfolio;
  // Just as we can convert an ordinary pointer to a derived type to a pointer to a base-class type,
  // we can also convert a smart pointer to a derived type to a smart pointer to a base-class type.
  // All the elements of portfolio have the same type, a shared_ptr<Asset>
  portfolio.add(acct);
  portfolio.add(stock);
  portfolio.add(bond);

  // Set all output that follows to show two decinal places
  cout << fixed;
  cout << setprecision(2);
  // Show the individual assets using get on the Asset container
  cout << "Show all Assets using get() on the container" << endl;
  cout << "============================================" << endl;
  cout << portfolio.get(0)->getName() << ": " << portfolio.get(0)->getValue() << "\n";
  cout << portfolio.get(1)->getName() << ": " << portfolio.get(1)->getValue() << "\n";
  cout << portfolio.get(2)->getName() << ": " << portfolio.get(2)->getValue() << "\n";

  // Show all three Asset names and values in the portfolio
  cout << endl << "The portfolio in it's current state has 3 Assets:" << endl;

  portfolio.showAll();
  // And the total value of the portfolio.
  cout << "Portfolio's total value: " <<  portfolio.getValue() << endl;

  // Change one Asset, the BankAccount, twice
  acct->withdraw(50.00); // balance 0.0
  acct->deposit(1.23); // balance 1.23

  // Change another Asset, the Stock, twice
  stock->changeShares(10);
  stock->changePrice(7.00); // getValue() 70

  // Show all three Asset names and values in the portfolio
  cout << endl << "The portfolio after modifying the state of two objects:" << endl;
  portfolio.showAll();
  cout << "Portfolio's total value: " << portfolio.getValue();

  return 0;
}

/* Expected Output:

Show all Assets using get() on the container
============================================
account: 50.00
stock: 500.00
bond: 5000.00

The portfolio in it's current state has 3 Assets:
All Assets
==========
50.00
500.00
5000.00
Portfolio's total value: 5550.00

The portfolio after modifying the state of two objects:
All Assets
==========
1.23
70.00
5000.00
Portfolio's total value: 5071.23

*/