#include<iostream>
#include <vector>
#include <string>
using namespace std;

int numberOfArithmeticSlices(vector<int>& nums) {      
    vector<pair<int,int>> dp(nums.size() + 1, make_pair(0,0));
    int sum = 0;
    if(nums[1] - nums[0] == nums[2] - nums[1]){
        dp[2] = {1,nums[1] - nums[0]};
        sum++;
    }
    for(int i = 3; i< nums.size(); i++){
        auto temp = dp[i-1];
        if(nums[i] - nums[i-1] == temp.second){
            dp[i] = {temp.first++, temp.second};
        }
        else if(nums[] - nums [] == nums[] - nums[]) {
            dp[i + 1] = make_pair(1,nums[i] - nums[i-1]);
            i = i+ 1;
        }
        sum += dp[i];
    }

    return sum;
}

int main(){
    
    return 0;
}