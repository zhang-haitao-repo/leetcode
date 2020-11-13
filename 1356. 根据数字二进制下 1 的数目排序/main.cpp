#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countBit(int a){
        int n = 0;
        while(a > 0){
            a &= (a - 1);
            ++n;
        }
        return n; 
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int a, int b){
            int countBit_x = countBit(a);
            int countBit_y = countBit(b);
            if (countBit_x != countBit_y) 
                return countBit_x < countBit_y;
            return a < b; 
        });
        return arr;
    }
};

void printVector(vector<int> array){
    for(int i = 0; i < array.size(); ++i){
        cout << array[i] << "\t";
    }
    cout << endl;
}

int main(){

    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    Solution s;

    arr = s.sortByBits(arr);
    printVector(arr);

    return EXIT_SUCCESS;
}