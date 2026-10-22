class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int> & vis, int node, stack<int>& st){
        vis[node] = 1;
        for(auto i : adj[node]){
            if(vis[i] == 0) if(!dfs(adj, vis, i, st)) return false;
            if(vis[i] == 1) return false;
        }
        vis[node] = 2;
        st.push(node);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto i: prerequisites){
            // adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(numCourses, 0);
        stack<int> st;
        for(int i=0; i<numCourses; i++){
            if(!vis[i])  if(!dfs(adj, vis, i, st)) return false;
        }
        return true;
    }
};