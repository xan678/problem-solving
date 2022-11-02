#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    vector<int> result;

    int i = 0, j = 0;

    while(i < m && j < n){
        if(nums1[i] <= nums2[j] ) {
            result.push_back(nums1[i]);
            i++;
        }else{
            result.push_back(nums2[j]);
            j++;
        }
    }

    while(i<m){
        result.push_back(nums1[i]);
        i++;
    }

    while(j<n){
        result.push_back(nums2[j]);
        j++;
    }

    for(int i = 0; i<nums1.size(); i++){
        nums1[i] = result[i];
    }
}

int main()
{
    return 0;
}