#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

TreeNode* buildTree(vector<int> & tree){
    int d  = tree[0];
    //cin>>d;

    TreeNode* root = new TreeNode(d);

    queue<TreeNode* > q;
    q.push(root);
    int i = 1;
    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();

        int c1 = tree[i],c2 = tree[i+1];
        if(c1 != -1){
            current->left = new TreeNode(c1);
            q.push(current->left);

        }
        if(c2 != -1){
            current->right = new TreeNode(c2);
            q.push(current->right);
        } 
        i+=2;
    }

    return root;
}

void levelOrderPrint(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {   
        
        if(q.front() == NULL && q.back() == NULL && q.size() == 1) break;
        TreeNode* cur = q.front();
        q.pop();

        if(cur == NULL){
            q.push(NULL);
            cout<<endl;
        }
        else{
            cout<<cur->val<<" ";

            if(cur->left != NULL) q.push(cur->left);
            if(cur->right != NULL) q.push(cur->right);
        }
    }
    
}

vector<vector<int>>  levelOrderPrint2(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    vector<vector<int>> result;
    vector<int> temp;
    while (!q.empty())
    {   
        
        if(q.front() == NULL && q.back() == NULL && q.size() == 1) break;

        TreeNode* cur = q.front();
        q.pop();

        if(cur == NULL){
            result.push_back(temp);
            temp = {};
            q.push(NULL);
        }
        else{
            //cout<<cur->val<<" ";
            temp.push_back(cur->val);
            if(cur->left != NULL) q.push(cur->left);
            if(cur->right != NULL) q.push(cur->right);
        }
    }
    result.push_back(temp);
    return result;
}

int main()
{
    vector<int> tree = {1, 2, 3, 4, 5, -1, 6, -1, -1, -1, -1, -1, -1};   
    TreeNode* root = buildTree(tree);
    cout<<"Tree got built"<<endl;
    //levelOrderPrint(root);
    vector<vector<int>> result = levelOrderPrint2(root);
    for(auto x : result){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}