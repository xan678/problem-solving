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

int main()
{
    vector<int> first = {5, 5 ,5};
    vector<int> second = {5, 5, 5};

    List one;
    List two;

    Node* A = one.insertArray(first);
    Node* B = two.insertArray(second);

    Node* C = NULL;
    List res;
    Node* result = mergeTwoLists(A,B);
    res.head = result;
    res.printList();
    return 0;
}