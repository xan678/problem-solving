#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // char s[1000] = {'1', 'a', 'b', 'c', '\0'};

    string myName = " Hello, my name is Ankush OJha.";
    string s;
    getline(cin, s);
    int index = myName.find(s);

    cout << index << endl;

    return 0;
}