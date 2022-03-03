#include<iostream>
#include <vector>
#include <string>
using namespace std;

//Recursive Solution
int knapsack(int wts[], int prices [], int N, int W){

    if(N==0 or W==0) return 0;
    
    int left = 0, right = 0;
    if(W > wts[N-1]){
       left = prices[N-1] + knapsack(wts,prices, N-1, W-wts[N-1]);
    }
    right = knapsack(wts, prices,N-1, W);
    return max(left, right);
}

//Recursion plus memoization
int knapsackTopDown(int wts[], int prices[], int N, int W, vector<vector<int>> dp){
    
    if(dp[N][W] != -1) return dp[N][W];
    if(N==0 or W==0) return 0;

    int left = 0, right = 0;
    if(W > wts[N-1]){
       left = prices[N-1] + knapsackTopDown(wts,prices, N-1, W-wts[N-1],dp);
    }
    right = knapsackTopDown(wts, prices,N-1, W,dp);
    dp[N][W] = max(left, right);
    return dp[N][W];
}

//Bottom up dp

int knapsackBottomUp(int wts[], int prices [], int N, int W){
    vector<vector<int>> dp(N+1, vector<int>(W+1,0));

    for(int n= 1; n<=N; n++){
        for(int w = 1; w<=W; w++){
            int inc =0, exc = 0;
            if(wts[n-1] <= w){
                inc = prices[n-1] + dp[n-1][w-wts[n-1]];
            }
            exc = dp[n-1][w];
            dp[n][w] = max(inc, exc);
        }
    }

    return dp[N][W];
}

//Bottom up space optimized

int knapsackBottomUpOpti(int wts[], int prices [], int N, int W){
    vector<vector<int>> dp(2, vector<int>(W+1,0));

    for(int n= 1; n<=N; n++){
        for(int w = 1; w<=W; w++){
            int inc =0, exc = 0;
            if(wts[n-1] <= w){
                inc = prices[n-1] + dp[n-1][w-wts[n-1]];
            }
            exc = dp[n-1][w];
            dp[n][w] = max(inc, exc);
        }
    }

    return dp[N][W];
}


int main(){
    int wts[] = {2,7,3,4};
    int prices[] = {5,20,20,10};

    int N = 4;
    int W = 11;

    //cout<<knapsack(wts, prices, N, W)<<endl;
    vector<vector<int>> dp(N+2, vector<int>(W+2,-1));
    cout<<knapsackTopDown(wts, prices, N , W, dp)<<endl;

    cout<<knapsackBottomUp(wts, prices,N,W);

   
    return 0;
}