#include<iostream>
#include <vector>
#include <string>
using namespace std;

int findAthFibonacci(int A){
    if(A == 0){
        return 0;
    }
    if(A <=2 and A>0){
        return 1;
    } 

 return findAthFibonacci(A-1) + findAthFibonacci(A-2);
}

string reverse(string A){
    
    
}

int main(){
    
    return 0;
}