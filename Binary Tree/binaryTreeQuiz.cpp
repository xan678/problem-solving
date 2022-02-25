#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node{
    int key;
    Node *left, *right;
    
    Node(int data){
        key = data;
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
            cout<<element->key<<" ";
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
                result.insert(result.begin(), q.front()->key);
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


//New approach, I watched the solution , here this guys is traversing level by level.
//Good approach, should use this in all the question that require level order traversal

vector<int> printKthLevel2(Node* root, int k){
    // your code goes here
    // Create Queue
    queue<struct Node*> que;
 
    // Enqueue the root node
    que.push(root);
 
    // Create a set
    vector<int> s;
 
    // Level to track
    // the current level
    int level = 0;
    int flag = 0;
 
    // Iterate the queue till its not empty
    while (!que.empty()) {
 
        // Calculate the number of nodes
        // in the current level
        int size = que.size();
 
        // Process each node of the current
        // level and enqueue their left
        // and right child to the queue
        while (size--) {
            struct Node* ptr = que.front();
            que.pop();
 
            // If the current level matches the
            // required level then add into set
            if (level == k) {
 
                // Flag initialized to 1
                flag = 1;
 
                // Inserting node data in set
                s.push_back(ptr->key);
            }
            else {
 
                // Traverse to the left child
                if (ptr->left)
                    que.push(ptr->left);
 
                // Traverse to the right child
                if (ptr->right)
                    que.push(ptr->right);
            }
        }
 
        // Increment the variable level
        // by 1 for each level
        level++;
 
        // Break out from the loop
        // if the Kth Level is reached
        if (flag == 1)
            break;
    }
    return s;
}

int main() {
    Node* root = buildLevelOrder();
    printLevelorder(root);
    
    vector<int> result = printKthLevel(root,1);
    
    for(int i = 0; i<result.size();i++){
        cout<<result[i]<<" ";
    }
   
    return 0;
}