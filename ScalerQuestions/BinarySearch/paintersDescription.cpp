#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

bool checkFunc(int A, int B, vector<int> &C, long long int mid){
    long long int sum = 0;
    long long int worker = 1;
    int i = 0;

    while (i<C.size())
    {   
        if(worker > A){
            break;
        }
        sum += (long long int)B * C[i];
        if(sum <= mid){
            i++;
        }else{
            sum = (long long int)B * C[i];
            worker++;
            i++;
        }
    }
    
    if(i == C.size() && worker <= A){
        return true;
    }

    return false;
}

int paint(int A, int B , vector<int> &C){
    int mod = 10000003;

    int maxElement = INT_MIN;
    long long int sum = 0;
    for(auto x : C){
        sum += x;
        maxElement = max(maxElement, x);
    }

    long long int start = maxElement * B;
    long long int end = sum * B;

    long long int ans = -1;
    while(start<= end){
        long long int mid = start + (end -start)/2;

        bool flag = checkFunc(A, B, C, mid);
        cout<<start<<" "<<end<<endl;
        if(flag){
            ans = mid;
            end = mid-1;
        }else{
            start = mid + 1;
        }   
    }

    return (int)(ans%mod);
}

int main()
{
    // int A = 3;
    // int B = 10;
    // vector<int> C = {185, 186, 938, 558, 655, 461, 441, 234, 902, 681 };

    int A = 1;
    int B = 1000000;
    vector<int> C = {1000000, 1000000 };

    cout<<paint(A,B,C);   
    return 0;
}