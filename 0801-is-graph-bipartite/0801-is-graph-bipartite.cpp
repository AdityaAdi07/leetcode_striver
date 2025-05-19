class Solution {
private:
    bool dfs(int v, int co, int color[], vector<vector<int>>& graph) {
        color[v] = co;
        for (auto it : graph[v]) {
            if (color[it] == -1) {
                if (!dfs(it, !co, color, graph)) return false; 
            } else if (color[it] == co) {
                return false; 
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        for (int i = 0; i < n; i++) color[i] = -1;

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, graph)) return false;
            }
        }
        return true;
    }
};
