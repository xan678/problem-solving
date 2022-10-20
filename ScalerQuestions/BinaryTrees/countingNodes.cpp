#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "binaryTree.h"

using namespace std;

vector<int> flag(200005,-1);

int solve2(TreeNode* A, int index){

    if(A == NULL) return 0;

    flag[index] = A->val;

    int left = solve2(A->left , index*2 );
    int right = solve2(A->right, index*2 + 1);

    cout<<left<<" "<<right<<endl;
    int count = 1;
    while(index >0){
        if(flag[index] != -1 && A->val < flag[index/2]){
            count = 0;
            break;
        }
        index /= 2;
    }
    return left + right + count;
}

int solve(TreeNode* A){

    // if(A->right == NULL && A->left == NULL) return 1;

    // int left = 0;
    // int right = 0;

    // if(A->left != NULL) left = solve(A->left);
    // if(A->right != NULL) right = solve(A->right);

    // if(A->left != NULL && A->val < A->left->val){
    //     left++;
    // }

    // if(A->right != NULL &&A->val < A->right->val){
    //     right++;
    // }
    // return left+right;
    flag[0] = INT_MIN;
    return solve2(A,1);
}

int main()
{
    binaryTree bt;
    vector<int> t = {11 ,1 ,20 ,3 ,-1 ,-1 ,14 ,-1 ,-1 ,5 ,-1 ,-1,-1};
    vector<int> t2 = {4,5,2,-1,-1,3,6,-1,-1,-1,-1};
    bt.buildTree(t2);
    //bt.levelOrderPrint(bt.tree);

    cout<<solve(bt.tree)<<endl;
    return 0;
}