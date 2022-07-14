#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> solve(vector<int> &A)
{
    vector<int> result;
    int i = A.size() - 2;
    int lastLeader = A[i + 1];
    result.push_back(lastLeader);
    while (i >= 0)
    {
        if (A[i] > lastLeader)
        {
            lastLeader = A[i];
            result.push_back(lastLeader);
        }
        i--;
    }

    return result;
}

int main()
{
    vector<int> A = {16, 17, 4, 3, 5, 2};

    vector<int> result = solve(A);

    for (auto x : result)
    {
        cout << x << " ";
    }
    return 0;
}