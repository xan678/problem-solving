#include <iostream>
#include <string>
#include "hashtable.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Hashtable<int> h;
    h.insert("Mango", 10);
    h.insert("Apple", 11);
    h.insert("Guava", 12);
    h.insert("Leechi", 15);
    h.insert("Kiwi", 103);
    h.insert("Bannana", 116);
    h.insert("Papaya", 125);
    h.insert("Orange", 140);
    //h.print();

    string key;
    cin >> key;

    if (h.search(key) != NULL)
    {
        //cout << *h.search(key) << endl;
        h.erase(key);
    }
    else
    {
        cout << "Fruit is not present, hence cannot be deleted from the hashtable" << endl;
    }

    h.print();

    return 0;
}
