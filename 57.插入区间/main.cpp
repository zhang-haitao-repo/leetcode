#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int lens = intervals.size();
        vector<vector<int>> nums;
        for(int i = 0; i < lens; ++i){
            if(intervals[i][1] < newInterval[0]){
                nums.push_back(intervals[i]);
            }
            if(intervals[i][1] >= newInterval[0]){

                if(intervals[i][0] > newInterval[1]){
                    nums.push_back(newInterval);
                }
                
                if(intervals[i][1] > newInterval[1]){
                    nums.push_back(intervals[i]);
                }
                
            }
        }
        return nums;
    }
};

void printVector(vector<vector<int>>& array){
    for(int i = 0; i < array.size(); ++i){
        cout <<"["<< array[i][0] << ","<<array[i][1]<<"]\t";
    }
    cout << endl;
}

int main(){
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {4, 5};

    printVector(intervals);

    Solution s;
    vector<vector<int>> nums = s.insert(intervals, newInterval);
    
    printVector(nums);

    return EXIT_SUCCESS;
}