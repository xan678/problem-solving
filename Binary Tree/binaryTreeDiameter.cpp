#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int key){
        data = key;
        left = right = NULL
    }
};

Node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }

    Node* n = new Node(d);

    n->left = buildTree();
    n->right = buildTree();

    return n;
}

int heightOfTree(Node *root){
    if(root == NULL{
        return 0;
    }

    int h1= heightOfTree(root->left);
    int h2 = heightOfTree(root->right);

    return max(h1, h2) +1;
}

pair<int, int> diameterTree(Node* root){
    pair<int, int> p;
    if(root == NULL){
        p.first = p.second = 0;
        return p;
    }

    pair<int, int> Left = diameterTree(root->left);
    pair<int, int> Right = diameterTree(root->right);

    p.first = max(Left.first, Right.second) +1;

    p.second = max(Left.first + Right.first, max(Left.second, Right.second));

    return p;

}

int main(){

    Node* root = buildTree();

    return 0;
}