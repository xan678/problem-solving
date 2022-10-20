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
        
        if(q.front() == NULL && temp == NULL) break;

        if(q.front() == NULL){
            result.push_back(temp->val);
        }
        if(temp == NULL){
            q.push(NULL);
        }   

        if(temp != NULL && temp->left != NULL){
            q.push(temp->left);
        }
        if(temp != NULL && temp->right != NULL){
            q.push(temp->right);
        }
    }

    return result;

}

int main()
{
    //vector<int> t = {7 ,1 ,15 ,2 ,-1 ,-1 ,-1 ,-1 ,-1, -1, -1};
    vector<int> t2 = {1,2,3,4,5,6,7,8,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    binaryTree bt;

    TreeNode* tr = bt.buildTree(t2);
    cout<<"tree built"<<endl;
    //bt.levelOrderPrint(tr);
    vector<int> result = solve(tr);
    for(auto x : result){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}