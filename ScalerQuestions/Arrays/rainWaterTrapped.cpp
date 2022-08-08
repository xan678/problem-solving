#include<iostream>
#include<string>
#include<vector>

using namespace std;

void display(vector<int> &A){
    for(auto x : A){
        cout<<x<<" ";
    }

    cout<<endl;
}

int solve(const vector<int> &A){
    vector<int> leftMax(A.size(),0);
    vector<int> rightMax(A.size(),0);
    int maxE = INT_MIN;
    int minE = INT_MIN;
    for(int i = 1;i<A.size(); i++){
        maxE = max(maxE, A[i-1]);
        leftMax[i] = maxE;
    }

    for(int i = A.size()-2; i>= 0; i--){
        minE = max(minE,A[i+1]);
        rightMax[i] = minE;
    }

    int count = 0;
    for(int i = 0; i<A.size();i++){
        int temp = min(leftMax[i],rightMax[i]) - A[i];

        if(temp>0){
            count+=temp;
        }
    }
    return count;

}

int main()
{
    vector<int> A = {4,2,5,7,4,2,3,6,8,2,3};
    cout<<solve(A);   
    return 0;
}