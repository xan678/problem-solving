#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "list.h"


using namespace std;

Node* middleElement(Node* A){
    Node* slow = A;
    Node* fast = A;

    while(fast->next != NULL && fast->next->next!= NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* reverse(Node* A){
    if(A->next == NULL){
        return A;
    }
    Node* prev = A;
    Node* curr = prev->next;
    Node* currNext = curr->next;

    prev->next = NULL;
    while (curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = currNext;
        if(currNext!= NULL){
            currNext = currNext->next;
        }
    }
    return prev;
}

int lPalin(Node* A) {

    Node* middle = middleElement(A);
    Node* h2 = middle->next;
     h2 = reverse(h2);
    middle->next = NULL;

    Node* h1 = A;
    cout<<"Everything good till here"<<endl;
    while (h1!= NULL && h2!= NULL)
    {
        cout<<"I am in the loop comparing"<<h1->data<<" "<<h2->data<<endl;
        if(h1->data != h2->data){
            return 0;
        }    
        h1 = h1->next;
        h2 = h2->next;
    }
    
    return 1;
}

int main()
{   
    vector<int> A = {1,2};
    List one;
    Node* e = one.insertArray(A);
    cout<<lPalin(e)<<endl;
    return 0;
}