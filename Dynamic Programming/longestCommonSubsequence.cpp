#include<iostream>
#include <vector>
#include <string>
using namespace std;


//To Do
int lengthofLISTopDown(vector<int>& nums){

}

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    int maxNum = INT_MIN;
    for(int i = 0; i< dp.size(); i++){
        int count = -1;
        for(int j = 0; j< i; j++){
            if(nums[j]<= nums[i]){
                count = max(count,dp[j]);
            }
        }
        dp[i] = 1 + count;
        maxNum = max(dp[i], maxNum);
    }
    return maxNum + 1;
}

int main(){
    
    vector<int> arr{50,4,10,8,30,100};
    cout<<lengthOfLIS(arr);
    return 0;
}