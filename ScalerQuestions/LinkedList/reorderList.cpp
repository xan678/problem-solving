#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "list.h"

using namespace std;

Node* middleElement(Node *A){
    Node* slow = A;
    Node* fast = A;

    while (fast != NULL && fast->next != NULL )
    {   
        slow = slow->next;
        if(fast->next!= NULL){
            fast = fast->next->next;
        }
    }
    return slow;
}

Node* mergeZigZag(Node* A, Node* B){
    Node* curr1 = A;
    Node* h1 = A;

    Node* curr2 = NULL;
    Node* h2 = B;

    while(h2 != NULL && curr1->next!=NULL){
        curr2 = h2;
        h2 = h2->next;
        curr2->next = curr1->next;
        curr1->next = curr2;
        curr1 = curr2->next;
    }

    if(curr1->next  == NULL){
        curr1->next = h2;
    }

    return h1;
}

Node* reverse(Node* A){
    Node* prev = A;
    Node* current = prev->next;
    Node* currNext = current->next;

    prev->next = NULL;
    while(current!= NULL){

        current->next = prev;
        prev = current;
        current = currNext;
        if(currNext != NULL){
            currNext = current->next;
        }
    }
    return prev;
}

Node* reorderList(Node* A){
    Node* middle = middleElement(A);

    Node* temp = middle->next;
    middle->next = NULL;
    if(temp->next != NULL){
        temp = reverse(temp);
    }
    return mergeZigZag(A, temp);

}

int main()
{
    vector<int> array = {1, 2, 3};
    List one;
    Node* A = one.insertArray(array);

    Node* B = reorderList(A);
    //Node* B = reverse(A);
    one.head = B;
    one.printList();
    return 0;
}