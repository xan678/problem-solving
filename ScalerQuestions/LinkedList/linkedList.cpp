#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "list.h"

using namespace std;

Node* reverseList(Node* A, int B){
    if(A == NULL){
        return NULL;
    }

    int k = B;
    Node* prev = NULL;
    Node* current = A;
    Node* currNext = current->next;

    while(k-- && current != NULL){
        current->next = prev;
        prev = current;
        current = currNext;
        if(currNext != NULL){
            currNext = currNext->next;
        }
    }

    A->next = reverseList(current,B);
    return prev;
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

int main()
{   
    vector<int> array = {1, 2, 3, 4, 5, 6};
    List one;
    Node* A = one.insertArray(array);

    Node* B = reverseList(A, 3);
    //Node* B = reverse(A);
    one.head = B;
    one.printList();
    return 0;
}