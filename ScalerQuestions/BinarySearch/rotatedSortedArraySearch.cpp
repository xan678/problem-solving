#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int search(const vector<int> &A, int B){
    int start = 0;
    int end = A.size()-1;

    int ans;
    while (start <= end)
    {   
        int mid = (start + end)/2;
        if(A[mid] < A[mid + 1] && A[mid] < A[mid -1]){
            ans = mid;
        }
        if(A[mid] > A[A.size()-1]){
            start = mid +1;
        }else{
            end = mid-1;
        }
    }

    if(B > A[A.size()-1]){
        start = 0;
        end = ans -1;

    }else{
        start = ans;
        end = A.size()-1;
    }

    while(start <= end){
            int mid = (start + end)/2;

            if(A[mid] == B){
                return mid;
                break;
            }
            if(A[mid] > B){
                end = mid -1;
            }else{
                start = mid +1;
            }
        }
    return -1;
}

int main()
{
    vector<int> A = {19, 20, 21, 22, 28, 29, 32, 36, 39, 40, 41, 42, 43, 45, 48, 49, 51, 54, 55, 56, 58, 60, 61, 62, 65, 67, 69, 71, 72, 74, 75, 78, 81, 84, 85, 87, 89, 92, 94, 95, 96, 97, 98, 99, 100, 105, 107, 108, 109, 110, 112, 113, 115, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 128, 130, 131, 133, 134, 135, 136, 137, 138, 139, 141, 142, 144, 146, 147, 148, 149, 150, 153, 155, 157, 159, 161, 163, 164, 169, 170, 175, 176, 179, 180, 185, 187, 188, 189, 192, 196, 199, 201, 203, 205, 3, 7, 9, 10, 12, 13, 17  };
    int B = 6;

    cout<<search(A,B)<<endl;
    return 0;
}