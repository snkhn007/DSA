class Solution {
public:
    bool dfs(int node, vector<bool>& vis, vector<int>& path, vector<vector<int>>& adj){
        vis[node] = true;
        path[node] = 1;

        for(auto i: adj[node]){
            if(!vis[i]){
                if(dfs(i, vis, path, adj)) return true; //cycle exists
            }
            else if(path[i] == 1) return true; //cycle exists
        }

        path[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto i: prerequisites){
            // adj[i[0]].push_back(i[1]); //bi first if you want to take course ai ie bi is dependent of ai
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(numCourses, false);
        vector<int>path(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i, vis, path, adj)) return false;
            }
        }
        return true; // no cycle 
    }
};