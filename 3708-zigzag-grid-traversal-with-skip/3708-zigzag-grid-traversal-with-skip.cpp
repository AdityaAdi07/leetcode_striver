class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> result;
        bool ok = true;
        for (int i = 0; i < grid.size(); ++i) {
            if (i % 2 == 1) {
                reverse(grid[i].begin(), grid[i].end());
            }
            for (int val : grid[i]) {
                if (ok) {
                    result.push_back(val);
                }
                ok = !ok;
            }
        }
        return result;
    }
};
