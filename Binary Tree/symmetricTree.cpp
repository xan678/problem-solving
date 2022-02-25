#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int key){
        data = key;
        left = right = NULL;
    }
};

Node* buildLevelOrder(){
    int d ;
    cin>>d;

    Node* root = new Node(d);

    queue<Node* > q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        int c1,c2;
        cin>>c1>>c2;

        if(c1 != -1){
            current->left = new Node(c1);
            q.push(current->left);

        }
        if(c2 != -1){
            current->right = new Node(c2);
            q.push(current->right);
        } 
    }

    return root;
}

void printLevelorder(Node* root){

    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* element = q.front();
        if(element == NULL){
            q.pop();
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<element->data<<" ";
            if(element->left){
                q.push(element->left);
            }
            if(element->right){
                q.push(element->right); 
            }   
        }
    }
    return;
}

//My solution using BFS: Time limit exceeded

bool is_symmetric(vector<int> &ans){
    if(ans.size() == 1){
        return true;
    }
    
    int start = 0;
    int end = ans.size()-1;

    int mid = (start + end)/2;
    
    while(start<mid and end>mid){
        if(ans[start] != ans[end]){
            return false;
        }
    }
    return true;
}

bool checkSymmetry(Node* root){
    queue<Node*> q;

    q.push(root);
    int flag  = 0;
    while(!q.empty()){
        int size = q.size();
        vector<int> arr;
        while(size--){
            Node* current = q.front();
            q.pop();
            if(current == NULL){
                arr.push_back(-1);
            }else{
                arr.push_back(current->data);
                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
            }
        }

        if(!is_symmetric(arr)){
           return false;
        }
    }
    return true;
}

//Recursive solution from the LeetCode discuss

bool check(Node* left, Node*right){
    if(left == NULL and right == NULL){
        return true;
    }
    if(left == NULL or right == NULL){
        return false;
    }
    if(left->data != right->data){
        return false;
    }

    return check(left->left, right->right) and check(left->right, right->left);
}

bool checkSymmetry_(Node* root){
    if(root== NULL){
        return true;
    }

    return check(root->left, root->right);
    
}

//target Path Sum

void pathSum2(Node* root, int targetSum, vector<int> &helper, vector<vector<int>> &result){
    if(root == NULL){
        //helper.erase(helper.end());
        //cout<<"root Node reached"<<endl;
        return;
    }

    if(targetSum-root->data == 0 and root->left == NULL and root->right == NULL){
        //cout<<"Condition met"<<endl;
        helper.push_back(root->data);
        for(int i = 0; i<helper.size();i++){
            cout<<helper[i]<<" ";
        }
        cout<<endl;
        result.push_back(helper);
        helper.erase(helper.end()-1);
        //helper.clear();
        return;
    }

    helper.push_back(root->data);
    pathSum2(root->left, targetSum- root->data, helper, result);
    pathSum2(root->right,targetSum- root->data,helper, result);
    helper.erase(helper.end()-1);

    return;
}

vector<vector<int>> pathSum(Node* root, int targetSum){
    vector<int> helper;
    vector<vector<int>> result;


    pathSum2(root, targetSum, helper, result);

    return result;
}

void removeHalfNodes_(Node* root, vector<int> &result){
    if(root == NULL){
        return;
    }
    if(root->left == NULL and root->right == NULL){
        result.push_back(root->data);
        return;
    }

    removeHalfNodes_(root->left, result);
    if(root->left!=NULL and root->right !=NULL){
        result.push_back(root->data);
    }

    removeHalfNodes_(root->right, result);
    return;

}

vector<int> removeHalfNodes(Node *root){
    vector<int> result;

    removeHalfNodes_(root, result);
    return result;
}

int evalTree( Node* root){
    if(root->data == NULL){
        return 0;
    }
    if(root->left == NULL and root->right == NULL){
        char ch = root->data[0];
        if(ch == '+' || ch == '-' || ch == '/' || ch =='*'){
            return 0;
        }else {
            return int(root->data);
        }

        int Left = evalTree(root->left);
        int Right = evalTree(root->right);

        char ch = root->data[0];
        
        if(ch == '+' || ch == '-' || ch == '/' || ch =='*'){
            switch (ch)
            {
            case '+' : return Left + Right/* constant-expression */:
                /* code */
                break;
            case '-' : return Left - Right/* constant-expression */:
                /* code */
                break;
            case '*' : return Left * Right/* constant-expression */:
                /* code */
                break;
            case '/' : return Left / Right/* constant-expression */:
                /* code */
                break;
            }
        }
    }
}

int main(){
    Node* root = buildLevelOrder();

    //printLevelorder(root);
    int targetSum = 22;

    vector<vector<int>> result = pathSum(root,targetSum);

    /*for(int i = 0; i<result[1].size();i++){
        cout<<result[1][i]<<" ";
    }
    if(checkSymmetry(root)){
        cout<<"Is Symmetric"<<endl;
    }*/
}