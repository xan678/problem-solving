#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Top Down
int fib(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

//Bottom up
int fib(int n){
    vector<int> dp(n+1,0);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i<= n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}


int main()
{
    vector<int> dp(10000, 0);
    cout << fib(5, dp) << endl;
    return 0;
}