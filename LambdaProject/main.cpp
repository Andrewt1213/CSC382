#include <iostream>
#include "LambdaFun.cpp"
#include <vector>
#include <string>
using namespace std;
int main() {
    vector<int> nums{2, 4, 6, 8, 2, 4, 10000};
    vector<int> nums1{2, 3, 6, 8, 2, 4, 10000};

    //cout << allEven(nums) << endl;
    //cout << allEven(nums1) << endl;

    vector<int> nums2{2, 4, 6, 8, 2, 4, 10000};
    vector<int> nums3{2, 3, 6, 8, 2, 0, 10000};
    vector<int> nums4{2, 3, 6, 8, 2, -1, 10000};

    //cout << allPositive(nums2) << endl;
    //cout << allPositive(nums3) << endl;
    //cout << allPositive(nums4) << endl;

    //vector<int> nums5{2, 4, 6, 8, 2, 4, 10000};
   // vector<double> nums6{2.0, 3.0, 6.0, 8.0, 2.0, 0.0, 10000.0};
    //vector<int> nums7{2, 3, 6, 8, 2, -1, 10000};

    //cout << hasNoneOfThese(nums5, 2) << endl;
    //cout << hasNoneOfThese(nums6, 6.0) << endl;
    //cout << hasNoneOfThese(nums7, 999) << endl;

    vector<int> nums5{-5, 89, 0, -1, 99, 101};
    vector<int> nums7{2, 3, 6, 8, 2, -1, 10000};

    auto x = cleanVector(nums5);
    auto z = cleanVector(nums7);
    vector<int> nums6{2, 4, 6, 8, 2, 4};


    for (auto i: x)
        cout << i << ' ';


    return 0;
}
