// Problem (short):
// Given coin values and an amount, return how many combinations can make that amount.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount+1,0); dp[0]=1;
        for(int c: coins){
            for(int x=c; x<=amount; ++x) dp[x]+=dp[x-c];
        }
        return static_cast<int>(dp[amount]);
    }
};
