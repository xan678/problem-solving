#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "binaryTree.h"

using namespace std;

int solve(TreeNode* A){
    
    int l = solve(A->left);
    int r = solve(A->right);

    if(l != 0 && r != 0){
        
    }
}

int main()
{
    
    return 0;
}