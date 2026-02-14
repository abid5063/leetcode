#include <bits/stdc++.h>
using namespace std;
class Solution { void gen(int n, int m, vector<string>& res){ if(n==0){ res.push_back(""); return; } if(n==1){ res.push_back("0"); res.push_back("1"); res.push_back("8"); return; } vector<string> prev; gen(n-2, m, prev); for(string s: prev){ for(auto pr: vector<pair<char,char>>{{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}}){ if(n==m && pr.first=='0') continue; res.push_back(string(1,pr.first)+s+string(1,pr.second)); } } } public: vector<string> findStrobogrammatic(int n){ vector<string> res; gen(n,n,res); return res; } };
