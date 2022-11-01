#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include "binaryTree.h"

using namespace std;

vector<int> solve(TreeNode* A){
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);

    vector<int> result;
    result.push_back(A->val);

    while (!q.empty())
    {
        TreeNode* f = q.front();
        q.pop();

        if(f == NULL){
            if(q.front() == NULL) break;
            result.push_back(q.front()->val);
            q.push(NULL);
        }else{
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }
    }
    return result;
    
}

int main()
{
    binaryTree bt; 
    vector<int> elements = {1,2,3,4,5,6,7,8,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    bt.tree = bt.buildTree(elements);
    //bt.levelOrderPrint(bt.tree);
    vector<int> result = solve(bt.tree);

    for(auto x : result) cout<<x<<" ";
    cout<<endl;
    return 0;
}