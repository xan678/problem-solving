#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> stringSearch(string big, string small)
{
    // store the occurrences in the result vector
    vector<int> result = {};
    int index = 0;
    while (index != -1)
    {
        if (!index)
        {
            index = big.find(small);
        }
        else
        {
            index = big.find(small, index + 1);
        }
        if (index != -1)
        {
            result.push_back(index);
        }
    }
    return result;
}

int main()
{
    string bigString = "I liked the movie, acting in movie was great!";
    string smallString = "movie";
    vector<int> result = stringSearch(bigString, smallString);
    for (auto x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}