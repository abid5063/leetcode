// Problem (short):
// Given stock prices by day, find the maximum profit from one buy and one sell.

#include <bits/stdc++.h>
using namespace std;
class Solution { 
    public: 
    int maxProfit(vector<int>& prices){ 
        int best =0; 
        int mn= prices[0];
        int n=prices.size();
        for(int i=0; i< n; i++){
            best= max(best, prices[i]-mn);
            mn=min(mn, prices[i]);
        }

        return best;
    } 
};
