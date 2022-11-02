#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
    unordered_map<int, int> map;
    vector<int> result;
    for(int i = 0; i<nums.size(); i++){
        int numToFind = target - nums[i];

        if(map.find(numToFind) != map.end()){
            result.push_back(map[numToFind]);
            result.push_back(i);
            return result;
        }

        map.insert(make_pair(nums[i],i));
    }

    return result;
  
}

int main()
{
    vector<int> temp = {8,7,3,4,2,8,9,0,5,7,2,3,9,8,6,7,2,3,9,4,8};
    vector<int> result = twoSum(temp, 16);
    for(auto x : result) cout<<x<<" ";
    cout<<endl;
    return 0;
}