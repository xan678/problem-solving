#include<iostream>
#include<string>
#include<vector>

using namespace std;

int solve(vector<int> &A){
    int sum = 0;
    int ans = INT_MIN;
    
    int l,r = 0;
    int lans = l;
    int rans = r;

    for(int i = 0; i<A.size(); i++){
        sum = sum + A[i];
        ans = max(ans, sum);
        if(sum == ans){
            lans = l;
            rans =r;
        }
        r++;
        if(sum < 0){
            sum = 0;
            l = i+1;
            r = l;
        }
    }

    for(int i = lans; i<=rans;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    return ans;    
}

int main()
{
    vector<int> A = {-5,-6,-7,-3,-2,-10,-12,-8,-12,-21,-4,-7};
    cout<<solve(A);
    return 0;
}