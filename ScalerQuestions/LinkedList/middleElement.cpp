#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "list.h"

using namespace std;

int middleElement(Node* A){

    Node* slow = A;
    Node* fast = A;

    while (fast != NULL && fast->next != NULL )
    {   
        slow = slow->next;
        if(fast->next!= NULL){
            fast = fast->next->next;
        }
    }
    return slow->data;
}

int main()
{
    vector<int> array = {1, 6};
    List one;
    Node* A = one.insertArray(array);

    int result = middleElement(A);
    cout<<result<<endl;
   
    return 0;
}