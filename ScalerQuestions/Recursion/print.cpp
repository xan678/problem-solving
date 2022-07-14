#include<iostream>
#include <vector>
#include <string>
using namespace std;

void recursion(int n){
    if (n == 0) return ;
    recursion(n-1);
    cout<<n<<" ";
}

int main(){
    
    return 0;
}