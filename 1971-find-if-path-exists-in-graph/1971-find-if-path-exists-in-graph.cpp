class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(source);
        vis[source] = true;

        while(!q.empty()){
            int currentKey = q.front();
            q.pop();
            if(destination == currentKey) return true;

            for(auto i:adj[currentKey]){
                // if(destination == i) return true;
                if(!vis[i]){
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
        return false;
    }
};