#include <bits/stdc++.h>
using namespace std;
class Solution { public: bool canAttendMeetings(vector<vector<int>>& intervals){ sort(intervals.begin(), intervals.end()); for(size_t i=1;i<intervals.size();++i) if(intervals[i][0] < intervals[i-1][1]) return false; return true; } };
