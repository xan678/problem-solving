#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include "binaryTree.h"

using namespace std;

vector<int> solve(TreeNode* A){
    queue<TreeNode*> q;
    q.push(A);
    vector<int> result;
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        
        result.push_back(temp->val);
        
        if(temp->val != -1){
            q.push( temp->left == NULL ? new TreeNode(-1) : temp->left);
            q.push( temp->right == NULL ? new TreeNode(-1) : temp->right);
        }
    }
    
    return result;
}

int main()
{
    
    return 0;
}