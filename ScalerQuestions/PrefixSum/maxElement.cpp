#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve(vector<int> &A)
{
    int maxElement = INT_MIN;

    for (int i = 0; i < A.size(); i++)
    {
        maxElement = (maxElement < A[i]) ? A[i] : maxElement;
    }
    cout << maxElement << endl;

    int ans = 0;
    for (auto x : A)
    {
        ans += (maxElement - x);
    }

    return ans;
}

int main()
{
    vector<int> A = {731, 349, 490, 781, 271, 405, 811, 181, 102, 126, 866, 16, 622, 492, 194, 735};
    cout << solve(A) << endl;
    return 0;
}