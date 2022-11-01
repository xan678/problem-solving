#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include "binaryTree.h"

using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode*A){
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    int level = 0;

    vector<int> tempV;
    vector<vector<int>>result;

    while (!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();

        if(temp == NULL) {
            
            if(q.front() == NULL) {
                if(level % 2 == 0){
                    reverse(tempV.begin(), tempV.end());
                    result.push_back(tempV);
                } 
                if(level %2 != 0) result.push_back(tempV);

                break;
            }
            
            if(level % 2 == 0){
                reverse(tempV.begin(), tempV.end());
                result.push_back(tempV);
            } 
            if(level %2 != 0) result.push_back(tempV);
            
            level++;
            q.push(NULL);
            tempV = {};
        }else{
            tempV.push_back(temp->val);
                
            if(temp->right) q.push(temp->right);
            if(temp->left) q.push(temp->left);

        }
    }
    
    return result;
}

int main()
{
    vector<int> t = {1,2,3,4,5,6,7,8,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    binaryTree bt;
    bt.tree = bt.buildTree(t);
    //bt.levelOrderPrint(bt.tree);

    vector<vector<int>> result = zigzagLevelOrder(bt.tree);
    for(auto x : result){
        for(auto y : x) cout<<y<<" ";
        cout<<endl;
    }

    return 0;
}