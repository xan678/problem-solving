#include<iostream>
#include<string>
#include<vector>

using namespace std;
struct Interval{
    int start;
    int end;

    Interval(){
        start = 0;
        end = 0;
    };

    Interval(int s, int e){
        start = s;
        end = e;
    };
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval){
    vector<Interval> result;

    int i = 0;

    while(i<intervals.size()){
        if(intervals[i].end < newInterval.start ){
            result.push_back(intervals[i]);
            i++;
        }

        else if(intervals[i].start > newInterval.end){
            result.push_back(newInterval);
            while(i<intervals.size()){
                result.push_back(intervals[i]);
                i++;
            }

            return result;
        }
        else{
            int start = min(intervals[i].start, newInterval.start);
            int end = max(intervals[i].end, newInterval.end);

            newInterval = Interval(start, end);
            i++;
        }
    }
    
    result.push_back(newInterval);
    return result;
}

int main()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(4,7));
    intervals.push_back(Interval(10,14));
    intervals.push_back(Interval(16,19));
    intervals.push_back(Interval(21,24));
    intervals.push_back(Interval(27,30));
    intervals.push_back(Interval(32,35));
    //intervals.push_back(Interval(6,9));

    intervals = insert(intervals, Interval(12,22));

    for(auto x : intervals){
        cout<<x.start << " "<<x.end<<endl;
    }
    return 0;
}