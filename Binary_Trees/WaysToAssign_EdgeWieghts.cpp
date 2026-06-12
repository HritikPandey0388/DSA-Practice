/*
Problem:
Given a tree with n nodes rooted at node 1, find the maximum depth
of the tree. The answer is 2^(maxDepth - 1) modulo 1e9+7.

Approach:
1. Use BFS from node 1 to find the maximum depth.
2. Compute 2^(maxDepth - 1) using binary exponentiation.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int assignEdgeWeights(vector<vector<int>>& edges) {

    int n = edges.size() + 1;

    // adjacency list
    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // bfs queue -> {node, depth}
    queue<pair<int, int>> q;
    q.push({1, 0});

    vector<bool> vis(n + 1, false);
    vis[1] = true;

    int maxDepth = 0;

    while(!q.empty()){

        int node = q.front().first;
        int depth = q.front().second;
        q.pop();

        maxDepth = max(maxDepth, depth);

        for(int neighbour : adj[node]){

            if(!vis[neighbour]){
                vis[neighbour] = true;
                q.push({neighbour, depth + 1});
            }
        }
    }

    // calculate 2^(maxDepth - 1)
    long long MOD = 1e9 + 7;
    long long ans = 1;
    long long base = 2;

    int exp = maxDepth - 1;

    while(exp > 0){

        // multiply current base if bit is set
        if(exp & 1){
            ans = (ans * base) % MOD;
        }

        // square the base
        base = (base * base) % MOD;

        // move to next bit
        exp >>= 1;
    }

    return (int)ans;
}

int main() {

    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4}
    };

    cout << assignEdgeWeights(edges);

    return 0;
}