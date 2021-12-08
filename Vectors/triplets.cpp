#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int sum)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;

    for (int i = 0; i < arr.size() - 2; i++)
    {
        int j = i + 1;
        int k = arr.size() - 1;
        // Two pointer approach to solve the pair sum problem
        while (j < k)
        {
            int current_sum = arr[i];
            current_sum += arr[j];
            current_sum += arr[k];

            if (current_sum > sum)
            {
                k--;
            }
            else if (current_sum < sum)
            {
                j++;
            }
            else
            {
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int Sum = 18;
    auto result = triplets(arr, Sum);

    for (auto x : result)
    {
        for (auto number : x)
        {
            cout << number << " ";
        }
        cout << endl;
    }
    return 0;
}