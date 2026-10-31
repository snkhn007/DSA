class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        if(vis[i][j] || grid[i][j] == 1) return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        
        int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
        int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

        vector<vector<bool>> vis(n, vector<bool>(m , false));
        queue <pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        // q.push({{0, 0}, 0});
        vis[0][0] = true;

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;

            if( i == n-1 && j == m-1) return dist;
            q.pop();

            for(int k=0; k<8; k++){
                int indx = i+dx[k], indy= j+dy[k];
                if(isValid(indx, indy, n, m, grid, vis)){
                    q.push({{indx, indy}, dist+1});
                    vis[indx][indy] = true;
                }
            }
        }

        return -1;

    }
};