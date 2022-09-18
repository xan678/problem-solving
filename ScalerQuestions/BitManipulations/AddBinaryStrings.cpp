#include<iostream>
#include<string>
#include<vector>

using namespace std;

string addBinary(string A, string B){
    if(B == ""){
        return A;
    }
    if(A == ""){
        return B;
    }
    else{
        int i = A.size() - 1;
    int j = B.size() - 1;

    string result = "";
    int carry = 0;
    while(i>=0 && j>=0){
        int a = A[i] - '0';
        int b = B[j] - '0';

        int v = (a + b + carry) % 2;
        carry = (a + b + carry) / 2;
        v = v+'0';
        result.insert(result.begin(), v); 
        i--;
        j--; 
    }
    while(i>=0){
        int a = A[i] - '0';

        int v  = (a+carry) %2;
        carry = (a+carry)/2;
        v= v + '0';
        result.insert(result.begin(), v);
        i--;
    }

    while(j>=0){
        int b = B[j] - '0';
        int v = ( b + carry) % 2;
        carry = ( b + carry) / 2;
        v = v+'0';
        result.insert(result.begin(), v); 
        j--;
    }

    if(carry){
        result.insert(result.begin(), carry + '0');
    }

    return result;
    }
}

int main()
{   
    string A = "110110010000111000100000001011001011011100";
    string B = "";

    string result = addBinary(A,B);
    cout<<result;
    
    return 0;
}