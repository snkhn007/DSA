class Solution {
public:
    void bfs(int i, int j, vector<vector<int>> &res, vector<vector<int>>& mat, int dist){
        int n = mat.size();
        int m = mat[0].size();        
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> res(n , vector<int> (m, 0));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue <pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    res[i][j] = 0;
                    vis[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            for(int k =0; k<size; k++){
                auto curr = q.front();
                q.pop();
                int i = curr.first.first;
                int j = curr.first.second;
                int dist = curr.second;
                if(i+1 < n && !vis[i+1][j] && mat[i+1][j]==1){
                    res[i+1][j] = dist+1;
                    q.push({{i+1, j}, dist+1});
                    vis[i+1][j] = true;
                }
                if(i-1>=0 && !vis[i-1][j] && mat[i-1][j]==1){
                    res[i-1][j] = dist+1;
                    q.push({{i-1, j}, dist+1});
                    vis[i-1][j] = true;
                }
                if(j+1 < m && !vis[i][j+1] && mat[i][j+1]==1){
                    res[i][j+1] = dist+1;
                    q.push({{i, j+1}, dist+1});
                    vis[i][j+1] = true;
                }
                if(j-1>=0 && !vis[i][j-1] && mat[i][j-1]==1){
                    res[i][j-1] = dist+1;
                    q.push({{i, j-1}, dist+1});
                    vis[i][j-1] = true;
                }
            }
        }
        return res;
    }
};