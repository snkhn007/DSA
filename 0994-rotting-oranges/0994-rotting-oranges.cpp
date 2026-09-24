class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int els = q.size(); // elements to process before cnt++;
            for(int k =0; k<els; k++){
                auto curr = q.front();
                q.pop();
                int i = curr.first.first;
                int j = curr.first.second;
                cnt = curr.second;

                if(i+1 < n && !vis[i+1][j] && grid[i+1][j]==1){
                    q.push({{i+1, j}, cnt+1});
                    vis[i+1][j] = true;
                }
                if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]==1){
                    q.push({{i-1, j}, cnt+1});
                    vis[i-1][j] = true;
                }
                if(j+1 < m && !vis[i][j+1] && grid[i][j+1]==1){
                    q.push({{i, j+1}, cnt+1});
                    vis[i][j+1] = true;
                }
                if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]==1){
                    q.push({{i, j-1}, cnt+1});
                    vis[i][j-1] = true;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == false) return -1;
            }
        }
        return cnt;
    }
};