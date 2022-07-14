#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve(vector<int> &A)
{
    int countSwitches = 0;
    int res = 0;

    for (auto i = A.begin(); i < A.end(); i++)
    {

        if (*i == 0 and countSwitches % 2 == 0)
        {
            countSwitches++;
            res++;
        }

        if (*i == 1 and countSwitches % 2 != 0)
        {
            countSwitches++;
            res++;
        }
    }

    return res;
}

int main()
{
    vector<int> A = {1, 1, 1, 1};
    cout << solve(A) << endl;
    return 0;
}