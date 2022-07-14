#include<iostream>
#include <vector>
#include <string>
using namespace std;

static string letters = "/ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int numDecodingsSomething(string s) {

    if(s.size() == 1){
        return 1;
    }

    int left =0 , right = 0;
    if(s.size() >1 and s[0] != '0') left = numDecodingsSomething(s.substr(1));

    if(s.size() > 2){
        string element = s.substr(0,2);
        if(element <= "26" and element[0] != '0'){
            right = numDecodingsSomething(s.substr(2));
        }
    }
    return  left + right;   
}

int numDecodings(string s){
    int n = s.length();
    vector<int> nums(n);
    vector<int> dp(nums.size()+1,1);
    
    for(char ch : s)nums.push_back(ch - '0');
    if(nums[n-1] > 0 and nums[n-1] < 9) dp[n-1]= 1;
    
    for(int i = n-2; i >=0; i--){
        int count = 0;
        if(nums[i] > 0 and nums[i] < 9) count++;
        if()
    }


    return dp[0];
}

int main(){
    string abc = "1000";
    cout<<numDecodings(abc)<<endl;   
    return 0;
}