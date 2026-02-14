#include <bits/stdc++.h>
using namespace std;
class WordDictionary {
    struct Node{ array<int,26> nxt; bool end; Node(){ nxt.fill(-1); end=false; } };
    vector<Node> tr;
    bool dfs(int u, const string& w, int i){ if(i==(int)w.size()) return tr[u].end; char c=w[i]; if(c=='.'){ for(int k=0;k<26;k++){ int v=tr[u].nxt[k]; if(v!=-1 && dfs(v,w,i+1)) return true; } return false; } else { int k=c-'a'; int v=tr[u].nxt[k]; return v!=-1 && dfs(v,w,i+1); } }
public:
    WordDictionary(){ tr.emplace_back(); }
    void addWord(string word){ int u=0; for(char c: word){ int k=c-'a'; if(tr[u].nxt[k]==-1){ tr[u].nxt[k]=tr.size(); tr.emplace_back(); } u=tr[u].nxt[k]; } tr[u].end=true; }
    bool search(string word){ return dfs(0, word, 0); }
};
