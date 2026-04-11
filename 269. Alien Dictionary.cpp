// Problem (short):
// Given sorted words in an alien language, return a valid character order.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;

        for (const string& word : words) {
            for (char c : word) indegree[c] = 0;
        }

        for (int i = 0; i + 1 < (int)words.size(); i++) {
            string& a = words[i];
            string& b = words[i + 1];
            int len = min(a.size(), b.size());
            int j = 0;

            while (j < len && a[j] == b[j]) j++;

            if (j == len) {
                if (a.size() > b.size()) return "";
                continue;
            }

            char u = a[j], v = b[j];
            if (!graph[u].count(v)) {
                graph[u].insert(v);
                indegree[v]++;
            }
        }

        queue<char> q;
        for (auto& p : indegree) {
            if (p.second == 0) q.push(p.first);
        }

        string order;
        while (!q.empty()) {
            char u = q.front();
            q.pop();
            order.push_back(u);

            for (char v : graph[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        if ((int)order.size() != (int)indegree.size()) return "";
        return order;
    }
};
