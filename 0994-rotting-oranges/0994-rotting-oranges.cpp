class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        if(i<0 ||j<0 || i>=n || j>= m) return false;
        // if(vis[i][j]) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        // vector<vector<bool>> vis(n, vector<bool> (m, false));
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    // vis[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            auto[i, j] = q.front().first;
            int lvl = q.front().second;
            res = max(res, lvl);
            q.pop();
            for(int k=0; k<4; k++){
                int indx = i+dx[k];
                int indy = j+dy[k];

                if(isValid(indx, indy, n, m) && grid[indx][indy] == 1){
                    grid[indx][indy] = 2;
                    q.push({{indx, indy}, lvl+1});
                    // vis[indx][indy] = true;
                }
            }

        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return res;
    }
};