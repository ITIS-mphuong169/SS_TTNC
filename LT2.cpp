#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int findConnectedComponents(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n + 1, false);
    int components = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            components++;
        }
    }
    return components;
}

int main() {
    int n, m, P;
    cin >> n >> m >> P;

    vector<vector<int>> adj(n + 1);
    set<pair<int, int>> existingEdges;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (a > b) swap(a, b);
        existingEdges.insert({a, b});
    }

    int components = findConnectedComponents(n, adj);
    int edgesNeeded = components - 1;

    // T?ng s? c?p có th? ch?n
    long long totalPairs = (long long)n * (n - 1) / 2;

    // T?ng s? c?p hi?n t?i
    long long existingPairs = existingEdges.size();

    // S? c?p có th? ch?n d? thêm vào
    long long newPairs = totalPairs - existingPairs;

    // Cách ch?n b? c?p
    long long result = 1;
    for (int i = 0; i < edgesNeeded; ++i) {
        result = (result * newPairs) % P;
        newPairs--;
    }

    cout << result << endl;
    return 0;
}

