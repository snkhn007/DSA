class Solution {
public:
    bool bfs(vector<vector<int>>& graph, vector<int> & vis, int node){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int currNode = q.front();
            q.pop();

            for(auto i : graph[currNode]){
                if(vis[i] == -1){
                    q.push(i);
                    // marking the correct color
                    if(vis[currNode] == 1) vis[i] = 0;
                    else vis[i] = 1;
                }else if(vis[i] != -1 && vis[i] == vis[currNode]) return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i=0; i<n; i++){
            if(vis[i] == -1) {
                bool res = bfs(graph, vis, i);
                if(!res) return false;
            }
        }
        return true;
    }
};