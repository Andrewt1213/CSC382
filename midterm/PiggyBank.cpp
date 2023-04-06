//
// Created by Andrew on 3/3/2023.
//
class PiggyBank {
private:
    int money;

public:
    PiggyBank() {
        money = 0;
    }

    void addPennies(int num){
        money += num;
    }

    void addNickels(int num){
        money += num*5;
    }

    void addDimes(int num){
        money += num*10;
    }

    int total(){
        return money;
    }

};