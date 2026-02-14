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
            auto [l1,r1]=expand(s,i,i);
            if(r1-l1>bestR-bestL){bestL=l1;bestR=r1;}
            auto [l2,r2]=expand(s,i,i+1);
            if(r2-l2>bestR-bestL){bestL=l2;bestR=r2;}
        }
        return s.substr(bestL, bestR-bestL+1);
    }
};
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        
        int start = 0, maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd length (center is s[i])
            int len1 = expand(s, i, i);
            // Case 2: Even length (center is between s[i] and s[i+1])
            int len2 = expand(s, i, i + 1);
            
            int currMax = max(len1, len2);
            
            if (currMax > maxLen) {
                maxLen = currMax;
                // Calculate the starting index of the palindrome
                start = i - (currMax - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }

private:
    int expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Length is right - left - 1 because the loop stops 
        // after the pointers have moved one step too far.
        return right - left - 1;
    }
};