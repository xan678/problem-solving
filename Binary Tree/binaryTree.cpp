#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//Making a tree in Pre order

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

//Fuction Approach : Preorder build of the tree
//First build the root node, then left tree and at last the right tree, -1 in the input means NULL

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

//Functional Approach : Level Order build of the tree
// -1 in the input means NULL


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


//Pre Order traversal
void printPreorder(Node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<"-->";
    printPreorder(root->left);
    printPreorder(root->right);

}

//Inorder Traversal

void printInorder(Node *root){
    if(root == NULL){
        return;
    }    
    printInorder(root->left);
    cout<<root->data<<"-->";
    printInorder(root->right);

}

//Post order Traversal, This is also called Bottom up traversal

void printPostorder(Node *root){
    if(root == NULL){
        return;
    }

    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<"-->";

    return;
}

//Level order traversal
//We use recursive structure for Depth first search, but here we need to implement breadth first search
//That's why we will use another data structure, ie Queue

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

//Height of Tree

int heightOfTree(Node* root){
    if(root == NULL){
        return 0;
    }
    int h1 = heightOfTree(root->left);
    int h2 = heightOfTree(root->right);
    return 1+ max(h1, h2);
}

//Sum of All Nodes using DFS Approach (Pre order approach)

int sumOfAllNodes(Node* root){

    if(root == NULL){
        return 0;
    }

    int h1 = sumOfAllNodes(root->left);
    int h2 = sumOfAllNodes(root->right);

    return root->data + h1 + h2;
}

//Kth Level

vector<int> printKthLevel(Node* root, int k){
    
   vector<int> result;
    queue<Node*> q;

    q.push(root);
    q.push(NULL);
    
    int m = -1;
    
    while(!q.empty()){
        Node* current  = q.front();
        q.pop();
        if(current == NULL){
            m = m+1;
            q.push(NULL);
           
        }
        if(m == k-1){
            while(q.front()!=NULL){
                //result.push_back(q.front()->key);
                result.insert(result.begin(), q.front()->data);
                q.pop();
            }
            return result;
        }else{
            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
        }
    }
    
    return result;
}

void pushInorder(Node* root, vector<int> &result){
    if(root == NULL){
        return ;
    }
    pushInorder(root->left,result);
    result.push_back(root->data);
    pushInorder(root->right,result);

    return;
}

bool isBST(Node* root){
    vector<int> inorder ;
    pushInorder(root, inorder);
    bool result = true;
    for(auto it = inorder.begin(); it<inorder.end()-1;it++){
        if(*it > *(it+1)){
            return false;
        }
    }

    return true;
}


int main(){
    Node* root = buildLevelOrder();
    /*cout<<"Pre Order Traversal"<<endl;
    printPreorder(root);
    cout<<endl;
    cout<<"In Order Traversal"<<endl;
    printInorder(root);
    cout<<endl;
    cout<<"Post Order Traversal"<<endl;
    printPostorder(root);
    cout<<endl;*/
    cout<<"Level Order Traversal"<<endl;
    printLevelorder(root);
    // cout<<"Height of the Tree is : ";
    // cout<<heightOfTree(root);

    // vector<int> result = printKthLevel(root,1);

    // for(int i : result){
    //     cout<<i<<" ";
    // }
    // return 0;
    //printInorder(root);
    cout<<endl<<isBST(root)<<endl;

}