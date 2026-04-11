// Problem (short):
// Given an integer, return how many bits are set to 1.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hammingWeight(int n) {
        int count =0; 
        while(n){
            if (n&1)count++;
            n=n>>1;
        }
        return count;
        
    }
};