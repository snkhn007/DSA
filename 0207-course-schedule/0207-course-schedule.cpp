class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool> & vis, vector<int>&path, int node, int parent){
        vis[node] = true;
        path[node] = 1;
        for(auto i : adj[node]){
            if(!vis[i]){
                bool res = dfs(adj, vis, path, i, node);
                if(res) return true;//cycle exixts
            }
            else if(path[i] == 1) return true;
            // else if(vis[i] && i != parent && path[i] == 1) return true;
        }
        path[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto i: prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        vector<bool> vis(numCourses, false);
        vector<int> path(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                bool res = dfs(adj, vis, path, i, -1);
                if(res) return false;// cycle exists ie it is not possible 
            }
        }
        return true;
    }
};