#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        vector<char> st; unordered_map<char,char> m={{')','('},{']','['},{'}','{'}};
        for(char c: s){
            if(c=='('||c=='['||c=='{') st.push_back(c);
            else {
                if(st.empty() || st.back()!=m[c]) return false;
                st.pop_back();
            }
        }
        return st.empty();
    }
};
