#include <bits/stdc++.h>
using namespace std;
class MedianFinder {
    priority_queue<int> lo; // max-heap
    priority_queue<int, vector<int>, greater<int>> hi; // min-heap
public:
    void addNum(int num){
        if(lo.empty() || num<=lo.top()) lo.push(num); else hi.push(num);
        if(lo.size() > hi.size()+1){ hi.push(lo.top()); lo.pop(); }
        else if(hi.size() > lo.size()){ lo.push(hi.top()); hi.pop(); }
    }
    double findMedian(){
        if(lo.size()==hi.size()) return (lo.top()+hi.top())/2.0; else return lo.top();
    }
};
