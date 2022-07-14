#include<iostream>
#include <vector>
#include <string>
using namespace std;
int c = 0;

void changeHelper(int amount, vector<int>& coins) {
    
    if(amount == 0){
        c++;
        return;
    }
    if(amount < 0){
        return;
    }

    for(auto x : coins){
        changeHelper(amount-x, coins);
    }

    return;
}

int change(int amount, vector<int>& coins) {
    vector<bool> dp(coins.size(), false);

    changeHelper(amount, coins);
    return c;
}

int main(){
    vector<int> coins = {1,2,5};
    int amount = 5;

    cout<<change(amount, coins)<<endl;   
    return 0;
}