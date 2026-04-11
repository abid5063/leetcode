// Problem (short):
// Given a string of brackets, check if every opening bracket is closed in the correct order.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        vector<int> st;
        for (char c : s) {
            if (c == '(') st.push_back(1);
            else if (c == '{') st.push_back(2);
            else if (c == '[') st.push_back(3);
            else {
                if (st.empty()) return false;
                int need = (c == ')') ? 1 : (c == '}') ? 2 : 3;
                if (st.back() != need) return false;
                st.pop_back();
            }
        }
        return st.empty();
    }
};
