#include <bits/stdc++.h>
using namespace std;
class Solution { public: vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& newI){ vector<vector<int>> res; size_t i=0; while(i<a.size() && a[i][1] < newI[0]) res.push_back(a[i++]); while(i<a.size() && a[i][0] <= newI[1]){ newI[0]=min(newI[0], a[i][0]); newI[1]=max(newI[1], a[i][1]); i++; } res.push_back(newI); while(i<a.size()) res.push_back(a[i++]); return res; } };
