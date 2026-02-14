#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val; vector<Node*> neighbors;
    Node(): val(0), neighbors() {}
    Node(int _val): val(_val), neighbors() {}
    Node(int _val, vector<Node*> _neighbors): val(_val), neighbors(_neighbors) {}
};
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q; q.push(node); mp[node]=new Node(node->val);
        while(!q.empty()){
            Node* cur=q.front(); q.pop();
            for(Node* nb: cur->neighbors){
                if(!mp.count(nb)){ mp[nb]=new Node(nb->val); q.push(nb); }
                mp[cur]->neighbors.push_back(mp[nb]);
            }
        }
        return mp[node];
    }
};
#include <unordered_map>
#include <vector>
#include <queue>

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Map to store: [Original Node Pointer] -> [Cloned Node Pointer]
        unordered_map<Node*, Node*> clones;
        
        // Clone the root and add to map
        clones[node] = new Node(node->val);
        
        // Queue for BFS traversal (stores original nodes)
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // Iterate through all neighbors of the original node
            for (Node* neighbor : curr->neighbors) {
                // If neighbor hasn't been cloned yet
                if (clones.find(neighbor) == clones.end()) {
                    // 1. Create the clone
                    clones[neighbor] = new Node(neighbor->val);
                    // 2. Push original neighbor to queue to process its neighbors later
                    q.push(neighbor);
                }
                
                // Add the cloned neighbor to the current cloned node's neighbor list
                clones[curr]->neighbors.push_back(clones[neighbor]);
            }
        }

        return clones[node];
    }
};