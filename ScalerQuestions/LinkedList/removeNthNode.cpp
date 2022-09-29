#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "list.h"

using namespace std;

Node* removeNthNodeFromEnd(Node* A, int B){
    Node* slow = A;
    Node* fast = A;

    while (B != 0 && fast != NULL)
    {   
        fast = fast->next;
        B--;
    }
    
    if(fast == NULL){
        return NULL;
    }

    while (fast->next!= NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    slow->next = slow->next->next;
    return A;
}

int main()
{
    vector<int> array = {1, 6, 7, 8, 10, 12, 2, 11};
    List one;
    Node* A = one.insertArray(array);

    Node* result = removeNthNodeFromEnd(A,4);
    
    one.head = result;
    one.printList();
    return 0;
}