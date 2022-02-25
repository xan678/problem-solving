#include <iostream>
#include <vector>
using namespace std;

//Forward Declaration
class List;

class Node
{
public:
    int data;
    Node *next;

    Node(int d) : data(d), next(NULL) {}

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
    int getData()
    {
        return this->data;
    }

    Node *getNext()
    {
        return this->next;
    }
    friend class List;
};

class List
{
    Node *head;
    Node *tail;

public:
    List() : head(NULL), tail(NULL) {}

    ~List()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
        return;
    }

    void pop_front()
    {
        if (head == NULL)
        {
            return;
        }

        Node *temp;
        temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

        return;
    }

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->getData() << " --> ";
            temp = temp->next;
        }
        cout << endl;
        return;
    }
    Node *begin()
    {
        return head;
    }

    Node *end()
    {
        return tail;
    }

    void push_front(int data)
    {
        if (head == NULL)
        {
            Node *n = new Node(data);

            head = tail = n;
            return;
        }

        Node *n = new Node(data);
        n->next = head;
        head = n;
        return;
    }
    void push_back(int data)
    {
        if (head == NULL)
        {
            Node *n = new Node(data);

            head = tail = n;
            return;
        }

        Node *n = new Node(data);
        tail->next = n;
        tail = n;
    }

    Node *insertArray(vector<int> &arr)
    {
        for (auto x : arr)
        {
            push_back(x);
        }

        return head;
    }
    void insert(int data, int pos)
    {
        if (pos == 0)
        {
            push_front(data);
            return;
        }

        Node *n = new Node(data);
        Node *temp = head;
        int i = 0;

        while (head != NULL && i != pos - 1)
        {
            temp = temp->next;
            i = i + 1;
        }

        n->next = temp->next;
        temp->next = n;

        return;
    }

    int searchHelper(int data, Node *head, int idx)
    {
        if (head == NULL)
        {
            return -1;
        }
        if (head->data == data)
        {
            return idx;
        }

        return searchHelper(data, head->next, idx + 1);
    }

    int searchRecursive(int data)
    {
        return searchHelper(data, head, 0);
    }
};