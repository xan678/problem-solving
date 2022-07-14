#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve(vector<int> &A)
{
    vector<int> prefixEven(A.size());
    vector<int> prefixOdd(A.size());

    prefixEven[0] = A[0];
    prefixOdd[0] = 0;
    for (int i = 1; i < A.size(); i++)
    {
        if (i % 2 == 0)
        {
            prefixEven[i] = prefixEven[i-1] + A[i];
            prefixOdd[i] = prefixOdd[i-1];
        }
        else
        {
            prefixOdd[i] = prefixOdd[i-1] + A[i];
            prefixEven[i] = prefixEven[i-1];
        }
    }

    int count =0;
    for(int i =0; i<A.size(); i++){
        
    }

    return count;
}

int main()
{

    return 0;
}