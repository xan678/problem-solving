#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "binaryTree.h"

using namespace std;

vector<int> result;

bool solve2(TreeNode* A, int B){

    if(A == NULL) return false;
    if(A->val == B) {
        result.push_back(A->val);
        return true;
    }

    bool left = solve2(A->left, B);
    bool right = solve2(A->right, B);

    //cout<<left<<" "<<right<<endl;

    if(left || right){
        //cout<<A->val<<" ";
        result.push_back(A->val);
    }

    return left || right;
}

vector<int> solve(TreeNode* A, int B){
    result = {};
    solve2(A,B);
    return result;
}


int main()
{
    vector<int> tre = {15 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1,-1,-1,-1};
    binaryTree bt;
    bt.buildTree(tre);

    //bt.levelOrderPrint(bt.tree);

    vector<int> result = solve(bt.tree, 4);
    for(auto x : result){
        cout<<x<<" ";
    }    
    return 0;
}