// Problem (short):
// Given a node in a connected graph, return a deep copy of the whole graph.

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
        if (!node) return nullptr;

        unordered_map<Node*, Node*> clones;
        clones[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors) {
                if (clones.find(neighbor) == clones.end()) {
                    clones[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                clones[curr]->neighbors.push_back(clones[neighbor]);
            }
        }

        return clones[node];
    }
};