#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include "binaryTree.h"

using namespace std;

int solve(TreeNode* A){
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    int level = 0;

    int oddLevelSum = 0;
    int evenLevelSum = 0;
    while (!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();

        if(temp == NULL){
            if(q.front() == NULL)break;
            q.push(NULL);
            level++;
        }else{
            if(level % 2 == 0) evenLevelSum += temp->val;
            if(level % 2 != 0) oddLevelSum += temp->val;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    
    return -oddLevelSum + evenLevelSum;
}

int main()
{
    binaryTree bt;
    vector<int> t = {1,2,3,4,5,6,7,8,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    vector<int> t2 = {1,2,10,-1,4,-1,-1,-1,-1,};
    bt.tree = bt.buildTree(t2);
    //bt.levelOrderPrint(bt.tree);
    cout<<solve(bt.tree);
    return 0;
}