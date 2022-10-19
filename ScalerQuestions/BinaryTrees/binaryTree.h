#include<iostream>
#include<queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class binaryTree{

public:
    TreeNode* tree;

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

        this->tree = root;
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
};