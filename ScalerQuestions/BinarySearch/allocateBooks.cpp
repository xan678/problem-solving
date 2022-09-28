#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

bool checkFunction(vector<int> A, int mid, int B){

    int i = 0;
    int count = 1;
    int sum = 0;

    while (i<A.size())
    {   
        sum += A[i];
        //cout<<sum<<" "<<count<<" "<<i<<endl;
        if(count> B){
            return false;
        }

        if(sum > mid){
            count++;
            sum = A[i];
        }
        i++;
    }
    
    //cout<<count<<" "<<i<<endl;
    if(count <= B && i == A.size()){
        return true;
    }

    return false;
}

int books(vector<int> &A, int B){
    int minElement = INT_MIN;
    long sum = 0;

    for(auto x : A){
        minElement = max(minElement, x);
        sum += x;
    }

    int start = minElement;
    int end = sum;

    int ans = 0;
    while (start <= end)
    {   
        int mid = start + (end - start)/2;
        cout<<start <<" "<<end<<" "<<mid<<endl;

        bool flag = checkFunction(A,mid,B);

        if(flag){
            end = mid-1;
            ans = mid;
        }else{
            start = mid +1;
        }
    }
    return ans;
}

int main()
{
    vector<int> A = {73, 58, 30, 72, 44, 78, 23, 9};
    int B = 5;
    int mid = 146;

    //cout<<checkFunction(A,mid,B)<<endl;
    cout<<books(A,B)<<endl;
    return 0;
}