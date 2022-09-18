#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

bool compareStrings(string A, string B, unordered_map<char, int> map){
    int i = 0; 
    int j = 0;
    while(i< A.size() && j < B.size()){

        if(map[A[i]] == map[B[j]]){
            i++;
            j++;
        }else if( map[A[i]] > map[B[j]]){
            return true;
        }else if(map[A[i]] < map[B[j]]){
            return false;
        }
    }
    if(A.size() > B.size()){
        return true;
    }

    return false;
}

int solve(vector<string> &A, string B){
    unordered_map<char, int> map;
    int i = 0;
    for(char ch: B){
        map.insert(make_pair(ch,i));
        i++;
    }

    // for(auto x : map){
    //     cout<<x.first<<" "<<x.second<<" ";
    // }
    // cout<<endl;

    for(int i = 1; i<A.size();i++){
        if(!compareStrings(A[i], A[i-1], map)){
            return 0;
        }
    }

    return 1;
}

int main()
{
    vector<string> A = {"zkv", "zbc", "qpmxuj", "loovaowuxwhmsncbxcoks", "ejuvpvaboygp", "txdknlyjyhfixjswnkkufnux", "qghumeaylnlfdxfirc", "scxggbwkfnqduxwfn", "ggxrpnrvystmwcysyycqpev", "ozvsrtkjpre", "o", "cxfxtlsgypsfadpooef", "keffmznimkkasvwsrenzk", "etlyhnkoaugzqrcddiutei", "eylfpbnpljvrvipyamyehwqnq", "jwayyzpvscmpsajlfvgubfa", "zrzbmnmgqoo" };
    string B = "viwcblqmjdxhuyfkonrpzagste";

    vector<string> C = {"ipial", "qjqgt", "vfnue", "vjqfp", "eghva", "ufaeo", "atyqz", "chmxy", "ccvgv", "ghtow" };
    string D = "nbpfhmirzqxsjwdoveuacykltg";
    cout<<solve(C,D);
    return 0;
}