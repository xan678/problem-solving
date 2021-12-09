#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countMinSwaps(vector<int> arr)
{
    int ans = 0;
    // Know the actual positions of elements (sorting)
    // Store the current indices
    int n = arr.size();
    vector<pair<int, int>> ap;
    for (int i = 0; i < n; i++)
    {
        ap.push_back({arr[i], i});
    }

    // sorting
    sort(ap.begin(), ap.end());

    // building the main logic
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        int temp = ap[i].second;
        if (visited[i] == true || i == temp)
        {
            continue;
        }
        int count = 0;
        int node = i;
        while (visited[node] == false)
        {
            visited[node] = true;
            node = ap[node].second;
            count++;
        }
        ans += count - 1;
    }

    return ans;
}

int main()
{
    vector<int> arr{10, 11, 5, 4, 3, 2, 1};
    cout << countMinSwaps(arr) << endl;
    return 0;
}