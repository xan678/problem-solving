#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

class Node{
    public:
        int key;
        Node* left;
        Node* right;

        Node(int key){
            this->key = key;
            left = right = NULL;
        }

};

Node* insert(Node* root, int key){
    if(root == NULL){
        return new Node(key);
    }

    //rec case
    if(key<=root->key){
        root->left = insert(root->left,key);
    }
    else{
        root->right = insert(root->right, key);
    }

    return root;

}

//Node* buildBinarySearchTee(vector<int> arr){
//    Node* root = NULL;
//    for(auto it : arr){
//        root = insert(root,*it);
//    }
//    return root;
//}

void printBinarySearchTree(Node* root){
    if(root == NULL){
        return;
    }

    printBinarySearchTree(root->left);
    cout<<root->key<<" ";
    printBinarySearchTree(root->right);
    return;
}
//Insert into BST through recursion is not the optimum solution for this.
//Better to do this interatively 
//Need to research on this while revising concepts
Node* findMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
Node* remove(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    else if(key<root->key){
        root->left =  remove(root->left, key);
    }
    else if(key > root->key){
        root->right = remove(root->right, key);
    }
    else{
        //The current Node matches the key
        // 1st case : Current Node has zero children
        if(root->right == NULL and root->left == NULL){
            delete root;
            root = NULL;
        }
        //Single Child
        else if(root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        //Two children;
        else{
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
    }

    return root;
}

void printLevelBST(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        if(current != NULL){
            cout<<current->key<<" ";
           if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
        }else{
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}

//Practice Questions from Leetcode
//Print sum in range low to high
int rangeSumBST(Node* root, int low, int high){
    if(root == NULL){
        return 0;
    }
    if(root->key >= low and root->key <= high){
        return rangeSumBST(root->left, low, high) + root->key + rangeSumBST(root->right,low, high);
    }
    if(high < root->key){
        return rangeSumBST(root->left, low,high);
    }else{
        return rangeSumBST(root->right,low, high);
    }
}

//Check whether a tree is BST or not
void pushInorder(Node* root, vector<int> &result){
    if(root == NULL){
        return ;
    }
    pushInorder(root->left,result);
    result.push_back(root->key);
    pushInorder(root->left,result);

    return;
}

bool isBST(Node* root){
    vector<int> inorder ;
    pushInorder(root, inorder);

    for(auto it = inorder.begin(); it<inorder.end()-1;it++){
        if(*it > *it++){
            return false;
        }
    }

    return true;
}

// Leetcode optimized solution
// Need to dry run the solution one more time
bool isValidBST(TreeNode* root) {
    TreeNode* prev = NULL;
    return validate(root, prev);
}
bool validate(TreeNode* node, TreeNode* &prev) {
    if (node == NULL) return true;
    if (!validate(node->left, prev)) return false;
    if (prev != NULL && prev->val >= node->val) return false;
    prev = node;
    return validate(node->right, prev);
}

int main(){
    int arr[] = {10,5,15,3,7,18};
    
    Node*root = NULL;

    for( int x : arr){
        root = insert(root,x);
    }

    //printBinarySearchTree(root);
    // int key;
    // cin>>key;
    // root = remove(root,key);
    //printBinarySearchTree(root);
    printLevelBST(root);
    // int low = 7;
    // int high = 15;
    // cout<<endl<<rangeSumBST(root,low,high);

    cout<<isBST(root)<<endl;
    return 0;
}