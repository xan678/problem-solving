#include <iostream>
#include <vector>
using namespace std;

vector<int> productArray(vector<int> arr)
{

    // Create an output Array
    int n = arr.size();
    vector<int> output(n, 1);

    // update the output array and return
    // complete the code
    vector<int> left(n, 0), right(n, 0);
    left[0] = 1;
    right[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] * arr[i - 1];
        right[n - i - 1] = right[n - i] * arr[n - i];
    }
    for (int i = 0; i < n; i++)
    {
        output[i] = left[i] * right[i];
    }

    return output;
}

int main()
{
    vector<int> arr{-1, 1, 0, -3, 3};
    vector<int> output = productArray(arr);
    for (auto x : output)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}