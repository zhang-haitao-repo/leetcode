#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;


class Solution {
public:
    // BFS解法：
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if ( words.empty() || words.find(endWord) == words.end() ) return 0;
        words.erase(beginWord);
        queue<string> que;
        que.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int step = 1;
        while ( !que.empty() ) {
            // 找到没有被访问过, 而且能够由当前单词转换而成的单词
            int n = que.size();
            // 每一轮(每一层step加个1)
            while ( n-- ) {
                string curWord = que.front();
                que.pop();
                // 当前单词的每个字符都替换成其他的25个字符, 然后在单词表中查询
                // 是不是包含转换后的单词
                // 这里千万不能遍历单词表, 因为单词表很长, 而哈希表使用的红黑树的查询效率比遍历单词表高很多
                for ( int i = 0; i < curWord.size(); ++i ) {
                    char originalChar = curWord[i];
                    for ( int j = 0; j < 26; ++j ) {
                        if ( char('a' + j) == originalChar ) continue;
                        curWord[i] = (char)('a' + j);
                        if ( words.find(curWord) != words.end() && visited.find(curWord) == visited.end() ) {
                            if ( curWord == endWord ) return step + 1;
                            else {
                                que.push(curWord);
                                visited.insert(curWord);
                            }    
                        }
                    }
                    curWord[i] = originalChar;
                }
            }
            ++step;
        }
        return 0;
    }
};


int main(){

    return EXIT_SUCCESS;
}

