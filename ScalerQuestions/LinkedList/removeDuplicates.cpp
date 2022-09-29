#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "list.h"

using namespace std;

Node* deleteDuplicates(Node* A){
    Node* temp = A;

    while (temp != NULL)
    {
        Node* flag = temp;

        while(flag->next != NULL  && flag->data == flag->next->data){
            flag = flag->next;
        }

        temp->next = flag->next;
        temp = temp->next;  
    }

    return A;
    
}

int main()
{
    vector<int> array = {1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,5,5,5,5,5,5};
    List one;
    Node* A = one.insertArray(array);

    Node* result = deleteDuplicates(A);
    
    one.head = result;
    one.printList();
    
    return 0;
}