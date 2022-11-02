#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

vector<int> plusOne(vector<int> & digits){
    int carry = 1;
    int i = digits.size()-1;
    while(i >=0 ){
        if(carry == 0) break;
        int currentDigit = digits[i];
        digits[i] = (currentDigit + carry) % 10;
        carry = (currentDigit + carry) /10;
        i--;
    }
    if(carry != 0) digits.insert(digits.begin(), carry);
    return digits;
}

int main()
{
    vector<int> digits = {4,3,2,1};
    vector<int> result = plusOne(digits);
    for(auto x : result) cout<< x<<" ";
    cout<<endl;
    return 0;
}