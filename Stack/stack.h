template <typename T>
class Stack;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        data = d;
    }
};

template <typename T>
class Stack
{

private:
    Node<T> *head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(T data)
    {
        Node<T> *n = new Node<T>(data);
        n->next = head;
        head = n;
    }

    bool empty(){
        return head == NULL :
    }

    T top()
    {
        return head->data;
    }

    void pop()
    {
        if (head != NULL)
        {
            Node<T> *temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }
};