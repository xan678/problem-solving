#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // char s[1000] = {'1', 'a', 'b', 'c', '\0'};

    string s;
    getline(cin,s,'.');
    cout << s;

    return 0;
}