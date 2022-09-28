#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int longestSubarray(vector<int> &nums){
    int maxElement = INT_MIN;

    for(auto x : nums){
        maxElement = max(maxElement, x);
    }

    int i =0;
    int maxSize = INT_MIN;
    while (i<nums.size())
    {
        if(nums[i] == maxElement){
            int size = 0;
           while(i<nums.size()){
                if(nums[i] == maxElement){
                    size++;
                    i++;
                }else{
                    break;
                }
            }
            
            maxSize = max(size,maxSize);
        }
        else{
            i++;
        } 
    }
    return maxSize;
}

int main()
{
    vector<int> nums = {25,25};
    cout<<longestSubarray(nums);
    //int p = 5 & 2;
    //cout<<p<<endl;
    return 0;
}