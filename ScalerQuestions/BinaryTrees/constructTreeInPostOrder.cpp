#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "binaryTree.h"

using namespace std;

TreeNode* solve(vector<int> &A, vector<int> &B, int ps , int pe, int ins, int ine){

    if(ps > pe) return NULL;

    int root = B[pe];

    int i = ins;
    int rootIndex = -1;
    while(i<= ine){
        if(A[i] == root){
            rootIndex = i;
            break;
        }
        i++;
    }
    
    TreeNode* node = new TreeNode(root);

    int leftSubtreeLength = rootIndex - ins;

    node->left = solve(A,B,ps, ps+leftSubtreeLength-1,ins, rootIndex-1);
    node->right = solve(A,B,ps+leftSubtreeLength, pe-1, rootIndex+1, ine);

    return node;
}

TreeNode* buildTree( vector<int> &A, vector<int> &B){
    return solve(A,B, 0,A.size()-1, 0, A.size()-1);
}

int main()
{
    
    return 0;
}