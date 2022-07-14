#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solveRecursive(string A)
{
    if (A.length() == 1)
        return 1;

    if (A.length() == 2)
    {
        if (A.front() == A.back())
            return 1;
        return 0;
    }

    int recursiveAns = solveRecursive(A.substr(1, A.length() - 2));
    if (recursiveAns == 1 and A.front() == A.back())
        return 1;
    return 0;
}

int solve(string A)
{
    auto start = A.begin();
    auto last = A.end() - 1;

    while (start <= last)
    {
        cout << "Comparing " << *start << " " << *last << endl;
        if (*start != *last){
            return 0;
        }
        start++;
        last--;
    }
    return 1;
}

int main()
{
    string a = "abcba";
    cout << solve(a) << endl;
    return 0;
}