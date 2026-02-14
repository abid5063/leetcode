#include <bits/stdc++.h>
using namespace std;
class Codec {
public:
    string encode(vector<string>& strs) {
        string out; out.reserve(1024);
        for(const auto& s: strs){ out += to_string(s.size()); out += '#'; out += s; }
        return out;
    }
    vector<string> decode(string s) {
        vector<string> res; int i=0, n=s.size();
        while(i<n){ int j=i; while(j<n && s[j] != '#') j++; int len = stoi(s.substr(i, j-i)); j++; res.push_back(s.substr(j, len)); i = j + len; }
        return res;
    }
};
