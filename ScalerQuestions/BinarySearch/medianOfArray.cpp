#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B){
    if(B.size() < A.size()) return findMedianSortedArrays(B,A);

    int n1 = A.size();
    int n2 = B.size();

    int start = 0;
    int end = n1;

    while(start <= end){
        int cut1 = (start + end) >>1;
        int cut2 = (n1 + n2 + 1)/2 - cut1;

        int l1 = cut1 == 0 ? INT_MIN : A[cut1-1];
        int l2 = cut2 == 0 ? INT_MIN : B[cut2-1];

        int r1 = cut1 == n1 ? INT_MAX : A[cut1];
        int r2 = cut2 == n2 ? INT_MAX : B[cut2];

        if(l1 <= r2 && l2 <= r1){
            if((n1 + n2) %2 == 0){
                return (max(l1,l2) + min(r1,r2))/ 2.0;
            }else{
                return max(l1,l2)/1.0;
            }
        }else if(l1 >r2){
            end = cut1-1;
        }else{
            start = cut1 +1;
        }
    }
    return 0.0; 
}

int main()
{
    vector<int> A = {1, 4, 5};
    vector<int> B = {2, 3};

    cout<<findMedianSortedArrays(A,B)<<endl;
    return 0;
}