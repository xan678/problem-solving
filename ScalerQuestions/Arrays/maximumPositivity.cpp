#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> sovle(vector<int> &A)
{
    int s = 0;
    int e = 0;
    int maxS = 0;
    int maxE = 0;
    long maxL = INT_MIN;
    while (s < A.size() and e < A.size()+1)
    {
        if (A[s] < 0)
        {
            s++;
            e = s;
            continue;
        }
        if (A[e] < 0 || e == A.size())
        {

            if (maxL < e - s - 1)
            {
                maxL = e - s - 1;
                maxS = s;
                maxE = e - 1;
            }

            e++;
            s = e;
            continue;
        }
        e++;
    }

    vector<int> result;
    while (maxS <= maxE)
    {
        result.push_back(A[maxS]);
        maxS++;
    }
    return result;
}

int main()
{
    // vector<int> A = {-5173778, -8176176, 1694510, 7089884, -1394259, 1146372, -2502339, 1544618, 6602022, 4330572};
    // vector<int> A = {-5173778, -8176176, 1694510, 7089884, -1394259, 1146372, -2502339, 1544618, 6602022, 4330572};
    vector<int> A = {-4549634, -3196682, 8455838, -1432628, -263819, -3928366, -5556259, -2114783, 3923939, -4183708 };
    vector<int> result = sovle(A);
    for (auto x : result)
    {
        cout << x << " ";
    }
    return 0;
}