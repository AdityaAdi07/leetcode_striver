class Solution {
public:
    bool dfs(int node, int destination, vector<bool>& visited, unordered_map<int, vector<int>>& adj) {
        if (node == destination) return true;

        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, destination, visited, adj)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;

        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  
        }

        vector<bool> visited(n, false);

        return dfs(source, destination, visited, adj);
    }
};
