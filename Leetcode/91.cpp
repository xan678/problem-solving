#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

static unordered_set<string> map;

int numDecodings(string s) {

    if(s.size() == 0){
        return 0;
    }

    if(s.size() == 1 ){
        if(map.find(s) != map.end()){
            return 1;
        }else{
            return 0;
        }
    }

    if(s.size() == 2){
        if(map.find(s) != map.end()){
            if(map.find(s.substr(0,1)) != map.end() && map.find(s.substr(1,s.size())) != map.end()) return 2;
            return 1;
        }
    }
    int res = 0;
    string s1 = s.substr(0,1);
    string s2 = s.substr(0,2);
    cout<<s1<<" "<<s2<<endl;
    if(map.find(s1) != map.end()) res += numDecodings(s.substr(1,s.size()));;
    
    if(map.find(s2) != map.end()) res += numDecodings(s.substr(2,s.size()));
    return res;
}

int main()
{
    map.insert("1");
    map.insert("2");
    map.insert("3");
    map.insert("4");
    map.insert("5");
    map.insert("6");
    map.insert("7");
    map.insert("8");
    map.insert("9");
    map.insert("10");
    map.insert("11");
    map.insert("12");
    map.insert("13");
    map.insert("14");
    map.insert("15");
    map.insert("16");
    map.insert("17");
    map.insert("18");
    map.insert("19");
    map.insert("20");
    map.insert("21");
    map.insert("22");
    map.insert("23");
    map.insert("24");
    map.insert("25");
    map.insert("26");

    string s = "27";
    cout<<numDecodings(s)<<endl;
    return 0;
}