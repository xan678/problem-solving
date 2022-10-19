#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include "binaryTree.h"

using namespace std;

vector<int> solve(TreeNode* A){
    queue<TreeNode*> q;
    vector<int> result;
    q.push(A);
    q.push(NULL);

    while (!q.empty())
    {   
        TreeNode* temp = q.front();
        q.pop();
        
        //if(q.front() == NULL && q.back() == NULL && q.size() == 1)break;

        if(q.front() == NULL){
            result.push_back(temp->val);
        }
        if(temp == NULL){
            q.push(NULL);
        }   

        if(temp->right != NULL){
            q.push(temp->right);
        }
        if(temp->left != NULL){
            q.push(temp->left);
        }
    }

    return result;

}

int main()
{
    
    return 0;
}