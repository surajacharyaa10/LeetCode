class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, 
             int& vertices, int& edges) {
        visited[node] = 1;
        vertices++;
        edges += adj[node].size();

        for (int nei : adj[node]) {
            if (!visited[nei]) {
                dfs(nei, adj, visited, vertices, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int vertices = 0;
                int edgesCount = 0;

                dfs(i, adj, visited, vertices, edgesCount);

                edgesCount /= 2;

                if (edgesCount == vertices * (vertices - 1) / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};