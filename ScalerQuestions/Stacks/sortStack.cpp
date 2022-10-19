#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "stack.h"

using namespace std;

Node<int>* sortStack(Node<int> * head){

    Stack<int> temp;
    while (head != NULL)
    {
        int curr = head->data;
    }
    

}

int main()
{
    Stack<int> s;
    vector<int> arr = {-5, -1, 0, 1, 2, 3, 4, 5, 6};
    for(auto x : arr){
        s.push(x);
    }
    s.head = sortStack(s.head);
    s.display();
    return 0;
}