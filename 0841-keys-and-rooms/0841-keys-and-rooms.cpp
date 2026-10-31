class Solution {
public:
    void dfs(int node, vector<bool> &vis, vector<vector<int>>& grid){
        vis[node] = true;
        for(auto i : grid[node]){
            if(!vis[i]) dfs(i, vis, grid);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), cnt=0;
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                if(cnt > 1) return false;
                dfs(i, vis, rooms);
            }
        }
        
        return true;        
    }
};