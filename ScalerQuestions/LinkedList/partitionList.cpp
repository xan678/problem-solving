#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "list.h"

using namespace std;


Node* partition(Node* A, int B){
    Node* head = A;
    Node * ins;
    Node* curr;

    if(A->data >= B){
        ins = new Node(-1);
        ins->next = A;
        curr = ins;
    }else{

        ins = A;
        curr = ins;
        head = ins->next;
    }
    while (curr->next!= NULL)  
    {   
        if(curr->next->data < B){
            Node* temp = curr->next;
            curr->next = temp->next;
            temp->next = ins->next;
            ins->next = temp;
            ins = ins->next;
        }
        if(curr->next!= NULL){
            curr = curr->next;
        }
    }

    return head->data == -1? head->next : head;
}

int main()
{
    vector<int> array = {3,4,1,1,1,2};
    List one;
    Node* A = one.insertArray(array);

    Node* B = partition(A,2);
    //Node* B = reverse(A);
    one.head = B;
    one.printList();
    return 0;
}