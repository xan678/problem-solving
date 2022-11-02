#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;


//Incorrect solution 11/15 test cases passing
int minMutation(string start, string end, vector<string>& bank){
    unordered_set<string> set;
    for(auto x : bank) set.insert(x);

    if(set.find(end) == set.end()) return -1;


    int count = 0;
    for(int i = 0; i<start.size(); i++){
        if(start[i] != end[i]) count++;
    }
    return count;
}

int minMutationBFS(string start, string end, vector<string>& bank){

    unordered_set<string> set(bank.begin(), bank.end());
    if(!set.count(end)) return -1;

    queue<string> q; 
    q.push(start);
    int step = 0, s;
    string cur, t;

    while(!q.empty()){
        s = q.size();

        while(s--){
            cur = q.front();
            q.pop();

            if(cur == end) return step;
            set.erase(cur);

            for(int i = 0; i<8; i++){
                t= cur;
                t[i] = 'A';
                if(set.count(t)) q.push(t);
                t[i] = 'C';
                if(set.count(t)) q.push(t);
                t[i] = 'G';
                if(set.count(t)) q.push(t);
                t[i] = 'T';
                if(set.count(t)) q.push(t);
            }
        }
        step++;
    }
    return -1;
}

int main()
{
    string start = "AAAAACCC";
    string end = "AACCCCCC";

    vector<string> bank = {"AAAACCCC","AAACCCCC","AACCCCCC"};

    cout<<minMutationBFS(start, end, bank);

    return 0;
}