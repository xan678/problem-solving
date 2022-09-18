#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int maxArea(vector<int> &A){
    int start = 0;
    int end = A.size()-1;
    
    int ans = INT_MIN;

    while(start <= end){
        int height = min(A[start], A[end]);
        int width = abs(start-end);

        int area = height * width;
        ans = max(ans, area);

        if(A[start] == height){
            start++;
            continue;
        }
        if(A[end] == height){
            end--;
            continue;
        }
    }

    return ans;
}

int main()
{
    
    return 0;
}