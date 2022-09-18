#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> sortColors(vector<int> &A){
    int redFreq = 0;
    int whiteFreq = 0;
    int blueFreq = 0;

    for(int i = 0;i< A.size(); i++){
        if(A[i] == 0){
            redFreq++;
        }
        if(A[i] == 1){
            whiteFreq++;
        }
        if(A[i] == 2){
            blueFreq++;
        }
    }
    vector<int> result;
    while(redFreq--){
        result.push_back(0);
    }

    while(whiteFreq--){
        result.push_back(1);
    }

    while(blueFreq--){
        result.push_back(2);
    }
    return result;    
}

int main()
{
    vector<int> A = {0,1 ,2 ,0 ,1 ,2};
    vector<int> result = sortColors(A);

    for(auto x : result){
        cout<< x<<" ";
    }
    return 0;
}