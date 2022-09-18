#include<iostream>
#include<string>
#include<vector>

using namespace std;

int findMod(string A, int B){
    long num  = 0;
    int mul = 1 % B;
    int i = 0;
    while(i<A.size()){
        int digit = (A.at(A.size()-i-1) - '0') % B;
        num = (num + (digit*mul)%B) %B;
        mul = (mul* (10%B))%B;
        i++;
    }
    return num;
}

int main()
{
    string A = "842554936302263";
    int B = 41;

    cout<<findMod(A,B);
    return 0;
}