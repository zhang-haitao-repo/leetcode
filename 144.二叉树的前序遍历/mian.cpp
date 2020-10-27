#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //二叉树前序遍历（栈的方法--也可以使用递归去做）
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> treeStack;
        treeStack.push(root);
        vector<int> preordertree;
        while (treeStack.empty())
        {
            TreeNode* pNode;
            pNode = treeStack.top();
            preordertree.push_back(pNode->val);
            treeStack.pop();
            if(pNode != nullptr){
                treeStack.push(pNode->left);
                treeStack.push(pNode->right);
            }
        }
        return preordertree;
    }
};

int main(){

}