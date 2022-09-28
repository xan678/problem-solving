#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "list.h"

using namespace std;

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

int main()
{   
    vector<int> first = {3, 1, };
    vector<int> second = {9, 8, 2, 4};

    List one;
    List two;

    Node* A = one.insertArray(first);
    Node* B = two.insertArray(second);

    List res;
    Node* result = mergeZigZag(A,B);
    res.head = result;
    res.printList();
    return 0;
}