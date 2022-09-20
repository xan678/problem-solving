#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int sqrt(int A){
    long start = 0;
    long end = (long) A;

    long ans = -1;

    while(start <= end){
        long mid = (start + end)/2;

        long lp = mid * mid;

        if(lp == (long) A){
            return mid;
        }
        if(lp > (long)A){
            end = mid-1;
        }
        else{
            start = mid + 1;
            ans = mid;
        }
    }

    return ans;
}

int main()
{
    cout<<sqrt(2147483647)<<endl;
    return 0;
}