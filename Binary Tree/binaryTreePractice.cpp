#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node( int d){
            data = d;
            left = right = NULL;
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
/*
void rightSideView_(Node* root, vector<int> &result,bool isInsert){
        if(root == NULL){
            return;
        }
        if(isInsert){
            cout<<"Insert True Pushed data"<<root->data<<endl;
            result.push_back(root->data);
        }
        
        if(root->right->right == NULL and root->right->left == NULL){
            cout<<"Both are null so I am here"<<endl;
            result.push_back(root->right->data);
            cout<<"Pushed Data : "<<root->right->right<<endl;
            rightSideView_(root->left, result,false);
        }

        if(root->right){
            rightSideView_(root->right,result, true);
        }
        else if(root->left){
            rightSideView_(root->left,result, true);
        }
        return;
    }

vector<int> rightSideView(Node* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        rightSideView_(root, result, true);
        return result;
   

void rightSideView_(Node* Left, Node* Right, vector<int> &result){
    if(Right){
        result.push_back(Right->data);
        if(Right->left == NULL and Right->right == NULL and Left !=NULL){
            rightSideView_(Left->left, Left->right, result);
        }else{
            rightSideView_(Right->left, Right->right, result);
        }
    }
    else if(Left){
        result.push_back(Left->data);
        rightSideView_(Left->left, Left->right, result);
    }
    return;
}

vector<int> rightSideView(Node*root){
    vector<int> result;
    if(root == NULL){
        return result;
    }
    result.push_back(root->data);
    rightSideView_(root->left, root->right, result);

    return result;
}
 }*/

 

int main(){
    Node* root = buildLevelOrder();
    cout<<" Tree is build"<<endl;
    vector<int> result = rightSideView(root);

    cout<<"Vector is returned back"<<endl;

    for(auto it = result.begin(); it<result.end(); it++){
        cout<<*it<<" ";
    } 
    return 0;
}