#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> initVector(){
    vector<int> array;
    int i = 0;
    while (1){
        cin >> i;
        if(i == -1)
            break;
        else
            array.push_back(i);
    }
    return array;
}

void printVector(vector<int> array){
    for(int i = 0; i < array.size(); ++i){
        cout << array[i] << "\t";
    }
    cout << endl;
}

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int lens = A.size();
        if(lens < 3)
            return false;
        int up_flag = 1;
        for(int i = 1; i < lens; ++i){
            if(A[i] == A[i - 1]){
                return false;
            }
            if(up_flag == 1){
                if(A[i] <= A[i - 1]){
                    up_flag = 0;
                    if(i == 1){
                        return false;
                    }
                }
            }
            else{
                if(A[i] >= A[i - 1]){
                    return false;
                }
            }
            
        }
        if(up_flag == 1)
            return false;
        return true;
    }

    bool validMountainArray1(vector<int>& A) {
        int N = A.size();
        int i = 0;

        // 递增扫描
        while (i + 1 < N && A[i] < A[i + 1]) {
            i++;
        }

        // 最高点不能是数组的第一个位置或最后一个位置
        if (i == 0 || i == N - 1) {
            return false;
        }

        // 递减扫描
        while (i + 1 < N && A[i] > A[i + 1]) {
            i++;
        }

        return i == N - 1;
    }
};


int main(){
    Solution s;
    vector<int> nums;

    nums = initVector();
    printVector(nums);

    bool result = s.validMountainArray(nums);

    if(result == true)
        cout << "true";
    else
    {
        cout << "false";
    }
    cout << endl;

    return EXIT_SUCCESS;
}
