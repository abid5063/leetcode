#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){ unordered_map<string, vector<string>> mp; for(auto &s: strs){ string k=s; sort(k.begin(),k.end()); mp[k].push_back(s);} vector<vector<string>> res; for(auto &p: mp) res.push_back(move(p.second)); return res; }
};
