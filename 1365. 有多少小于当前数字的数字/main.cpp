#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> initVector()
{
    vector<int> array;
    int i = 0;
    while (1)
    {
        cin >> i;
        if(i == -1)
        {
            break;
        }
        else
        {
            array.push_back(i);
        }
    }
    return array;
}

void printVector(vector<int> array)
{
    for(int i = 0; i < array.size(); ++i){
        cout << array[i] << "\t";
    }
    cout << endl;
}

class Solution {
public:
    // 暴力解：
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> small_list;
        for(int i = 0; i < nums.size(); ++i){
            int num = 0;
            for(int j = 0; j < nums.size(); ++j)
            {
                if(nums[i] > nums[j])
                    num ++;
            }
            small_list.push_back(num);
        }
        return small_list;
    }
};

int main(){
    Solution s;
    vector<int> nums;

    nums = initVector();
    printVector(nums);

    nums = s.smallerNumbersThanCurrent(nums);
    printVector(nums);

    return EXIT_SUCCESS;
}
