#include <iostream>
#include <vector>
using namespace std;

bool outOfOrder(vector<int> arr, int idx)
{
    int x = arr[idx];
    if (idx == 0)
    {
        return x > arr[1];
    }
    if (idx == arr.size() - 1)
    {
        return x < arr[idx - 1];
    }

    return x > arr[idx + 1] || x < arr[idx - 1];
}

pair<int, int> subArraySort(vector<int> arr)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        int x = arr[i];
        if (outOfOrder(arr, i))
        {
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
    }
    cout << smallest << " " << largest << endl;
    // Now find the right index where smallest and the largest should be present so that the entire array get's sorted
    if (smallest == INT_MAX)
    {
        return {-1, -1};
    }

    int left = 0;
    while (smallest >= arr[left])
    {
        left++;
    }
    int right = arr.size() - 1;
    while (largest <= arr[right])
    {
        right--;
    }

    return {left, right};
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto p = subArraySort(arr);
    cout << p.first << " and " << p.second << endl;
    return 0;
}