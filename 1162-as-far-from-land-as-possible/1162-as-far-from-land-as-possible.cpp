class Solution {
public:
    bool isValid(int i, int j , vector<vector<bool>>& vis, int n, int m){
        if(i < 0|| j<0 || i>=n || j>=m) return false;
        if(vis[i][j]) return false;
        return true;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = INT_MIN, dist = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] ==1){
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        if(q.empty()) return -1;
        if(q.size() == n*m) return -1;

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            res = max(res, dist);
            q.pop();

            for(int k=0; k<4; k++){
                int indx = i+dx[k], indy = j+dy[k];

                if(isValid(indx, indy, vis, n, m)){
                    q.push({{indx, indy}, dist+1});
                    vis[indx][indy] = true;
                }
            }
        }
        return res;
    }
};