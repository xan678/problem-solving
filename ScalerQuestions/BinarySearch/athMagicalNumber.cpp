#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

long gcd(long a, long b)
{
    long result = min(a, b); // Find Minimum of a nd b
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
    return result; // return gcd of a nd b
}

int magicalCount(long mid, int A, int B, long gcdNum){
    long lcm = ((long)A * (long)B)/gcdNum;

    return (int)(mid/A + mid/B - mid/lcm);
}

int solve(int A, int B, int C){
    int mod = 1000*1000*1000 + 9;

    long start = min(B,C);
    long end = A * start;

    long gcdNum = gcd(B,C);
    int ans = -1;
    while(start <= end){
        long mid = (start + end)/2;
        int count = magicalCount(mid, B,C,gcdNum);
        if(count<A){
            start = mid+1;
        }
        if(count> A){
            end = mid -1;
        }   

        if(count == A){
            ans = mid % mod;
            end = mid -1;
        }
        
    }
    return ans;
}

int main()
{
    cout<<solve(4,2,3)<<endl;
    return 0;
}