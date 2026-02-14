#include <bits/stdc++.h>
using namespace std;
class Solution {
    struct DSU{ vector<int> p, r; DSU(int n):p(n),r(n){ iota(p.begin(),p.end(),0);} int find(int x){ return p[x]==x?x:p[x]=find(p[x]); } bool unite(int a,int b){ a=find(a); b=find(b); if(a==b) return false; if(r[a]<r[b]) swap(a,b); p[b]=a; if(r[a]==r[b]) r[a]++; return true; } };
public:
    int countComponents(int n, vector<vector<int>>& edges){ DSU d(n); int comp=n; for(auto &e: edges){ if(d.unite(e[0], e[1])) comp--; } return comp; }
};
