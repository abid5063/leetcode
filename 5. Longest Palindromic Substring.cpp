// Problem (short):
// Given a string, return its longest palindromic substring.

#include <bits/stdc++.h>
using namespace std;
class Solution {
    pair<int,int> expand(const string& s, int l, int r){
        while (l >= 0 && r < (int)s.size() && s[l] == s[r]){ l--; r++; }
        return {l+1, r-1};
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int bestL=0, bestR=0;
        for(int i=0;i<n;i++){
            pair<int,int> p1=expand(s,i,i);
            int l1 = p1.first, r1 = p1.second;
            if(r1-l1>bestR-bestL){bestL=l1;bestR=r1;}
            pair<int,int> p2=expand(s,i,i+1);
            int l2 = p2.first, r2 = p2.second;
            if(r2-l2>bestR-bestL){bestL=l2;bestR=r2;}
        }
        return s.substr(bestL, bestR-bestL+1);
    }
};
