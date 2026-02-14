#include <bits/stdc++.h>
using namespace std;
class Trie {
    struct Node{ array<int,26> nxt; bool end; Node(){ nxt.fill(-1); end=false; } };
    vector<Node> tr;
public:
    Trie(){ tr.emplace_back(); }
    void insert(string word){ int u=0; for(char c: word){ int i=c-'a'; if(tr[u].nxt[i]==-1){ tr[u].nxt[i]=tr.size(); tr.emplace_back(); } u=tr[u].nxt[i]; } tr[u].end=true; }
    bool search(string word){ int u=0; for(char c: word){ int i=c-'a'; if(tr[u].nxt[i]==-1) return false; u=tr[u].nxt[i]; } return tr[u].end; }
    bool startsWith(string prefix){ int u=0; for(char c: prefix){ int i=c-'a'; if(tr[u].nxt[i]==-1) return false; u=tr[u].nxt[i]; } return true; }
};
