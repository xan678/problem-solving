#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve(const vector<vector<int>> &A)
{
    int n = A.size();
    int sum = 0;
    int i = 0;
    int j = n - 1;

    while (i <= n-1 and j>=0)
    {
        sum += A[i][j];
        j--;
        i++;
    }
    return sum;
}

int main()
{
    const vector<vector<int>> A = {
        {1, -2, -3},
        {-4, 5, 6},
        {-7, -8, 9}};
    cout << solve(A);
    return 0;
}