#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int count(const vector<int> &A, int mid){

    int elements = 0;
    for(auto x : A){
        if(x <= mid){
            elements++;
        }
    }

    return elements;
}

int solve(const vector<int> &A, int B){

    int minElement = INT_MAX;
    int maxElement = INT_MIN;

    for(auto x : A){
        minElement = min(x, minElement);
        maxElement = max(x, maxElement);
    }
    int start = minElement;
    int end = maxElement;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end -start)/2;

        int elements = count(A,mid);
        if(elements >= B){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> A = { 8, 16, 80, 55, 32, 8, 38, 40, 65, 18, 15, 45, 50, 38, 54, 52, 23, 74, 81, 42, 28, 16, 66, 35, 91, 36, 44, 9, 85, 58, 59, 49, 75, 20, 87, 60, 17, 11, 39, 62, 20, 17, 46, 26, 81, 92 };
    int B = 9;

    cout<<solve(A,B)<<endl;
    return 0;
}