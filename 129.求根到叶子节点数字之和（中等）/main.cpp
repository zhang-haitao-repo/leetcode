#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct TreeNode
{
    //数据域
    int val;
    //指针域
    struct TreeNode* left;
    struct TreeNode* right;
};

class Solution {
public:
    int front_recursion(struct TreeNode* root, int num){
        num = num * 10 + root->val;
        if(root->left == NULL && root->right == NULL){
            return num;
        }
        int sum = 0;
        if(root->left != NULL){
            sum += front_recursion(root->left, num);
        }

        if(root->right != NULL){
            sum += front_recursion(root->right, num);
        }

        return sum;
    }
    int sumNumbers(TreeNode* root) {
        int sumNum = 0;

        sumNum = front_recursion(root, 0);
        return sumNum;
    }
};

//前序遍历
void front_recursion(struct TreeNode* root)
{
    if(root == NULL){
        return;
    }

    printf("%d", root->val);

    front_recursion(root->left);

    front_recursion(root->right);
}

void test01(){
    printf("======test01=====\n");
    struct TreeNode nodeA = {1, NULL, NULL};
    struct TreeNode nodeB = {2, NULL, NULL};
    struct TreeNode nodeC = {3, NULL, NULL};
    struct TreeNode nodeD = {5, NULL, NULL};
    struct TreeNode nodeE = {1, NULL, NULL};
    
    //建立关系
    nodeA.left = &nodeB;
    nodeA.right = &nodeC;

    // nodeB.left = &nodeD;
    // nodeB.right = &nodeE;

    Solution s;

    front_recursion(&nodeA);
    printf("\n");

    int num = s.sumNumbers(&nodeA);
    cout << num << endl;
}

int main(){

    test01();

    return EXIT_SUCCESS;
}