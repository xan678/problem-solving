#include <iostream>
#include <vector>
using namespace std;

int highest_mountain(vector<int> arr)
{
    int n = arr.size();
    int largest = 0;
    int width = -1;

    for (int i = 1; i <= n - 2; i++)
    {
        // Check if a[i] is peak or not;
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            // do some work
            int cnt = 1;
            // cnt backwards (left)
            int j = i;
            while (j >= 1 && arr[j] > arr[j - 1])
            {
                cnt++;
                j--;
            }
            // cnt forward (right)
            while (i <= n - 2 && arr[i] > arr[i + 1])
            {
                cnt++;
                i++;
            }

            if (cnt > width)
            {
                width = cnt;
            }
        }
        // else
        // {
        //     i++;
        // }
    }

    return width;
}

int main()
{
    vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout << highest_mountain(arr) << endl;
    return 0;
}