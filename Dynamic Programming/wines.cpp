#include<iostream>
#include <vector>
#include <string>
using namespace std;


//Top down dp
int countWines(int l, int r, vector<int> &nums, int y, vector<vector<int>> dp){
    if(l>r) return 0;
    if(dp[l][r] != 0) return dp[l][r];

    int left = nums[l] * y + countWines(l+1, r, nums, y+1, dp);
    int right = nums[r] * y + countWines(l, r-1, nums,y+1, dp);

    return dp[l][r] = max(left,right);
}

//Bottom up dp

int countWinesBU(vector<int> & num, int n){
    vector<vector<int>> dp (n+1, vector<int> (n+1,0));

    for(int i = n-1 ; i >=0 ; i--){
        for(int j = 0; j<n;j++){
            if(i == j){
                dp[i][j] = n*num[i];
            }
            if(i<j){
                int y = n - (j - i);
                int pick_left = y * num[i] + dp[i+1][j];
                int pick_right = y * num[j] + dp[i][j-1];
                dp[i][j] = max(pick_left,pick_right);
            }
            cout<<dp[i][j]<<"   ";
        }
        cout<<endl;
    }
    return dp[0][n-1];  
}

int main(){
    vector<int> nums = {2,3,5,1,4};
    int n =5;
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    cout<<countWines(0, n-1, nums,1, dp)<<endl;
    cout<<countWinesBU(nums,n)<<endl;
    return 0;
}