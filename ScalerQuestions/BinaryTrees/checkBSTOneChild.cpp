#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

string solve(vector<int> &A){

    int leftMin = INT_MIN;
    int leftMax = A[0];

    int rightMin = A[0];
    int rightMax = INT_MAX;

    for(int i = 1; i<A.size(); i++){
        int currElement = A[i];
        if(currElement >= leftMin && currElement <= leftMax){
            rightMax = leftMax;
            leftMax = currElement;
            rightMin = leftMax;
            continue;
        }
        else if (currElement >= rightMin && currElement<= rightMax){
            leftMin = rightMin;
            leftMax = currElement;
            rightMin = currElement;
            continue;
        }

        return "NO";
    }

    return "YES";
}

int main()
{
    vector<int> A = {1, 5, 6, 4};
    cout<<solve(A);
    return 0;
}