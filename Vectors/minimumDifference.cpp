#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

pair<int, int> minDifference(vector<int> a, vector<int> b)
{
    // Complete this method
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = INT_MAX;
    pair<int, int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        int temp = abs(a[i] - b[j]);
        ans = min(ans, temp);
        if (min(ans, temp) == temp)
        {
            ans = min(ans, temp);
            res.first = a[i];
            res.second = b[j];
        }
        if (a[i] <= b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return res;
}

int main()
{
    // vector<int> arr1{23, 5, 10, 17, 30};
    // vector<int> arr2{26, 134, 135, 14, 19};

    vector<int> arr1{3, -4, 6, 7, 12, 2};
    vector<int> arr2{-2, 8, 16, 5, 18, 21};

    pair<int, int> result = minDifference(arr1, arr2);
    cout << result.first << " and " << result.second << endl;
    return 0;
}