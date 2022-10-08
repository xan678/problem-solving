#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "list.h"

using namespace std;

Node* mergeTwoLists(Node* A, Node * B){
    if(A == NULL) return B;
    if(B == NULL) return A;
    
    Node* result;
    Node* head = NULL;
    Node* temp1 = A;
    Node* temp2 = B;

    while (temp1 != NULL && temp2 != NULL)
    {
        bool flag = temp1->data <= temp2->data;
        if(flag){
            if(head == NULL){
             head = temp1;
             result = head;
            }
            else{
                head->next = temp1;
                head = head->next;
            }
            temp1 = temp1->next;
        }else{
            if(head == NULL) {
                head = temp2;
                result = head;
            }
            else{
                head->next = temp2;
                head = head->next;
            }
            temp2 = temp2->next;
        }
    }

    if(temp1 != NULL) head->next = temp1;
    if(temp2 != NULL) head->next = temp2;

    return result;
}

Node* middleElement(Node* A){
    if(A->next->next == NULL){
        return A;
    }
    Node* slow = A;
    Node* fast = A;

    while(fast != NULL && fast->next!= NULL){
        slow = slow->next;

        if(fast->next != NULL){
            fast = fast->next->next;
        }
    }

    return slow;
}

Node* sortList(Node* A){
    
    if(A == NULL || A->next == NULL){
        return A;
    }

    Node* m = middleElement(A);
    Node * h2 = m->next;
    m->next = NULL;
    A= sortList(A);
    h2 = sortList(h2);

    return mergeTwoLists(A,h2);
}

int main()
{
    vector<int> array = {1};
    List one;
    Node* A = one.insertArray(array);
    one.printList();
    one.head = sortList(A);


    one.printList();
    
    // Node* res = middleElement(A);
    // cout<<res->data;
    return 0;
}