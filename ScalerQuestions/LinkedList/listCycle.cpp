#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "list.h"

using namespace std;

Node* detectCycle(Node* A){

    unordered_set<Node*> set;
    Node* temp = A;
    while(temp->next != NULL){
        
        if(set.find(temp) != set.end()){
            return temp;
        }
        set.insert(temp);
        temp = temp->next;
    }

    return NULL;
}

int main()
{
    vector<int> array = {1, 2, 3};
    List one;
    Node* A = one.insertArray(array);

    Node* B = detectCycle(A);
    //Node* B = reverse(A);
    one.head = B;
    one.printList();    
    return 0;
}