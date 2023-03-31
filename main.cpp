#include <iostream>
#include <windows.h>
#include <cassert>
#include "Card.cpp"
#include "52Cards.hpp"
#include "PokerHand.cpp"
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    vector<PokerHand> all;

    PokerHand a(C7, D7, C4, H8, H10);
    PokerHand b(H7, S7, S4, S7, S10);
    PokerHand c(D4, C5, S6, C7, S9);
    PokerHand d(C4, S3, H6, H7, H9);
    PokerHand e(S6, D6, DK, CK, HK);
    PokerHand f(S3, D3, DA, CJ, HQ);
    PokerHand g(S6, D6, DA, CA, HA);
    PokerHand h(C7, H7, DA, CA, HA);
    PokerHand i(D2, H4, C3, C2, H3);
    PokerHand j(H9, D9, S2, H2, SJ);
    PokerHand k(DA, CA, DK, CK, H7);
    PokerHand l(C2, D2, C3, H3, D4);
    PokerHand m(CA, HA, CK, HK, CQ);
    PokerHand n(S7, C10, D2, HJ, SQ);

    all.push_back(a);
    all.push_back(b);
    all.push_back(c);
    all.push_back(d);
    all.push_back(e);
    all.push_back(f);
    all.push_back(g);
    all.push_back(h);
    all.push_back(i);
    all.push_back(j);
    all.push_back(k);
    all.push_back(l);
    all.push_back(m);
    all.push_back(n);

    sort(all.begin(), all.end());
    for (auto itr = all.begin(); itr != all.end(); itr++) {
        std::cout << itr->toString() <<  std::endl;
    }


    return 0;
}



