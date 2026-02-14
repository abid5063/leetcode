#include <bits/stdc++.h>
using namespace std;
class Solution { public: vector<int> topKFrequent(vector<int>& nums, int k){ unordered_map<int,int> cnt; for(int x: nums) cnt[x]++; vector<vector<int>> buckets(nums.size()+1); for(auto &p: cnt) buckets[p.second].push_back(p.first); vector<int> res; for(int f=buckets.size()-1; f>=0 && (int)res.size()<k; --f) for(int x: buckets[f]){ res.push_back(x); if((int)res.size()==k) break; } return res; } };
