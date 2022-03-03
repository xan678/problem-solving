#include<iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> countBits(int n) {
        
}

//Discuss Section

vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    
    }

int main(){
    
    return 0;
}