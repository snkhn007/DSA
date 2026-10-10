class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& vis, int node){
        vis[node] = true;
        for(int i=0; i<isConnected.size(); i++){
            if(isConnected[node][i] &&  !vis[i]){
                // ie edge between node and i exists 
                dfs(isConnected, vis, i);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // vector<vector<bool>> vis(n , vector<bool>(n, false));
        vector<bool> vis(n, false);
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(isConnected, vis, i);
                cnt++;
            }
        }
        return cnt;
    }
};