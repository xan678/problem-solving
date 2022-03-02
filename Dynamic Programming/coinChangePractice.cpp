#include<iostream>
#include <vector>
#include <string>
using namespace std;


//Top down memoization
int minCoins(vector<int> & coins, int amount, vector<int>& dp){

    if(dp[amount] != INT_MAX-1){
        return dp[amount];
    }
    if(amount < 0){
        return INT_MAX-1;
    }
    //int res = INT_MAX-1;

    for(auto x : coins){
        int calc = minCoins(coins,amount - x,dp);
        dp[amount] = min(dp[amount],calc + 1);
    }
    
    return dp[amount];
}

//Bottom up memoization

int minCoinsBottomup(int m , vector<int> coins){

    vector<int> dp(m+1, 0);
    dp[0] = 0;

    for(int i = 1; i<=m;i++){
        dp[i] = INT_MAX-1;
        for(auto c : coins){
            if(i - c >=0 and dp[i-c] != INT_MAX-1){
              dp[i] = min(dp[i], dp[i-c] + 1);    
            }
        }
    }

    return dp[m] == INT_MAX-1 ? -1 : dp[m];
}

int main(){
    vector<int> coins = {1,3,4,5};
    int amount = 7;

    int size = coins.size();
    vector<int> dp(amount+1, INT_MAX-1);
    dp[0] = 0;
    //cout<<minCoins(coins,amount, dp);

    cout<<minCoinsBottomup(amount, coins)<<endl;

    // for(auto x : dp){
    //     cout<<x<<" ";
    // }
    return 0;
}