#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> arr)
{
    // Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
    int currentSum = 0;
    int maxSum = INT_MIN;
    for (auto x : arr)
    {
        currentSum += x;
        if (currentSum < 0)
        {
            currentSum = 0;
        }
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main()
{
    vector<int> arr{-1, 2, 3, 4, -2, 6, -8, 3};
    cout << maxSubarraySum(arr) << endl;
    return 0;
}