#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

#define MOD 1000000007
int dp[32][1002];

int numRollstToTarget(int n, int k, int target){

    if(n == 0 && target == 0) return 1;
    if(n == 0 && target <0) return 0;
    if(dp[n][target] != -1) return dp[n][target];

    int sum = 0;
    for(int i = 1; i<= k; i++){
        sum = (sum%MOD + numRollstToTarget(n-1, k, target-i)%MOD) %MOD;
    }
    dp[n][target] = sum;
    return sum;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    return 0;
}