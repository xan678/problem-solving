//Hashtable
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node
{
public:
    string key;
    T value;
    Node *next;

    Node(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <typename T>
class Hashtable
{
private:
    Node<T> **table;
    int cs;
    int ts;

    int hashFn(string key)
    {
        int idx = 0;
        int pow = 1;
        for (auto ch : key)
        {
            idx = (idx + ch * pow) % ts;
            pow = (pow * 29) % ts;
        }
        return idx;
    }

    void rehash()
    {
        Node<T> **oldTable = table;
        table = new Node<T> *[2 * ts + 1];

        int oldTs = ts;
        ts = 2 * ts + 1;
        cs = 0;
        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }

        for (int i = 0; i < oldTs; i++)
        {
            Node<T> *temp = oldTable[i];

            while (temp != NULL)
            {
                string key = temp->key;
                T value = temp->value;

                insert(key, value);
                temp = temp->next;
            }

            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

public:
    Hashtable(int default_size = 7)
    {
        cs = 0;
        ts = default_size;
        table = new Node<T> *[ts];

        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, T val)
    {
        int idx = hashFn(key);

        Node<T> *n = new Node<T>(key, val);

        //Insertion to the head of the linkList
        n->next = table[idx];
        table[idx] = n;
        cs++;

        float load = cs / float(ts);
        if (load > 0.7)
        {
            rehash();
        }
    }

    void print()
    {
        for (int i = 0; i < ts; i++)
        {
            cout << "Current Bucket " << i << endl;
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << " : " << temp->value << endl;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    bool isPresent(string key)
    {
        int idx = hashFn(key);
        Node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    // if the object is present we return the address of the object, else we return a NULL object
    T *search(string key)
    {
        int idx = hashFn(key);

        Node<T> *temp = table[idx];

        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return &temp->value; //address is given by the & operator
            }
            temp = temp->next;
        }
        return NULL;
    }

    void erase(string key)
    {
        if (isPresent(key))
        {
            //
            int idx = hashFn(key);
            Node<T> *temp = table[idx];
            //Removing first element
            if (temp->key == key)
            {
                table[idx] = temp->next;
                temp->next = NULL;
                delete temp;
                return;
            }
            else
            { //deleting the element if present betweent the start and the end of the link list
                Node<T> *prev;
                while (temp->next != NULL)
                {
                    if (temp->key == key)
                    {
                        prev->next = temp->next;
                        temp->next = NULL;
                        delete temp;
                        return;
                    }
                    prev = temp;
                    temp = temp->next;
                }
                //deleting the element if present at the end of the element
                if (temp->key == key)
                {
                    prev->next = NULL;
                    delete temp;
                    return;
                }
            }
        }
        return;
    }

    //returning by reference
    &T operator[](string key)
    {
        // return value
        T *valueFound = search(key);
        if (valueFound == NULL)
        {
            T object;
            insert(key, object);
            valueFound = search(key);
        }
        return *valueFound;
    }
};
