#include<iostream>
#include <vector>
#include <string>
using namespace std;

string solve(vector<int> &A){
    if(A[0] % 2 == 0 and A[A.size()-1] % 2 == 0){
        int even;
        auto x = A.end()-2;
        bool flag = false;
        while(x> A.begin()){
            if(*x%2 == 0 and (x - A.begin())%2 == 0 and (A.end() -x )%2 == 0) return "YES";

            x--;
        }
        if(A.size() %2 == 0) return "YES";
        return "NO";
    }else{
        return "NO";
    }
}

int main(){
    vector<int> A = {2, 4, 8, 7, 6};
    cout<<solve(A)<<endl;
    return 0;
}