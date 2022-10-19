#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include "binaryTree.h"

using namespace std;


vector<int> inorderTraversal(TreeNode* A){
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* temp = A;
    s.push(temp);

    while (temp != NULL)
    {   
        //if(s.empty()) break;
        //cout<<"In Loop"<<endl;   
        if(temp->left != NULL){
            s.push(temp->left);
            temp = temp->left;
            continue;
        }else{
            TreeNode* root = s.top();
            s.pop();
            result.push_back(root->val);
            while (root->right == NULL)
            {   
                if(s.empty()){
                    temp = NULL;
                    break;
                }
                root = s.top();
                result.push_back(root->val);
                s.pop();
            }
            
            if(root->right != NULL){
            temp = root->right;
            s.push(temp);
            }
        }
    }
    //cout<<result.size();
    return result;    
}

int main()
{
    vector<int> btree = {1,6,2,-1,-1,3,-1,-1,-1,-1,-1};
    binaryTree bt;
    TreeNode* btnode = bt.buildTree(btree);
    //bt.levelOrderPrint(btnode); 

    vector<int> result = inorderTraversal(btnode);
    for(auto x : result){
        cout<<x<<" -> ";
    }
    cout<<endl;
    return 0;
}