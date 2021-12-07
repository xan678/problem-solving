#include <iostream>
#include <vector>
using namespace std;

// vector are passed by value
// arrays on the other hand are passed by reference

int main(int argc, char const *argv[])
{
    // Demo

    vector<int> arr = {1, 2, 3, 10, 14, 15};

    // push_back insert in O(1)
    arr.push_back(8);

    // Size of the array
    cout << arr.size() << endl;

    // Capacity of the vector
    cout << arr.capacity() << endl;

    // pop_back in o(1)
    arr.pop_back();

    // Fill constructor
    vector<int> arr2(10, 7);

    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }

    //////////////////////////////////////////////////////////
    // 2D Vector

    // Here each row can have multiple elements
    vector<vector<int>> arr3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9, 10},
        {11, 12, 13, 14}};

    for (int i = 0; i < arr3.size(); i++)
    {
        for (auto number : arr3[i])
        {
            cout << number << " ";
        }
        cout << endl;
    }
    return 0;
}
