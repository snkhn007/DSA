class Solution {
public:
    bool bfs(vector<vector<int>>& adj, vector<int>&vis, int node){
        queue<int> q;
        q.push(node);
        vis[node] = true;

        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            for(auto i: adj[currNode]){
                if(vis[i] == -1){
                    // ie no color assigned
                    if(vis[currNode] == 1) vis[i] = 0;
                    else vis[i] = 1;
                    q.push(i);
                }else if(vis[i] == vis[currNode]){
                    // ie it already has a color similar to color of parent 
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto i: dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        // vector<bool> vis(n, false);
        vector<int> vis(n+1, -1);

        for(int i=1; i<=n; i++){
            if(vis[i] == -1){
                bool res =  bfs(adj, vis, i);
                if(!res) return false;
            }
        }

        return true;
    }
};