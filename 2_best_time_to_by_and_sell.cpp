#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        
       
        int min_price = INT_MAX; 
        
       

        for (int price : prices) {
            
            min_price = min(min_price, price);
            
          
            int current_profit = price - min_price;
            
            max_profit = max(max_profit, current_profit);
        }
        
        return max_profit;
    }
};