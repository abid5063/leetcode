#include <bits/stdc++.h>
using namespace std;
class Solution { public: int maxProfit(vector<int>& prices){ int mn=INT_MAX, best=0; for(int p: prices){ mn=min(mn,p); best=max(best, p-mn); } return best; } };
