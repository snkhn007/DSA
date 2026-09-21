class Solution {
public:
    int bfs(queue<pair<int, int>>& q,  vector<vector<bool>>& vis, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            for(int k = 0; k<size; k++){
                auto curr = q.front();
                int i = curr.first;
                int j = curr.second;
                q.pop();
                if(i+1 <n  &&  !vis[i+1][j]  && grid[i+1][j] == 1){
                    q.push({i+1, j});
                    grid[i+1][j] = 2;
                    vis[i+1][j] = true;
                }
                if(i-1 >=0  &&  !vis[i-1][j]  && grid[i-1][j] == 1){
                    q.push({i-1, j});
                    grid[i-1][j] = 2;
                    vis[i-1][j] = true;
                }
                if(j+1 <m  &&  !vis[i][j+1]  && grid[i][j+1] == 1){
                    q.push({i, j+1});
                    grid[i][j+1] = 2;
                    vis[i][j+1] = true;
                }
                if(j-1 >=0  &&  !vis[i][j-1]  && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                    vis[i][j-1] = true;
                }
            }
            cnt++;
        }
        return cnt;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue <pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
        int res = 0;
        res = bfs(q, vis, grid);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        if(res == 0) return res;
        return res-1;
    }
};