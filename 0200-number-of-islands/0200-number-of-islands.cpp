class Solution {
public:
    bool isValid(vector<vector<bool>>& vis, int i, int j, int n, int m, vector<vector<char>>&grid){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        if(vis[i][j]) return false;
        if(grid[i][j] == '0') return false;
        return true;
    }
    void bfs(vector<vector<char>>&grid, int n, int m, int i, int j, vector<vector<bool>>& vis){
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;

        while(!q.empty()){
            auto[i, j] = q.front();
            q.pop();

            for(int k=0; k<4; k++){
                int indx = i+ dx[k];
                int indy = j+dy[k];

                if(isValid(vis, indx, indy, n, m, grid)){
                    q.push({indx, indy});
                    vis[indx][indy] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector<vector<bool>> vis(n, vector<bool> (m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]  && grid[i][j] == '1'){
                    bfs(grid, n, m, i, j, vis);
                    res++;
                }
            }
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return res;
    }
};