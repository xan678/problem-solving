#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "list.h"

using namespace std;

static int length = 0;

Node* insertAtHead(Node*head, int A){
    Node* temp = new Node(A);
    temp->next = head;
    head = temp;
    length++;
    return head;
}

Node* insertAtLast(Node* head, int B){
    if(head == NULL){
        length++;
        return new Node(B);
    }

    Node* temp = new Node(B);

    Node* curr = head;

    while(curr->next != NULL){
        curr = curr->next;
    }

    curr->next = temp;
    length++;
    return head;
}

Node* insertAtIndex(Node* head, int A, int i){
    if(i > length){
        return head;
    }

    if(i == length){
        return insertAtLast(head, A);
    }

    int k = 1;
    Node* temp = head;

    while (k < i)
    {
        temp = temp->next;
        k++;
    }

    Node* newNode = new Node(A);
    newNode->next = temp->next;
    temp->next = newNode;
    length++;
    return head;
}

Node* deleteAtIndex(Node* head, int i){
    if(i > length){
        return head;
    }

    if(i == 0){
        head = head->next;
        length--;
        return head;
    }
    
    int k = 1;
    Node* temp = head;
    while(k<i){
        temp = temp->next;
        k++;
    }
    length--;
    temp->next = temp->next->next;
    return head;
}

Node* solve(vector<vector<int>> &A){

    Node* head = NULL;

    for(auto x : A){
        int flag = x[0] + x[2];
        switch (flag)
        {
        case -1:
            head = insertAtHead(head,x[1]);
            break;
        case 0:
            head = insertAtLast(head, x[1]);
            /* code */
            break;
        case 2:
            /* code */
            head = deleteAtIndex(head, x[1]);
            break;
        default:
            head = insertAtIndex(head, x[1], x[2]);
            break;
        }
    }

    return head;
}

int main()
{
    vector<vector<int>> A = {
        {0, 1, -1},
        {1, 2, -1},
        {2, 3, 1},
        {0, 4, -1},
        {3, 1, -1},
        {3, 2, -1}
    };

    List one;
    one.head = solve(A);
    one.printList();
    cout<<length<<endl;
    return 0;
}