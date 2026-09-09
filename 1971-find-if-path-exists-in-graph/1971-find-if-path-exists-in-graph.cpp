class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // generic bfs but on each node see if it is equal to destination or not
        queue <int> q;
        vector<bool> vis(n, false);

        vector<vector<int>> adj(n);
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }


        q.push(source);
        vis[source] = true;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            if(current == destination) return true;
            cout<<current<<" ";
            for(auto i: adj[current]){
                if(!vis[i]){
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
        return false;
    }
};