#include <iostream>
#include "linkedlist.h"
using namespace std;

void printList(Node *root)
{
    while (root != NULL)
    {
        cout << root->getData() << " ";
        root = root->getNext();
    }
    return;
}

Node *alternateMerge(Node *root1, Node *root2)
{
    Node *res = root1;
    Node *temp1;
    Node *temp2;
    Node *prev1;
    Node *prev2;

    while (root1 && root2)
    {
        prev1 = root1;
        prev2 = root2;
        temp1 = root1->next;
        temp2 = root2->next;
        root2->next = root1->next;
        root1->next = root2;
        root2 = temp2;
        root1 = temp1;
    }
    if (root2 != NULL && root1 == NULL)
    {
        prev2->next = root2;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> arr1 = {5, 7, 17, 13, 11};
    vector<int> arr2 = {12, 10, 2, 4, 6};

    List one;
    List two;
    Node *root1 = one.insertArray(arr1);
    Node *root2 = two.insertArray(arr2);

    // printList(root1);
    // cout << endl;
    // printList(root2);

    Node *root = alternateMerge(root1, root2);
    printList(root);
    return 0;
}
