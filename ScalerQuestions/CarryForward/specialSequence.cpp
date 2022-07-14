#include<iostream>
#include <vector>
#include <string>
using namespace std;

int solve(string A){
    int mod = 1000000007;

    int ans = 0;
    int cg = 0;

    auto x = A.end()-1;
    while(x>=A.begin()){
        if(*x == 'G') cg++;

        if(*x == 'A'){
            ans =  (ans % mod + cg%mod) % mod;
        }
        x--;
    }

    return ans;
}

int main(){

    string A = "ABCGAG";
    cout<<solve(A)<<endl;
    
    return 0;
}