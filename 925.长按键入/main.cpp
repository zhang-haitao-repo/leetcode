#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (j < typed.length()) {
            if (i < name.length() && name[i] == typed[j]) {
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            } else {
                return false;
            }
        }
        return i == name.length();
    }
};

int main(){
    Solution s;
    string name = "saeedi";
    string typed = "ssaaeediixxxiii";
    bool output = false;

    output = s.isLongPressedName(name, typed);

    if(output == true)
        cout << "true";
    else
    {
        cout << "false";
    }
    

    return 0;
}
