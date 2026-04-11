// Problem (short):
// Return the sum of two integers without using plus or minus operators.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b)
        {
            unsigned carry = (unsigned)(a & b) << 1;
            a ^= b;
            b = (int)carry;
        }
        return a;
    }
};
