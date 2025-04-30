class Solution {
public:
    void bfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int j = 0; j < isConnected.size(); ++j) {
                if (isConnected[curr][j] == 1 && !visited[j]) {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                bfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }
};
