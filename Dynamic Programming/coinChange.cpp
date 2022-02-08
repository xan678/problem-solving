#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

// bottom up DP
int minNumberOfCoinsForChange(int n, vector<int> denoms)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
        for (int c : denoms)
        {
            if (i - c >= 0 && dp[i - c] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    return dp[n] == INT_MAX ? -1 : dp[n];
}

//Top down dp

int coinChange(vector<int>& coins, int amount) {
    if(amount == 0){
        return 0;
    }
    if(amount<0){
        return INT_MAX;
    }
    

}

int main()
{
    vector<int> denoms = {1, 5, 7, 10};
    int n;
    cin >> n;

    cout << minNumberOfCoinsForChange(n, denoms) << endl;
    return 0;
}