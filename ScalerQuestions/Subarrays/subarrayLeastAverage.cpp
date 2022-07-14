#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve(vector<int> &A, int B)
{
    vector<int> prefixSum(A.size());
    prefixSum[0] = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }

    int s = 0;
    int e = s + B - 1;
    double leastAverage = (double)INT_MAX;
    int i = 0;
    while (e < A.size())
    {
        double average;
        if (s == 0) average = (double)(prefixSum[e]);
        else average = double((prefixSum[e] - prefixSum[s - 1]));
        
        if (average <= leastAverage)
        {
            leastAverage = average;
            i = s;
        }

        s++;
        e++;
    }
    return i;
}

int main()
{
    vector<int> A = {20, 3, 13, 5, 10, 14, 8, 5, 11, 9, 1, 11};
    vector<int> A2 = {15, 7, 11, 7, 9, 8, 18, 1, 16, 18, 6, 1, 1, 4, 18};
    cout << solve(A, 9);
    cout << "_______________________________________________________" << endl;
    cout << solve(A2, 6);
    return 0;
}