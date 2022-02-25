#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> p;

class Compare{
    public:
        bool operator()(int a, int b){
            return a>b;
        }
};

//Relative Ranks
vector<string> findRelativeRanks(vector<int>& score){
    //priority_queue<pair<int,int>,vector<pair<int, int>, compare2>> heap;
    priority_queue<pair<int,int>> heap;
    for(int i = 0; i <score.size();i++){
        heap.push(make_pair(score[i],i));
    }

    vector<string> v(score.size(),"");
    int i = 1;
    while(!heap.empty()){
        if(i == 1){
            v[heap.top().second] = "Gold Medal";
        }
        else if(i == 2){
            v[heap.top().second] = "Silver Medal";
        }
        else if(i == 3){
            v[heap.top().second] = "Bronze Medal";
        }else{
            v[heap.top().second] = to_string(i);
        }

        heap.pop();
        i++;
    }

    return v;
}

//Maximum value

int maxProduct(vector<int>& nums){
    priority_queue<int> heap;

    for(auto x : nums){
        heap.push(x);
    }

    int one = heap.top();
    heap.pop();
    int second = heap.top();
    heap.pop();

    return (one - 1)*(second -1);
}

//Merging Ropers

int minCost(vector<int>& ans){
    priority_queue<int, vector<int>, greater<int>> heap;

    for(auto x : ans){
        heap.push(x);
    }

    int min = 0;
    while(heap.size() > 1){
        int one = heap.top();
        heap.pop();
        int two = heap.top();
        heap.pop();
        int newRope = one + two;
        min = min + newRope;
        heap.push(newRope);
        
    }

    return min;
}

//Weekest Rows

class Compare{
    public:
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.first>b.second;
        }
};

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

    priority_queue<p, vector<p>, greater<p>> heap;

    for(int i = 0;i<mat.size();i++){
        int count = 0;
        for(auto x: mat[i]){
            if(x == 1){
                count++;
            }
        }
        heap.push(make_pair(count,i));
    }

    vector<int> result;
    while(k--){
        result.push_back(heap.top().second);
        heap.pop();
    }
}

int main(int argc, char const *argv[])
{   
    // int arr[] = {10,15,20,13,6,90};
    // int n = sizeof(arr)/sizeof(int);

    // //Minimum heap with internal comparator
    // priority_queue<int,vector<int>, greater<int>> minHeap;
    
    // //Maximum Heap. This comes with default;
    // priority_queue<int> maxHeap;

    // //Heap with custom Comparator class.
    // priority_queue<int,vector<int>, Compare> customHeap;

    // //pushing stuff in heap
    // for(int x: arr){
    //     maxHeap.push(x);
    // }

    // //displaying stuff in heap
    // while(!maxHeap.empty()){
    //     cout<<maxHeap.top()<<" ";
    //     maxHeap.pop();
    // }

    vector<int> score = {4,3,2,6};

    // vector<string> ranks = findRelativeRanks(score);
    // for(auto x : ranks){
    //     cout<<x<<" ";
    // }

    cout<<minCost(score)<<endl;
    return 0;
}
