class Solution {
public:

    void dfs(int node, int& ans,vector<int>& vis, vector<vector<int>>& forwd, vector<vector<int>>& backwd){
        vis[node]=1;
        for(int nbr:forwd[node]){
            if(!vis[nbr]){
            ans++;
            dfs(nbr, ans, vis, forwd, backwd);}
        }

        for(int nbr:backwd[node]){
            dfs(nbr, ans, vis, forwd, backwd);
        }

    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> forwd(n), backwd(n);
        vector<int> vis(n);

        for (int i=0; i<connections.size(); i++){
            int a= connections[i][0];
            int b= connections[i][1];

            forwd[a].push_back(b);
            backwd[b].push_back(a);
        }
        int ans=0;
        dfs(0, ans, vis, forwd, backwd);

        return ans;
        
    }
};