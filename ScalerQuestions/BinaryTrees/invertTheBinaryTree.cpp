#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "binaryTree.h"

using namespace std;

TreeNode* invertTree(TreeNode* A){
    if(A == NULL) return NULL;

    TreeNode* left = invertTree(A->left);
    TreeNode* right = invertTree(A->right);

    A->left = right;
    A->right = left;
    return A;

}

int main()
{
    
    return 0;
}