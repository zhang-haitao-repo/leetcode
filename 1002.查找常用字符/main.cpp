#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> b;
        vector<string> c;
        for(int i = 0; i < A.size(); ++i){
            b.push_back(A[i]);
        }
        for(int i = 0; i < b[0].size(); ++i){
            int num = 0;
            for(int j = 1; i < b.size(); ++j){
                for(int k = 0; k < b[j].size(); ++k){
                    if(b[0][i] == b[i][k]){
                        b[i][k] = '0';
                        num ++;
                    }
                }
            }
            if(num == b.size() - 1){
                string str = "";
                char str_b;
                str_b = b[0][i];
                str += str_b; 
                c.push_back(str);
            }
        }
        return c;
    }
};

int main(){


}
