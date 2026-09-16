class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;

        int size = edges.size();
        vector<vector<int>> adj(n);
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        // for(int i = 0; i < adj.size(); i++){
        //     cout << i << " -> ";

        //     for(int j = 0; j < adj[i].size(); j++){
        //         cout << adj[i][j] << " ";
        //     }

        //     cout << endl;
        // }
        queue <int> q;
        vector<bool> vis(n, false);
        q.push(source);
        vis[source] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto i:adj[curr]){
                if( i == destination) return true;
                if(!vis[i]){
                    q.push(i);
                    vis[i] = true;
                }
            }
        }

        return false;
    }
};