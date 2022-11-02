#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int removeDuplicates(vector<int> & nums){
    int i = 0, j = 1;

    while(i<nums.size() && j<nums.size()){
        if(nums[i] != nums[j]){
            i = j;
            j = i + 1;
            continue;
        }

        nums[j] = -102;
        j++;
    }

    for(auto it = nums.begin(); it<nums.end(); it++) {
        if(*it == -102){
            nums.erase(it);
            it = nums.begin();
        }
    }

    return nums.size();
}


int solve(vector<int> & A){
    int count = 0;
    int n = A.size();
    for(int i = 1; i < n; i++){
        if(A[i] == A[i-1]) {
            count++;
        }
        else {
            A[i-count] = A[i];
        }
    }
    return n-count;
}
int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout<<solve(nums);
    return 0;
}