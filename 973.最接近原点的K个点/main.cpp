#include <iostream>
#include <vector>
#include <string>
#include <queue>

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

void printVector(vector<vector<int>> array)
{
    for(int i = 0; i < array.size(); ++i){
        cout <<"{"<< array[i][0] << ","<< array[i][1]<<"}";
    }
    cout << endl;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> nums;
        priority_queue<pair<int, int>> que;
        for(int i = 0; i < K; ++i){
            que.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
        }

        int lens = points.size();
        for(int i = K; i < lens; ++i){
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if(dis < que.top().first){
                que.pop();
                que.emplace(dis, i);
            }
        }

        while(!que.empty()){
            nums.push_back(points[que.top().second]);
            que.pop();
        }
        return nums;
    }
};

int main(){
    Solution s;
    vector<vector<int>> nums = {{3, 4}, {5, -1}, {-2, 4}};

    printVector(nums);

    nums = s.kClosest(nums, 2);
    printVector(nums);

    return EXIT_SUCCESS;
}
