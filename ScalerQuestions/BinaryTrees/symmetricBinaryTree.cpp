#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include"binaryTree.h"


using namespace std;

int solve(TreeNode* lf, TreeNode* rf){

    if( lf == NULL && rf == NULL) return 0;

    if(lf == NULL || rf == NULL) return 1;

    int f1 = 1;
    if(lf->val != rf->val) f1 = 0;

    int f2 = solve(lf->right, rf->left);
    int f3 = solve(lf->left, rf->right);

    return (f1 + f2 + f3) == 3 ? 1 : 0;
}

int isSymmetric(TreeNode* A){

    return solve(A->left, A->right);
}

int main()
{
    
    return 0;
}