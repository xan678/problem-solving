#include<iostream>
#include<string>
#include<vector>

using namespace std;

void factors(int A){
    for(int i =1; i*i <= A; i++){
        if(A%i == 0){
            if(A/i == i){
                cout<<i<<endl;
            }
            else{
                cout<<i<<endl;
                cout<<A/i<<endl;
            }
        }
    }
}

int solve(int A, int B){
    int neg = abs(A-B);
    int ans = -1;
    for(int i = 1; i*i<= neg; i++ ){
        if(neg % i == 0){
            if(neg/i == i){
                ans = max(ans, i);
            }
            else{
                ans = max(max(ans, i), neg/i);
            }
        }
    }

    return ans;
}

int main()
{
    int A = 5;
    int B = 10;   
    cout<<solve(A,B);
    //factors(6);
    return 0;
}