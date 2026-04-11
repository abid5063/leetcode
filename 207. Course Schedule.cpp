// Problem (short):
// Given courses and prerequisites, check if it is possible to finish all courses.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> g(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto &p : prerequisites)
        {
            g[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (indeg[i] == 0)
                q.push(i);
        int cnt = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cnt++;
            for (int v : g[u])
                if (--indeg[v] == 0)
                    q.push(v);
        }
        return cnt == numCourses;
    }
};