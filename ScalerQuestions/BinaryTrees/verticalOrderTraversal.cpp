#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include "binaryTree.h"
#include <unordered_map>

using namespace std;

vector<vector<int>> verticalOrderTraversal(TreeNode* A){
    int minLevel = INT_MAX;
    int maxLevel = INT_MIN;

    unordered_map<int, vector<int>> map;
    queue<pair<TreeNode*,int>> q;

    q.push(make_pair(A,0));

    while (!q.empty())
    {
        pair<TreeNode*,int> temp = q.front();
        q.pop();

        minLevel = min(minLevel, temp.second);
        maxLevel = max(maxLevel, temp.second);

        if(map.find(temp.second) != map.end()){
            map[temp.second].push_back(temp.first->val);
        }else{
            vector<int> tempV;
            tempV.push_back(temp.first->val);
            map.insert(make_pair(temp.second, tempV));
        }

        if(temp.first->left) q.push(make_pair(temp.first->left, temp.second-1));
        if(temp.first->right) q.push(make_pair(temp.first->right, temp.second+1));
    }
    
    vector<vector<int>> result;
    for(int i = minLevel; i<=maxLevel; i++){
        result.push_back(map[i]);
    }
    return result;
}

int main()
{
    binaryTree bt; 
    vector<int> t = {6,3,7,2,5,-1,9,-1,-1,-1,-1,-1,-1};
    
    return 0;
}