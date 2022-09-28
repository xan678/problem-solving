#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int countElements(vector<int> &A, int B){

    int start = 0; 
    int end = A.size()-1;

    int ans = 0;
    while(start <= end){
        int mid = start + (end-start)/2;

        if(A[mid] <= B){
            ans += (mid - start + 1);
            start = mid +1;
        }
        else{
            end = mid -1;
        }
    }

    return ans;
}

int findMedian(vector<vector<int>> &A){

    int maxElement = INT_MIN;
    int minElement = INT_MAX;

    for(int j = 0; j<A.size(); j++){
        minElement = min(A[j][0], minElement);
        maxElement = max(A[j][A[0].size()-1], maxElement);
    }

    //cout<<minElement <<" "<<maxElement;

    int start = minElement;
    int end = maxElement;

    int elementsRequired = (A.size()*A[0].size()/2) + 1;


    //cout<<elementsRequired<<endl;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start)/2;

        int elementsLessThanMid = 0;
        for(auto x : A){
            elementsLessThanMid += countElements(x,mid);
        }
        //cout<<mid <<" "<<elementsLessThanMid<<endl;

        //cout<<elementsLessThanMid<<endl;
        // if(elementsLessThanMid == elementsRequired){
        //     ans = mid;
        //     break;
        // }
        if(elementsLessThanMid< elementsRequired){
            start = mid + 1;
        }else{
            ans = mid;
            end =  mid -1;
        }
    }
    return ans;
}


int main()
{
    vector<vector<int>> A = {
       //{1, 1, 3, 3, 3, 3, 3},
       {7, 8 ,9},
       {3, 4 ,5},
       {6, 11 , 13},
       {4 ,7 ,9} 
    };

    cout<<findMedian(A)<<endl;
    return 0;
}